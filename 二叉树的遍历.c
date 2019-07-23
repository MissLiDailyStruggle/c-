#include <stdio.h>
#include <malloc.h>
typedef struct TreeNode
{
    struct TreeNode *left;
    struct TreeNode *right;
    char val;
}Node;

Node *CreatTree(char *str,int *pi)
{
    if(str[(*pi)] == '#')
        return NULL;
    Node *cur =(Node *)malloc(sizeof(Node));
    cur->val = str[(*pi)];
    (*pi)++;
    cur->left = CreatTree(str,pi);
    (*pi)++;
    cur->right =CreatTree(str,pi);
    return cur;
}

void InorderTree(struct TreeNode*root)
{
    if(root == NULL)
        return;
    InorderTree(root->left);
    printf("%c ",root->val);
    InorderTree(root->right);
}

int main()
{
    char str[100];
    scanf("%s",str);
    int i = 0;
    Node * root = CreatTree(str,&i);
    InorderTree(root);
    return 0;
}
