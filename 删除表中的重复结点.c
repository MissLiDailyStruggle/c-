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
            //��������һֱ��ӣ�
            if(n2->val != n1->val)
            {
                n0 = n1;
                n1 = n2;
                n2 = n2->next;
            }
            else
            {
                //�ҳ�������n1��ȵ�n2��ֱ��n2������n1������n0��n2��
                while(n2 && n2->val == n1->val)
                    n2 = n2->next;
                if(n0)
                    n0->next = n2;
                else
                    pHead = n2;
                //ɾ����������ͬ�Ľ��
                while(n1 != n2)
                {
                    ListNode* next = n1->next;
                    free(n1);
                    n1 = next;
                }
                //���¸�n1��n2��ֵ
                n1 = n2;
                if(n2)
                    n2 = n2->next;
            }
        }
        return pHead;

    }
};
