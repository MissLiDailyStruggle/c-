/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSametree(struct TreeNode* p, struct TreeNode* q)
{
    if(p == NULL && q == NULL)
        return true;
    if(p == NULL || q == NULL)
        return false;
    if(p->val != q->val)
        return false;
    return isSametree(p->left,q->left) && isSametree(p->right,q->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){
    if(s == NULL)
        return false;
    if(s->val == t->val)
    {
        if(isSametree(s,t))
        return true;
    }
    
    return isSubtree(s->left,t) || isSubtree(s->right,t);
}


