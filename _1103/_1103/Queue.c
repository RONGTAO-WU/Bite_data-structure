#define _CRT_SECURE_NO_WARNINGS

#include"Queue.h"



void Init(QE* pq)												// ��ʼ��
{
	assert(pq);

	pq->phead = pq->ptail = NULL;
	pq->size = 0;

}

void Pust(QE* pq, QDatatype x)									// �����
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

bool Empty(QE* pq)												// �ж϶��������޽ڵ�
{
	return pq->phead != NULL;
}

int Size(QE* pq)												// ���ض����нڵ����
{
	return pq->size;
}

void Pop(QE* pq)												// ������,��ͷ�Ƴ�
{
	assert(pq);

	if (pq->phead == pq->ptail)												// ֻ��һ���ڵ�����
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{																		// ��ֹһ���ڵ�����
		QE* ret = pq->phead->next;
		free(pq->phead);
		pq->phead = ret;
	}

	pq->size--;

}

QDatatype Front(QE* pq)											// ȡ����ͷ��Ԫ��
{
	assert(pq && Empty(pq));

	return pq->phead->Data;
}

QDatatype Back(QE* pq)											// ȡ����β��Ԫ��
{
	assert(pq && Empty(pq));

	return pq->ptail->Data;
}

void Destroy(QE* pq)											// ���ٶ���
{
	assert(pq);
	if (pq->phead == pq->ptail)												// ֻ��һ���ڵ�����
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