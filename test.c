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
	printf("�������Ľ�����%d\n", size);
	int leafsize = BinaryTreeLeafSize(root);
	printf("��������Ҷ�ӽ�����%d\n", leafsize);
	int ksize = BinaryTreeLevelKSize(root,2);
	printf("��������k�������%d\n", ksize);
	BTNode *tem = BinaryTreeFind(root,'a');
	if (tem->_data == NULL)
		printf("�������ڶ��������ҵ�");
	else
		printf("�����ڶ��������ҵ�%c\n", tem->_data);
	if (BinaryTreeComplete(root) == true)
		printf("�ö���������ȫ������\n");
	else
		printf("�ö�����������ȫ������\n");
	BinaryTreeDestory(root);

}

int main()
{
	test();
	system("pause");
	return 0;
}