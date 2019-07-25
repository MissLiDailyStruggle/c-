/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    struct ListNode* reverseList(struct ListNode* head) 
    {
        ListNode *newhead = NULL;
        ListNode *cur = head;
        while(cur)
        {
            ListNode *next = cur->next;
            cur->next = newhead;
            newhead = cur;
            cur = next;
        }
        return newhead;
    }
    bool chkPalindrome(ListNode* A) {
        ListNode *cur = A;
        size_t n = 0;
        while(cur)
        {
            cur = cur->next;
            ++n;
        }
        cur = A;
        int mid  = n/2;
        while(mid--)
        {
            cur = cur->next;
        }
        ListNode *head1 = A;
        ListNode *head2 = reverseList(cur);
        mid = n/2;
        while(mid--)
        {
            if(head1->val == head2->val)
            {
                head1 = head1->next;
                head2 = head2->next;
            }
            else
                return false;
        }
        return true;
        // write code here
    }
};
