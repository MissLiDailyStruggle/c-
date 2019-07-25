#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <assert.h>

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
}BTNode; 

BTNode *BinaryTreeCreate(BTDataType *a,int n,int *pi);
void BinaryTreeDestory(BTNode **root);

int BinaryTreeSize(BTNode *root);
int BinaryTreeLeafSize(BTNode *root);
int BinaryTreeLevelKSize(BTNode *root,int k);

BTNode *BinaryTreeFind(BTNode *root, BTDataType x);

void BinaryTreePrevOrder(BTNode *root);
void BinaryTreeInOrder(BTNode *root);
void BinaryTreePostOrder(BTNode *root);
void BinaryTreeLevelOrder(BTNode *root);
bool BinaryTreeComplete(BTNode *root);