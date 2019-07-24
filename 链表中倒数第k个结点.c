/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
typedef struct ListNode listNode;

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    ListNode *slow = pListHead;
    ListNode *fast = slow;
    //fast����k����slow��ʼ�ߣ�fast��slowʼ�ղ�k��fastΪ�գ���slowΪ������k�����
    while(k--)
    {
        if(fast)
        {
            fast = fast->next;
        }
        else
            return NULL;
    }
    while(fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
        return slow;
    }
};
