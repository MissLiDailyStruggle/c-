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

bool isValid(char * s){
    Stack st;
    StackInit(&st);
    char *symbol[3] = {"[]","()","{}"};
    
    while(*s)
    {
        if(*s == '(' || *s == '{' || *s == '[')
        {
            StackPush(&st,*s);
        }
        else if(*s == ')' || *s == '}' || *s == ']')
        {
            if(StackEmpty(&st))
                return false;
            
            STDataType top = StackTop(&st);
            StackPop(&st);
            
            for(size_t i = 0;i < 3;++i)
            {
                if(*s == symbol[i][1])
                {
                    if(top != symbol[i][0])
                    {
                        StackDestory(&st);
                        return false;
                    }
                    else 
                    {
                        break;
                    }
                }
            }
        }
        ++s;
    }
    bool ret = StackEmpty(&st);
    StackDestory(&st);
    return ret;
}
