#define _CRT_SECURE_NO_WARNINGS

#include"Tree.h"


BTNode* buyNode(Datatype x)
{
	BTNode* tmp = (BTNode*)malloc(sizeof(BTNode));
	if (tmp == NULL)
	{
		perror("malloc");
		return -1;
	}

	tmp->data = x;
	tmp->left = tmp->right = NULL;

	return tmp;
}

BTNode* createTree()
{
	BTNode* NodeA = buyNode('A');
	BTNode* NodeB = buyNode('B');
	BTNode* NodeC = buyNode('C');
	BTNode* NodeD = buyNode('D');
	BTNode* NodeE = buyNode('E');
	BTNode* NodeF = buyNode('F');

	NodeA->left = NodeB;
	NodeA->right = NodeC;
	NodeB->left = NodeD;
	NodeC->left = NodeE;
	NodeC->right = NodeF;

	return NodeA;
}

void test()
{
	BTNode* root = createTree();
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");

	printf("�������Ľ�����:%d\n", BinaryTreeSize(root));

	printf("������Ҷ�ӽ�����:%d\n", BinaryTreeLeafSize(root));

	printf("��������K�������:%d\n", BinaryTreeLevelKSize(root, 3));

	printf("�������ĸ߶�:%d\n", BinaryTreeDepth(root));

	BTNode* ret = BinaryTreeFind(root, 'E');

	if (ret)
		printf("�ҵ���");
	else
		printf("δ�ҵ�");

	BinaryTreeDestory(&root);

}

int main()
{
	
	test();

	return 0;
}
