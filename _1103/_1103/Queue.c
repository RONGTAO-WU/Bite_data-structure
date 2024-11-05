#define _CRT_SECURE_NO_WARNINGS

#include"Queue.h"



void Init(QE* pq)												// 初始化
{
	assert(pq);

	pq->phead = pq->ptail = NULL;
	pq->size = 0;

}

void Pust(QE* pq, QDatatype x)									// 入队列
{
	assert(pq);

	QN* newnode = (QN*)malloc(sizeof(QN));
	if (newnode == NULL)
	{
		perror("malloc");
		return -1;
	}

	newnode->Data = x;
	newnode->next = NULL;

	if (pq->phead == NULL)
	{
		pq->ptail = pq->phead = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}

	pq->size++;

}

bool Empty(QE* pq)												// 判断队列中有无节点
{
	return pq->phead != NULL;
}

int Size(QE* pq)												// 返回队列中节点个数
{
	return pq->size;
}

void Pop(QE* pq)												// 出队列,把头移除
{
	assert(pq);

	if (pq->phead == pq->ptail)												// 只有一个节点的情况
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{																		// 不止一个节点的情况
		QE* ret = pq->phead->next;
		free(pq->phead);
		pq->phead = ret;
	}

	pq->size--;

}

QDatatype Front(QE* pq)											// 取队列头部元素
{
	assert(pq && Empty(pq));

	return pq->phead->Data;
}

QDatatype Back(QE* pq)											// 取队列尾部元素
{
	assert(pq && Empty(pq));

	return pq->ptail->Data;
}

void Destroy(QE* pq)											// 销毁队列
{
	assert(pq);
	if (pq->phead == pq->ptail)												// 只有一个节点的情况
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		QN* tmp = pq->phead;

		while (tmp)
		{
			QN* next = pq->phead->next;
			free(pq->phead);
			tmp = next;
		}

		pq->phead = pq->ptail = NULL;
		pq->size = 0;

		free(tmp);
		tmp = NULL;
	}

}