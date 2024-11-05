#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//typedef int QDatatype;
typedef struct BTNode* QDatatype;						// �޸�һ���������͸�Ϊ�ṹ������
														// ���Ǹ�ǰ�����������߱��������Ǹ��ṹ������

typedef struct QueueNode {

	QDatatype Data;
	struct QueueNode* next;

}QN;

typedef struct Queue
{

	struct QueueNode* phead;
	struct QueueNode* ptail;
	int size;											// ˳���¼�����е���Ч����

}QE;

void Init(QE* pq);

void Pust(QE* pq, QDatatype x);

bool Empty(QE* pq);

int Size(QE* pq);

void Pop(QE* pq);

QDatatype Front(QE* pq);

QDatatype Back(QE* pq);

void Destroy(QE* pq);


