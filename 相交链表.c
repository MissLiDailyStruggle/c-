/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lenA = 0, lenB = 0;
    struct ListNode* curA = headA, *curB = headB;
    while(curA) {
        ++lenA;
        curA = curA->next;
    }
    
    while(curB) {
        ++lenB;
        curB = curB->next;
    }
    
    int gap = abs(lenA-lenB);
    struct ListNode* longList = headA, *shortList = headB;
    if(lenA < lenB) {
        longList = headB;
        shortList = headA;
    }
    
    while(gap--){
        longList = longList->next;
    }
    
    while(longList && shortList)
    {
        if(longList == shortList) {
            return longList;
        }
        else {
            longList = longList->next;
            shortList = shortList->next;
        }
    }
    
    return NULL;
}
