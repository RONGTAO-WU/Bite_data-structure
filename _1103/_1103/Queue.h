#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//typedef int QDatatype;
typedef struct BTNode* QDatatype;						// 修改一：数据类型改为结构体类型
														// 这是个前置声明，告诉编译器这是个结构体类型

typedef struct QueueNode {

	QDatatype Data;
	struct QueueNode* next;

}QN;

typedef struct Queue
{

	struct QueueNode* phead;
	struct QueueNode* ptail;
	int size;											// 顺便记录队列中的有效数据

}QE;

void Init(QE* pq);

void Pust(QE* pq, QDatatype x);

bool Empty(QE* pq);

int Size(QE* pq);

void Pop(QE* pq);

QDatatype Front(QE* pq);

QDatatype Back(QE* pq);

void Destroy(QE* pq);


