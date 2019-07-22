#include <stdio.h>
#include <malloc.h>
#include <assert.h> 
// 顺序表的动态存储 
typedef int SLDataType;
typedef struct SeqList 
{ 
SLDataType* array; // 指向动态开辟的数组 
size_t size ; // 有效数据个数 
size_t capicity ; // 容量空间的大小 
}SeqList; 

// 基本增删查改接口 
void SeqListInit(SeqList* psl, size_t capacity); 
void SeqListDestory(SeqList* psl); 

void CheckCapacity(SeqList* psl); 
void SeqListPushBack(SeqList* psl, SLDataType x); 
void SeqListPopBack(SeqList* psl); 
void SeqListPushFront(SeqList* psl, SLDataType x); 
void SeqListPopFront(SeqList* psl); 

int SeqListFind(SeqList* psl, SLDataType x); 
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x); 
void SeqListErase(SeqList* psl, size_t pos); 
void SeqListRemove(SeqList* psl, SLDataType x); 
void SeqListModify(SeqList* psl, size_t pos, SLDataType x); 
void SeqListPrint(SeqList* psl); 

// 扩展面试题实现 
void SeqListBubbleSort(SeqList* psl); 
int SeqListBinaryFind(SeqList* psl, SLDataType x); 
// 本题要求：时间复杂度：O(N) 空间复杂度 O(1) 
void SeqListRemoveAll(SeqList* psl, SLDataType x);
 
void SeqListInit(SeqList* psl, size_t capacity)
{
	assert(psl);
	psl->array  = (SLDataType*)malloc(capacity*sizeof(SLDataType));
	psl->capicity = capacity;
	psl->size = 0;
}
void SeqListDestory(SeqList* psl)
{
	assert(psl);
	if(psl->size > 0)
	{
		free(psl->array);
	}
	psl->array = NULL;
	psl->capicity = psl->size = 0;
}

void CheckCapacity(SeqList* psl)
{
	assert(psl);
	if(psl->size == psl->capicity)
	{
		int newcapicity = psl->capicity == 0 ? 2 : psl->capicity *  2;
		psl->array =(SLDataType*) realloc(psl->array,sizeof(SLDataType) * newcapicity);
		psl->capicity = newcapicity;
	}
}

void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}

void SeqListPopBack(SeqList* psl)
{
	assert(psl);
	psl->size--;
}

void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);
	int i = 0;
	psl->size++;
	CheckCapacity(psl);
	for(i = psl->size-1;i > 0;i--)
	{
		psl->array[i] = psl->array[i-1];
	}
	psl->array[0] = x;
	
}


void SeqListPopFront(SeqList* psl)
{
	assert(psl);
	int i = 0;
	for(i = 0;i < psl->size - 1;i++)
	{
		psl->array[i] = psl->array[i+1];
	}
		psl->size--;
}

int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl->size > 0);
	int i = 0;
	for(i = 0;i < psl->size;i++)
	{
		if(psl->array[i] == x)
		return i;
	}
	return -1;
}
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(0<=pos<psl->size);
	int i = 0;
	psl->size++;
	CheckCapacity(psl);
	for(i = psl->size-1;i > pos;i--)
	{
		psl->array[i] = psl->array[i-1];
	}
	psl->array[pos] = x;
}
void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl->size > 0);
	int i = 0;
	for(i = pos;i < psl->size - 1;i++)
	{
		psl->array[i] = psl->array[i+1];
	}
		psl->size--;
	 
}

void SeqListRemove(SeqList* psl, SLDataType x)
{
	assert(psl->size > 0);
	int pos = 0;
	int i = 0;
	for(i = 0;i < psl->size;i++)
	{
		if(psl->array[i] == x)
		pos = i;
	}
	for(i = pos;i < psl->size - 1;i++)
	{
		psl->array[i] = psl->array[i+1];
	}
		psl->size--;
}
void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	assert(0<=pos<psl->size);
	psl->array[pos] = x;
}

void SeqListprint(SeqList* psl)
{
	assert(psl->size > 0);
	int i = 0;
	for(i = 0;i < psl->size;i++)
	{
		printf("%d ",psl->array[i]);
	}
	printf("\n");
}

void SeqListBubbleSort(SeqList* psl)
{   assert(psl->size > 0);
	int i = 0;
	int j = 0;
	int temp = 0;
	int noswap;
	for(i = 1;i < psl->size;i++)
	{
		noswap = 1;
		for(j = 0; j < psl->size - i;j++) 
		if(psl->array[j]>psl->array[j+1])
		{
			noswap = 0;
			temp = psl->array[j];
			psl->array[j] = psl->array[j+1];
			psl->array[j+1] = temp;
		}
		if(noswap)
		break;
	}
}
int SeqListBinaryFind(SeqList* psl, SLDataType x)
{
	assert(psl->size > 0);
	int left = 0;
	int right = psl->size - 1;
	while(left <= right)
	{
		int mid = left +(right + left)/2;
		if(x > psl->array[mid])
		left = mid + 1;
		else if(x < psl->array[mid])
		right = mid - 1;
		else
		return mid;
	}
	return -1;
}
// 本题要求：时间复杂度：O(N) 空间复杂度 O(1) 
void SeqListRemoveAll(SeqList* psl, SLDataType x)
{
	assert(psl->size > 0);
	int i = 0;
	int k = 0;
	for(i = 0; i < psl->size;i++)
	{
		if(psl->array[i] != x)
		{
			psl->array[k] = psl->array[i];
			k++;
		}
	}
	psl->size = k;
}

void Test()
{
	SeqList psl;
	SeqListInit(&psl, 4); 
	SeqListPushBack(&psl,3); 
	SeqListPushBack(&psl,4); 
	SeqListPushBack(&psl,5);
	SeqListPushBack(&psl,6);
	SeqListPushBack(&psl,7);
	SeqListprint(&psl);
    SeqListPopBack(&psl); 
    SeqListprint(&psl); 
    SeqListPushFront(&psl,8); 
    SeqListprint(&psl);
	SeqListPopFront(&psl); 
    SeqListprint(&psl);
    printf("4的序号为%d\n",SeqListFind(&psl,4));
    printf("4的序号为%d\n",SeqListBinaryFind(&psl,4));
    SeqListInsert(&psl, 2, 9);
    SeqListprint(&psl);
    SeqListBubbleSort(&psl);
    SeqListprint(&psl);
    SeqListErase(&psl,2);
    SeqListprint(&psl);
    SeqListRemove(&psl,6);
    SeqListprint(&psl);
    SeqListModify(&psl,0,0);
    SeqListprint(&psl);
    SeqListPushBack(&psl,6);
	SeqListPushBack(&psl,6);
	SeqListprint(&psl);
    SeqListRemoveAll(&psl,6);
    SeqListprint(&psl);
    SeqListDestory(&psl); 
}

int main()
{
	Test();
	return 0;
}
