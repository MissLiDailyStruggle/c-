#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType *_a;
	int _top;
	int _capacity;
}Stack;


void StackInit(Stack *ps);
void StackDestory(Stack *ps);

void StackPush(Stack *ps, STDataType x);
void StackPop(Stack *ps);
STDataType StackTop(Stack *ps);
bool StackEmpty(Stack *ps);
size_t StackSize(Stack *ps);

void StackInit(Stack *ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}
void StackDestory(Stack *ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
	free(ps->_a);
	ps = NULL;
}
void StackPush(Stack *ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = (ps->_capacity == 0) ? 2 : ps->_capacity * 2;
		ps->_a = (STDataType*)realloc(ps->_a, newcapacity * sizeof(STDataType));
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}
void StackPop(Stack *ps)
{
	assert(ps && ps->_top > 0);
	--ps->_top;
}
STDataType StackTop(Stack *ps)
{
	assert(ps && ps->_top > 0);
	return ps->_a[ps->_top - 1];
}
bool StackEmpty(Stack *ps)
{
	assert(ps);
	return !(ps->_top);
}
size_t StackSize(Stack *ps)
{
	assert(ps);
	return ps->_top;
}

typedef struct MyQueue {
    Stack _popst;
    Stack _pushst;
} MyQueue;


/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
    StackInit(&(q -> _popst));
    StackInit(&(q -> _pushst));
    return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    StackPush(&(obj -> _pushst), x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if(StackEmpty(&(obj -> _popst)))
    {
        while(!StackEmpty(&(obj -> _pushst)))
        {
            int top = StackTop(&(obj -> _pushst));
            StackPush(&(obj -> _popst), top);
            StackPop(&(obj -> _pushst));
        }
    }
    int top = StackTop(&(obj -> _popst));
    StackPop(&(obj -> _popst));
    return top;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
   if(StackEmpty(&(obj -> _popst)))
    {
        while(!StackEmpty(&(obj -> _pushst)))
        {
            int top = StackTop(&(obj -> _pushst));
            StackPush(&(obj -> _popst), top);
            StackPop(&(obj -> _pushst));
        }
    }
    int top = StackTop(&(obj -> _popst));
    return top;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return StackEmpty(&(obj -> _pushst)) && StackEmpty(&(obj -> _popst));
}

void myQueueFree(MyQueue* obj) {
    StackDestory(&(obj -> _pushst));
    StackDestory(&(obj -> _popst));
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/

