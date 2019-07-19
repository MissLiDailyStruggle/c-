#include <stdio.h> 
#include <stdlib.h>
#include <assert.h> 
#include <malloc.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType *_a;
	int _top;
	int _capacity;
}Stack;

void StackInit(Stack *ps)
{
	assert(ps);
	ps -> _a = NULL;
	ps -> _top = ps -> _capacity = 0;
}
void StackDestory(Stack *ps)
{
	assert(ps);
	if (ps ->_a != NULL) 
	{
		free(ps->_a);
		ps->_a=NULL;
		ps->_capacity=ps->_top=0;
	}
}

void StackPush(Stack *ps,STDataType x)
{
	assert(ps);
	if(ps -> _top == ps -> _capacity)
	{
		size_t newcapacity = ps -> _capacity == 0 ? 2 : (ps -> _capacity)*2;
		ps -> _a = (STDataType*)realloc(ps -> _a , newcapacity * sizeof(STDataType));
		ps -> _capacity = newcapacity;
	}
	ps -> _a[ps -> _top] = x;
	ps -> _top++;
}

void StackPop(Stack *ps)
{
	assert(ps && ps -> _top > 0);
	ps -> _top--;
}
STDataType StackTop(Stack *ps)
{
	assert(ps && ps -> _top > 0);
	return ps -> _a[ps -> _top-1];
}
bool StackEmpty(Stack *ps)
{
	assert(ps);
	return !(ps -> _top);
}
int StackSize(Stack *ps)
{
	assert(ps);
	return ps -> _top;
}

void TestStack()
{
	Stack p;
	StackInit(&p);
	StackPush(&p,4);
	StackPush(&p,5);
	StackPush(&p,6);
	StackPush(&p,7);
	while(!(StackEmpty(&p)))
	{
		STDataType top = StackTop(&p);
		StackPop(&p);
		printf("%d",top);
	}
	StackDestory(&p);
}

int main()
{
	TestStack();
	return 0;
}
