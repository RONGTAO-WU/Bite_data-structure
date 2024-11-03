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

void PreOrder(BTNode* root);							// ǰ�����
void InOrder(BTNode* root);								// �������
void PostOrder(BTNode* root);							// �������

int BinaryTreeSize(BTNode* root);						// ������������
int BinaryTreeLeafSize(BTNode* root);					// ������Ҷ�ӽ�����
int BinaryTreeLevelKSize(BTNode* root, int k);			// ��������K�������
int BinaryTreeDepth(BTNode* root);						// �������ĸ߶�
BTNode* BinaryTreeFind(BTNode* root,Datatype x);		// ����������ֵΪx�Ľ��
void BinaryTreeDestory(BTNode** root);					// ������������