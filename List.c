#define _CRE_SECURE_NO_WARNNGS
#include "List.h"

void ListInit(List *plist)
{
	assert(plist);
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
	head -> _next = head;
	head -> _prev = head;
    plist -> _head = head;
}

void ListDestory(List *plist)
{
	assert(plist);
	ListNode *head = plist -> _head;
	ListNode *cur = head -> _next;
	while(cur != head)
	{
		ListNode *next = cur -> _next;
		free(cur);
		cur = next;
	}
	plist -> _head = NULL;
}

ListNode * BuyListNode(LTDataType x)
{
	ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
	cur -> _data = x;
	cur -> _next = NULL;
	cur -> _prev = NULL;
}

void ListPushBack(List *plist,LTDataType x)
{
	assert(plist);
	ListNode *head = plist -> _head;
	ListInsert(head,x);
	//ListNode *tail = head -> _prev;
	//ListNode *newnode = BuyListNode(x);
	//newnode -> _next = head;
	//head -> _prev = newnode;
	//tail -> _next = newnode;
	//newnode -> _prev = tail;
}
void ListPopBack(List *plist)
{
	assert(plist);
	ListNode *head = plist -> _head;
	assert(head -> _next != head);
	ListNode *tail = head -> _prev;
	ListNode *prev = tail -> _prev;
	free(tail);
	prev -> _next = head;
	head -> _prev = prev;
}

void ListPushFront(List *plist,LTDataType x)
{
	assert(plist);
	ListNode *head = plist -> _head;
	ListNode *first = head -> _next;
	ListNode *newnode = BuyListNode(x);
	newnode -> _next = first;
	first -> _prev = newnode;
	head -> _next = newnode;
	newnode -> _prev = head;
}
void ListPopFront(List *plist)
{
	assert(plist);
	ListNode *head = plist -> _head;
	assert(head -> _next != head);
	ListNode *first = head -> _next;
	ListNode *second = first -> _next;
	free(first);
	head -> _next = second;
	second -> _prev = head;
}

ListNode *ListFind(List *plist, LTDataType x)
{
	assert(plist);
	ListNode *head = plist -> _head;
	ListNode *cur = head -> _next;
	while(cur != head)
	{
		if(x == cur -> _data)
		return cur;
		cur = cur -> _next;
	}
	return NULL;
}
void ListInsert(ListNode *pos, LTDataType x)
{
	assert(pos);
	ListNode *prev = pos -> _prev;
	ListNode *newnode = BuyListNode(x);
	newnode -> _next = pos;
	pos -> _prev = newnode;
	newnode -> _prev = prev;
	prev -> _next = newnode;
}

void ListErase(ListNode *pos)
{
	assert(pos);
	ListNode *prev = pos -> _prev;
	ListNode *next = pos -> _next;
	free(pos);
	prev -> _next = next;
	next -> _prev = prev;
}
void ListPrint(List *plist)
{
	assert(plist);
    ListNode *head = plist -> _head;
    ListNode *cur = head ->_next;
	while(cur != head)
	{
		printf("%d-",cur -> _data);
		cur = cur -> _next;
	} 
	printf("\n");
}
