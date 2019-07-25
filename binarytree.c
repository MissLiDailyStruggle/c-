#include "binarytree.h"

typedef char *QUDataType;
typedef struct QueueNode
{
	struct QueueNode *_next;
	QUDataType _data;
}QueueNode;
typedef struct Queue
{
	QueueNode *_front;
	QueueNode *_rear;
}Queue;

void QueueInit(Queue *pq)
{
	assert(pq);
	pq->_front = NULL;
	pq->_rear = NULL;
}

void QueueDestory(Queue *pq)
{
	assert(pq);
	QueueNode *cur = pq->_front;
	while (cur)
	{
		QueueNode *next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_front = pq->_rear = NULL;
}

QueueNode *BuyQueueNode(QUDataType x)
{
	QueueNode *Node = (QueueNode *)malloc(sizeof(QueueNode));
	Node->_data = x;
	Node->_next = NULL;
	return Node;
}

void QueuePush(Queue *pq, QUDataType x)
{
	assert(pq);
	QueueNode *newnode = BuyQueueNode(x);
	if (pq->_rear == NULL)
	{
		pq->_front = pq->_rear = newnode;
	}
	else
	{
		pq->_rear->_next = newnode;
		pq->_rear = newnode;
	}
}

void QueuePop(Queue *pq)
{
	assert(pq && pq->_front != NULL);
	QueueNode *next = pq->_front->_next;
	free(pq->_front);
	pq->_front = next;
	if (pq->_front == NULL)
		pq->_rear = NULL;
}

QUDataType QueueFront(Queue *pq)
{
	assert(pq && pq->_front != NULL);
	return pq->_front->_data;
}
QUDataType QueueRear(Queue *pq)
{
	assert(pq && pq->_rear != NULL);
	return pq->_rear->_data;
}

bool QueueEmpty(Queue *pq)
{
	assert(pq);
	return  pq->_front == NULL;
}

int QueueSize(Queue *pq)
{
	assert(pq);
	QueueNode *cur = pq->_front;
	size_t size = 0;
	while (cur)
	{
		++size;
		cur = cur->_next;
	}
	return size;
}

BTNode *BinaryTreeCreate(BTDataType *a,int n , int *pi)
{
	if (a[(*pi)] == '#')
		return NULL;
	struct BinaryTreeNode *cur = (BTNode *)malloc(sizeof(BTNode));
	cur->_data = a[(*pi)];
	(*pi)++;
	cur->left = BinaryTreeCreate(a,n,pi);
	(*pi)++;
	cur->right = BinaryTreeCreate(a,n,pi);
	return cur;

}
void BinaryTreePrevOrder(BTNode *root)
{
	if (root == NULL)
		return;
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
void BinaryTreeInOrder(BTNode *root)
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->right);
}
void BinaryTreePostOrder(BTNode *root)
{
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->_data);
}
void BinaryTreeLevelOrder(BTNode *root)
{
	Queue pq;
	QueueInit(&pq);
	if (root !=  NULL)
		QueuePush(&pq, root);
	while (!QueueEmpty(&pq))
	{
		BTNode* front = QueueFront(&pq);
		QueuePop(&pq);
		printf("%c ", front->_data);
		if (front->left)
			QueuePush(&pq, front->left);
		if (front->right)
			QueuePush(&pq, front->right);
	}
}
void BinaryTreeDestory(BTNode *root)
{
	if (root == NULL)
		return;
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
	root == NULL;
}
int BinaryTreeSize(BTNode *root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
int BinaryTreeLeafSize(BTNode *root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
int BinaryTreeLevelKSize(BTNode *root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
BTNode *BinaryTreeFind(BTNode *root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	struct BinaryTreeNode *lret = BinaryTreeFind(root->left, x);
	struct BinaryTreeNode *rret = BinaryTreeFind(root->right, x);
	if (lret != NULL)
		return lret;
	if (rret != NULL)
		return rret;
	return NULL;
}
bool BinaryTreeComplete(BTNode *root)
{
	Queue pq;
	QueueInit(&pq);
	if (root != NULL)
		QueuePush(&pq, root);
	while (!QueueEmpty(&pq))
	{
		BTNode* front = QueueFront(&pq);
		QueuePop(&pq);
		if (front != NULL)
		{
			QueuePush(&pq, front->left);
			QueuePush(&pq, front->right);
		}
		else
			break;
	}
	while (!QueueEmpty(&pq))
	{
		BTNode* front = QueueFront(&pq);
		QueuePop(&pq);
		if (front != NULL)
		{
			QueueDestory(&pq);
			return false;
		}
	}
	return true;
}