#include <stdio.h> 
#include <stdlib.h>
#include <assert.h> 
#include <malloc.h>
#include <stdbool.h>

typedef int QUDataType;

typedef struct QueueNode
{
	struct QueueNode *_next;
	QUDataType _data;
}QueueNode;

typedef struct Queue
{
	QueueNode *_front;
	QueueNode *_rear;
}Queue;


void QueueInit(Queue *pq)
{
	assert(pq);
	pq -> _front = NULL;
	pq -> _rear = NULL;
}

void QueueDestory(Queue *pq)
{
	assert(pq);
	QueueNode *cur = pq -> _front;
	while(cur)
	{
		QueueNode *next = cur -> _next;
		free(cur);
		cur = next;
	} 
	pq -> _front = pq -> _rear = NULL;
}

QueueNode *BuyQueueNode(QUDataType x)
{
	QueueNode *Node = (QueueNode *)malloc(sizeof(QueueNode));
	Node -> _data = x; 
	Node -> _next = NULL;
	return Node;
}

void QueuePush(Queue *pq,QUDataType x)
{
	assert(pq); 
	QueueNode *newnode = BuyQueueNode(x);
	if(pq -> _rear == NULL)
	{
		pq -> _front = pq -> _rear = newnode;
	}
	else
	{
		pq -> _rear -> _next = newnode;
		pq -> _rear = newnode;
	}
}

void QueuePop(Queue *pq)
{
	assert(pq && pq -> _front !=NULL);
	QueueNode *next = pq -> _front -> _next;
	free(pq -> _front);
	pq -> _front = next;
	if(pq -> _front == NULL)
	pq -> _rear = NULL;
}

QUDataType QueueFront(Queue *pq)
{
	assert(pq && pq -> _front !=NULL);
	return pq -> _front -> _data; 
}

QUDataType QueueRear(Queue *pq)
{
	assert(pq && pq -> _rear !=NULL);
	return pq -> _rear -> _data; 
}

bool QueueEmpty(Queue *pq)
{
	assert(pq);
	return  pq -> _front == NULL;
}

int QueueSize(Queue *pq)
{
	assert(pq);
	QueueNode *cur = pq -> _front;
	size_t size = 0;
	while(cur)
	{
		++size;
		cur = cur -> _next;
	}
	return size;
}


typedef struct {
    Queue _q1;
    Queue _q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *st = (MyStack *)malloc(sizeof(MyStack));
    QueueInit(&(st->_q1));
    QueueInit(&(st->_q2));
    return st;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if(!QueueEmpty(&(obj->_q1)))
        QueuePush(&(obj->_q1), x);
    else
        QueuePush(&(obj->_q2), x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    assert(obj);
    Queue *empty = &(obj -> _q1);
    Queue *nonempty = &(obj -> _q2);
    if(!(QueueEmpty(&(obj -> _q1))))
    {
         empty = &(obj -> _q2);
         nonempty = &(obj -> _q1);
    }
    while((QueueSize(nonempty))>1)
    {
        int front = QueueFront(nonempty);
        QueuePop(nonempty);
        QueuePush(empty,front);
    }
    int front = QueueFront(nonempty);
    QueuePop(nonempty);
    return front;
}


/** Get the top element. */
int myStackTop(MyStack* obj) {
    if(!QueueEmpty(&(obj->_q1)))
        return QueueRear(&(obj->_q1));
    else
        return QueueRear(&(obj->_q2));
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return QueueEmpty(&(obj->_q1)) && QueueEmpty(&(obj->_q2));
}

void myStackFree(MyStack* obj) {
    QueueDestory(&(obj->_q1));
    QueueDestory(&(obj->_q2));
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/

