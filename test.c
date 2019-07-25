#include "binarytree.h"

void test()
{
	char str[100];
	//abc##de#g##f###
	scanf("%s", str);
	int i = 0;
	BTNode * root = BinaryTreeCreate(str,sizeof(str)/sizeof(char),&i);
	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");
	BinaryTreeLevelOrder(root);
	printf("\n");
	int size = BinaryTreeSize(root);
	printf("二叉树的结点个数%d\n", size);
	int leafsize = BinaryTreeLeafSize(root);
	printf("二叉树的叶子结点个数%d\n", leafsize);
	int ksize = BinaryTreeLevelKSize(root,2);
	printf("二叉树的k层结点个数%d\n", ksize);
	BTNode *tem = BinaryTreeFind(root,'a');
	if (tem->_data == NULL)
		printf("不可以在二叉树中找到");
	else
		printf("可以在二叉树中找到%c\n", tem->_data);
	if (BinaryTreeComplete(root) == true)
		printf("该二叉树是完全二叉树\n");
	else
		printf("该二叉树不是完全二叉树\n");
	BinaryTreeDestory(root);

}

int main()
{
	test();
	system("pause");
	return 0;
}