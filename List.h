#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode *_prev;
	struct ListNode *_next;
}ListNode;
typedef struct List
{
	ListNode *_head;
}List;

void ListInit(List *plist);
void ListDestory(List *plist);

void ListPushBack(List *plist,LTDataType x);
void ListPopBack(List *plist);

void ListPushFront(List *plist,LTDataType x);
void ListPopFront(List *plist);

ListNode *ListFind(List *plist, LTDataType x);
void ListInsert(ListNode *pos, LTDataType x);

void ListErase(ListNode *pos);
void ListPrint(List *plist);
