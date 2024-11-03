#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int Datatype;

typedef struct BinaryTreeNode
{
	int data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

void PreOrder(BTNode* root);							// 前序遍历
void InOrder(BTNode* root);								// 中序遍历
void PostOrder(BTNode* root);							// 后序遍历

int BinaryTreeSize(BTNode* root);						// 二叉树结点个数
int BinaryTreeLeafSize(BTNode* root);					// 二叉树叶子结点个数
int BinaryTreeLevelKSize(BTNode* root, int k);			// 二叉树第K层结点个数
int BinaryTreeDepth(BTNode* root);						// 二叉树的高度
BTNode* BinaryTreeFind(BTNode* root,Datatype x);		// 二叉树查找值为x的结点
void BinaryTreeDestory(BTNode** root);					// 二叉树的销毁