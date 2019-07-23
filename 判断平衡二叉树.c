/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int height(struct TreeNode* root)
{
    if(root == NULL)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return left > right ? left+1 : right+1;

}

bool isBalanced(struct TreeNode* root){
    if(root == NULL)
        return true;
    int left = height(root->left);
    int right = height(root->right);
    if(abs(left - right) > 1)
       return false;
    return isBalanced(root->left) && isBalanced(root->right);

}


