#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int Datatype;

typedef struct QueueNode {

	Datatype Data;
	struct QueueNode* next;

}QN;

typedef struct Queue
{

	struct QueueNode* phead;
	struct QueueNode* ptail;
	int size;											// 顺便记录队列中的有效数据

}QE;

void Init(QE* pq);

void Pust(QE* pq, Datatype x);

bool Empty(QE* pq);

int Size(QE* pq);

void Pop(QE* pq);

Datatype Front(QE* pq);

Datatype Back(QE* pq);

void Destroy(QE* pq);


