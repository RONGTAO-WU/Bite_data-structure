#define _CRT_SECURE_NO_WARNINGS

#include"Tree.h"



void PreOrder(BTNode* root)											// ǰ�����
{

	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	printf("%c ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);

}

void InOrder(BTNode* root)											// �������
{

	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);

}

void PostOrder(BTNode* root)										// �������
{

	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);

}

int BinaryTreeSize(BTNode* root)									// ������������
{

	if (root == NULL)
		return 0;
	else
		return 1+ BinaryTreeSize(root->left)+ BinaryTreeSize(root->right);

}

int BinaryTreeLeafSize(BTNode* root)								// ������Ҷ�ӽ�����
{

	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);

}

int BinaryTreeLevelKSize(BTNode* root, int k)						// ��������K�������
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);

}

int BinaryTreeDepth(BTNode* root)									// �������ĸ߶�
{

	if (root == NULL)
		return 0;
	
	int leftDep = BinaryTreeDepth(root->left);
	int rightDep = BinaryTreeDepth(root->right);

	return 1 + (leftDep > rightDep ? leftDep : rightDep);
}

BTNode* BinaryTreeFind(BTNode* root, Datatype x)					// ����������ֵΪx�Ľ��
{
	if (root == NULL)
		return NULL;

	if (root->data == x)											// �ҵ��˷���
		return root;

	BTNode* leftFind = BinaryTreeFind(root->left, x);				// ����������
	if (leftFind)													// ����������Ϊ�գ��򷵻أ��������������
		return leftFind;

	BTNode* rightFind = BinaryTreeFind(root->right, x);
	if (rightFind)
		return rightFind;

	return NULL;
}

void BinaryTreeDestory(BTNode** root)								// ������������
{
	if (*root == NULL)
		return NULL;

	BinaryTreeDestory(&(*root)->left);
	BinaryTreeDestory(&(*root)->right);

	free(*root);
	*root = NULL;
}