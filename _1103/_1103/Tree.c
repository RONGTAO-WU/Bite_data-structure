#define _CRT_SECURE_NO_WARNINGS

#include"Tree.h"



void PreOrder(BTNode* root)											// 前序遍历
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

void InOrder(BTNode* root)											// 中序遍历
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

void PostOrder(BTNode* root)										// 后序遍历
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

int BinaryTreeSize(BTNode* root)									// 二叉树结点个数
{

	if (root == NULL)
		return 0;
	else
		return 1+ BinaryTreeSize(root->left)+ BinaryTreeSize(root->right);

}

int BinaryTreeLeafSize(BTNode* root)								// 二叉树叶子结点个数
{

	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);

}

int BinaryTreeLevelKSize(BTNode* root, int k)						// 二叉树第K层结点个数
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);

}

int BinaryTreeDepth(BTNode* root)									// 二叉树的高度
{

	if (root == NULL)
		return 0;
	
	int leftDep = BinaryTreeDepth(root->left);
	int rightDep = BinaryTreeDepth(root->right);

	return 1 + (leftDep > rightDep ? leftDep : rightDep);
}

BTNode* BinaryTreeFind(BTNode* root, Datatype x)					// 二叉树查找值为x的结点
{
	if (root == NULL)
		return NULL;

	if (root->data == x)											// 找到了返回
		return root;

	BTNode* leftFind = BinaryTreeFind(root->left, x);				// 先找左子树
	if (leftFind)													// 若左子数不为空，则返回，否则遍历右子树
		return leftFind;

	BTNode* rightFind = BinaryTreeFind(root->right, x);
	if (rightFind)
		return rightFind;

	return NULL;
}

void BinaryTreeDestory(BTNode** root)								// 二叉树的销毁
{
	if (*root == NULL)
		return NULL;

	BinaryTreeDestory(&(*root)->left);
	BinaryTreeDestory(&(*root)->right);

	free(*root);
	*root = NULL;
}