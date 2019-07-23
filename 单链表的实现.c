#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdbool.h> 
typedef int SLTDataType; 
typedef struct SListNode 
{ 
SLTDataType _data; 
struct SListNode* _next; 
}SListNode; 

typedef struct SList 
{ 
SListNode* _head; 
}SList; 

void SListInit(SList* plist); 
void SListDestory(SList* plist); 

SListNode* BuySListNode(SLTDataType x); 
void SListPushFront(SList* plist, SLTDataType x); 
void SListPopFront(SList* plist); 
SListNode* SListFind(SList* plist, SLTDataType x); 
// 在pos的后面进行插入 
void SListInsertAfter(SListNode* pos, SLTDataType x); 
// 在pos的前面进行插入 
void SListEraseAfter(SListNode* pos); 
void SListRemove(SList* plist, SLTDataType x); 

void SListPrint(SList* plist); 
void TestSList(); 

void SListInit(SList* plist)
{
	assert(plist);
    plist->_head = NULL;
} 

void SListDestory(SList* plist)
{
	assert(plist);
	SListNode *cur = plist->_head;
	while(cur)
	{
		SListNode *next = cur -> _next;
		free(cur);
		cur = next;
	} 
	plist->_head = NULL;
}

SListNode* BuySListNode(SLTDataType x)
{
	SListNode *node = (SListNode *)malloc(sizeof(SListNode));
	node->_data = x;
	node->_next = NULL;
	return node;
}

void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode *newnode = BuySListNode(x); 
	SListNode *first = plist->_head;
	newnode->_next = first;
	plist->_head = newnode;
}

void SListPopFront(SList* plist)
{
	assert(plist);
	SListNode *first = plist->_head;
	SListNode *second = first->_next;
	free(first);
	plist->_head = second;
}

SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode *cur= plist->_head;
	while(cur != NULL)
	{
		if(x == cur->_data)
		return cur;
		cur = cur->_next;
	}
	return NULL;
}

// 在pos的后面进行插入 
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	SListNode *newnode = BuySListNode(x); 
	SListNode *cur = pos->_next;
	newnode->_next = cur;
	pos->_next = newnode;
} 
// 在pos的后面进行删除 
void SListEraseAfter(SListNode* pos)
{
	SListNode *first = pos->_next;
	SListNode *second = first->_next;
	pos->_next = second;
	free(first);
}
void SListRemove(SList* plist, SLTDataType x)
{
	assert(plist);
	int i = 0;
	SListNode *prev= plist->_head;
	SListNode *pos = SListFind(plist,x);
	SListNode *next = pos ->_next;
	while(prev->_next != pos)
	{
		prev = prev->_next;
	}
	prev->_next = next;
	free(pos);	
} 

void SListPrint(SList* plist)
{
	assert(plist);
	SListNode *cur = plist->_head;
	while(cur)
	{
		SListNode *next = cur -> _next;
		printf("%d-",cur->_data);
		cur = next;
	} 
	printf("\n");
}

void TestSList()
{
	SList pl; 
	SListInit(&pl);
	SListPushFront(&pl,4);
	SListPushFront(&pl,5);
	SListPushFront(&pl,6);
	SListPushFront(&pl,7);
	SListPrint(&pl);
	SListPopFront(&pl);
	SListPrint(&pl);
	SListNode *pos1 = SListFind(&pl,6);
    SListInsertAfter(pos1,2);
    SListPrint(&pl);
    SListNode *pos2 = SListFind(&pl,6);
    SListEraseAfter(pos2);
    SListPrint(&pl);
    SListRemove(&pl,4);
    SListPrint(&pl);
	SListDestory(&pl);
}

int main()
{
	TestSList(); 
	return 0;
}
