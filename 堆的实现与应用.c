#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>
#include <stdbool.h> 

typedef int  HPDateType;
typedef struct Heap
{
	HPDateType* _a;
	int _size;
	int _capacity;
}Heap;

void HeapInit(Heap *hp,HPDateType *a,int n);
void HeapDestory(Heap *hp);
void HeapPush(Heap *hp,HPDateType x);
void HeapPop(Heap *hp);
HPDateType HeapTop(Heap *hp);
int HeapSize(Heap *hp);
bool HeapEmpty(Heap *hp);
void AdjustDown(HPDateType *a,int n,int parent);
void AdjustUp(HPDateType *a,int child);

//升序 用大堆 
void HeapSort(int *a,int n);

void TestHeap();

void Swap (int *p1,int *p2)
{
	int temp = 0;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void print(Heap *hp)
{
	assert(hp -> _size > 0);
	int i = 0;
	for(i = 0;i < (hp -> _size);i++)
	{
		printf("%d ",hp -> _a [i]);
	}
	printf("\n");
}
void HeapInit(Heap *hp,HPDateType *a,int n)
{
	assert(hp);
	int i = (n-1-1)/2; 
	hp -> _a = malloc(sizeof(HPDateType)*n);
	memcpy(hp -> _a,a,sizeof(HPDateType)*n);
	hp -> _capacity = hp -> _size = n;
	for(i = (n-1-1)/2;i >= 0;--i)
	{
		AdjustDown(hp -> _a,n,i);
	}
}

void HeapDestory(Heap *hp)
{
	assert(hp);
	if(hp -> _a)
	{
		free(hp -> _a);
	}
	hp -> _a = NULL;
	hp->_size = hp->_capacity = 0;
}

void AdjustDown(HPDateType *a,int n,int parent)
{
	int child = parent * 2 + 1;
	while(child < n-1)
	{
		if(a[child] > a[child + 1] && child+1 < n-1)
		child++;
		if(a[parent] > a[child])
		{
			Swap(&a[child],&a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else break;
	}
}

void AdjustUp(HPDateType *a,int child)
{
	int parent = (child - 1) / 2;
	while(child > 0)
	{
		if(a[child] < a[parent])
		{
			Swap(&a[child],&a[parent]);
		    child = parent;
		    parent = (child-1) / 2; 
		}
		else break;
	}
}

void HeapPush(Heap *hp,HPDateType x)
{
	int i = 0;
	if(hp -> _size == hp -> _capacity)
	{
		int newcapacity = hp -> _capacity == 0 ? 2 : hp ->  _capacity *  2;
		hp -> _a = realloc(hp -> _a,sizeof(HPDateType) * newcapacity);
		hp -> _capacity = newcapacity;
	}
	hp -> _a[hp -> _size] = x;
	hp -> _size++;
	AdjustUp(hp -> _a,hp -> _size-1);
}

void HeapPop(Heap *hp)
{
	assert(hp -> _size > 0);
	Swap(&(hp -> _a[0]),&(hp -> _a[hp -> _size - 1]));
	--hp -> _size;
	AdjustDown(hp -> _a,hp -> _size,0);
}

HPDateType HeapTop(Heap *hp)
{
	return hp -> _a[0];
}

int HeapSize(Heap *hp)
{
	return hp -> _size;
}

bool HeapEmpty(Heap *hp)
{
	return hp -> _size == 0;
}

void HeapSort(int *a,int n)
{
	int i = 0;
	for(i = (n-2)/2;i >= 0;--i)
	{
		AdjustDown(a,n,i);
	}
	int end = n-1;
	while(end > 0)
	{
		Swap(&a[0],&a[end]);
		AdjustDown(a,end,0);
		end --;
	}
}

void TestHeap()
{
	int a[]={1,7,4,3,8,5,9};
	Heap hp;
	HeapInit(&hp,a,sizeof(a)/sizeof(int));
	print(&hp);
    HeapPush(&hp,0);
    print(&hp);
    HeapPush(&hp,2);
    print(&hp);
    HeapPop(&hp);
    print(&hp);
    int top = HeapTop(&hp);
    printf("堆顶元素为：%d\n",top);
    int size = HeapSize(&hp);
    printf("堆元素个数为：%d\n",size);
    HeapDestory(&hp);
}

void Test()
{
	int i = 0;
	int a[]={1,7,4,3,8,5,9};
    HeapSort(a,sizeof(a)/sizeof(int));
    for(i = 0; i < sizeof(a)/sizeof(int);i++)
    {
    	printf("%d ",a[i]);
	}
    printf("\n");
} 
int main()
{
	TestHeap();
	Test();
	return 0;
}
