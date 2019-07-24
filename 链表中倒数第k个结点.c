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
    //fast先走k步，slow开始走，fast和slow始终差k，fast为空，则slow为倒数第k个结点
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
