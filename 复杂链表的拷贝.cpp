/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
 Node *BuyNode(int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->next == NULL;
    node->random == NULL;
    node->val = val;
    return node;
}
class Solution {
public:
    Node *copyRandomList(Node* head) {
        //拷贝插入
        Node *cur = head;
        while(cur)
        {
            Node *next = cur->next;
            Node *newnode = BuyNode(cur->val);
            newnode->next = next;
            cur->next = newnode;
            cur = next;
        }
        //置randow
        cur = head;
        while(cur)
        {
            Node *cpnode = cur->next;
            if(cur->random)
                cpnode->random = cur->random->next;
            cur = cur->next->next;
        }
        //拆解重新链接
        Node *cphead = BuyNode(0);
        Node *cptail = cphead;
        cur = head;
        while(cur)
        {
            Node *cpnode = cur->next;
            Node *next = cur->next->next;
            //拆解
            cur->next = next;
            //链接
            cptail->next = cpnode;
            cptail = cpnode;
            //迭代
            cur = next;
        }
        Node *cplist = cphead->next;
        free(cphead);
        return cplist;
    }
};
