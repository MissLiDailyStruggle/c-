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
void TestQueue()
{
	Queue p;
	QueueInit(&p);
	QueuePush(&p,4);
	QueuePush(&p,5);
	QueuePush(&p,6);
	QueuePush(&p,7);
	while(!QueueEmpty(&p))
	{
		QUDataType temp = QueueFront(&p);
		printf("%d ",temp);
		QueuePop(&p);
	}
	QueueDestory(&p);
}

int main()
{
	TestQueue();
	return 0;
}
