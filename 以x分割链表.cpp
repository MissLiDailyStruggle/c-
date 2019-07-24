/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
typedef struct ListNode ListNode;
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        ListNode *lesshead ,*greaterhead ,*lesstail,*greatertail;
        lesshead = lesstail = (ListNode*)malloc(sizeof(ListNode));
        greaterhead = greatertail = (ListNode*)malloc(sizeof(ListNode));
        ListNode *cur = pHead;
        while(cur)
        {
            if(cur->val < x)
            {
                lesstail->next = cur;
                lesstail = cur;
            }
            else
            {
                greatertail->next = cur;
                greatertail = cur;
            }
            cur = cur->next;
        }
        greatertail->next = NULL;
        lesstail->next = greaterhead->next;
        ListNode *list = lesshead->next;
        free(lesshead);
        return list;
    }
};
