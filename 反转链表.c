/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
struct ListNode* reverseList(struct ListNode* head){
    ListNode* newhead = NULL;
    ListNode* p = head;
    while(p)
    {
        ListNode* temp = p -> next;
        p -> next = newhead;
        newhead = p;
        p = temp;
        }
        return newhead;

}

