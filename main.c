#define _CRE_SECURE_NO_WARNNGS
#include "List.h"

void test()
{
	List plt;
	ListInit(&plt);
	ListPushBack(&plt,4);
	ListPushBack(&plt,5);
	ListPushBack(&plt,6);
	ListPushBack(&plt,7);
    ListPrint(&plt);
    ListPopBack(&plt);
    ListPrint(&plt);
    ListPushFront(&plt,7);
    ListPrint(&plt);
    ListPopFront(&plt);
    ListPrint(&plt);
    ListNode *pos1 = ListFind(&plt, 5);
    ListInsert(pos1,2);
    ListPrint(&plt);
    ListNode *pos2 = ListFind(&plt, 5);
    ListErase(pos2);
    ListPrint(&plt);
    ListDestory(&plt);
    ListPrint(&plt);

}
int main()
{
	test();
	system("pause");
	return 0;
}
