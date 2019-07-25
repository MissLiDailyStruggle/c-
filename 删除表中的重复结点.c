/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
    
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL || pHead->next == NULL)
            return pHead;
        ListNode *n0 = NULL;
        ListNode *n1 = pHead;
        ListNode *n2 = pHead->next;
        while(n2)
        {
            //如果不相等一直相加；
            if(n2->val != n1->val)
            {
                n0 = n1;
                n1 = n2;
                n2 = n2->next;
            }
            else
            {
                //找出所有与n1相等的n2，直到n2不等于n1，连接n0和n2；
                while(n2 && n2->val == n1->val)
                    n2 = n2->next;
                if(n0)
                    n0->next = n2;
                else
                    pHead = n2;
                //删除掉所有相同的结点
                while(n1 != n2)
                {
                    ListNode* next = n1->next;
                    free(n1);
                    n1 = next;
                }
                //重新给n1，n2赋值
                n1 = n2;
                if(n2)
                    n2 = n2->next;
            }
        }
        return pHead;

    }
};
