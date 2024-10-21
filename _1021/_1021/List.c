#define _CRT_SECURE_NO_WARNINGS

#include"List.h"



LT* LTInit()
{
	LT* phead = (LT*)malloc(sizeof(LT));

	if (phead == NULL)
	{
		perror("malloc");
		return -1;
	}

	phead->Data = -1;
	phead->next = phead->perv = phead;

	return phead;
}


LT* buyNode(Datatype x)
{

	LT* node = (LT*)malloc(sizeof(LT));

	if (node == NULL)
	{
		perror("malloc");
		return -1;
	}

	node->Data = x;
	node->next = node->perv = node;

	return node;

}

void print(LT* phead)
{
	if (phead == NULL)
		return NULL;

	LT* pcur = phead->next;

	printf("%d <=>", phead->Data);
	while (pcur != phead)
	{
		printf(" %d <=>", pcur->Data);
		pcur = pcur->next;
	}
	printf(" %d\n", phead->Data);


}

bool Empty(LT* phead)													// �ж������Ƿ�Ϊ��
{
	assert(phead);

	return phead->next != phead;										// ������������Լ�˵����Ϊ��
}

void LTPustBack(LT* phead, Datatype x)									// β��
{
	assert(phead);

	LT* newnode = buyNode(x);

	phead->perv->next = newnode;
	newnode->perv = phead->perv;

	newnode->next = phead;
	phead->perv = newnode;


}

void LTPustFront(LT* phead, Datatype x)									// ͷ��
{
	assert(phead);

	LT* newnode = buyNode(x);
	
	newnode->next = phead->next;
	newnode->perv = phead;

	phead->next->perv = newnode;
	phead->next = newnode;

	
}

void LTPopBack(LT* phead)												// βɾ
{
	assert(Empty(phead));

	phead->perv = phead->perv->perv;
	phead->perv->next = phead;


}

void LTPopFront(LT* phead)												// ͷɾ
{
	assert(Empty(phead));

	phead->next = phead->next->next;
	phead->next->perv = phead;

}

LT* LTFind(LT* phead, Datatype x)										// ����
{

	assert(phead);

	LT* ret = phead->next;
	while (ret != phead)
	{
		if (ret->Data == x)
			return ret;
		ret = ret->next;
	}
	return NULL;
	
}

void LTInsert(LT* phead, LT* pos, Datatype x)							// ��ָ��λ�ú����ڵ�
{
	assert(phead && pos);												// pos��������ڶ��Թ���ȥ�������������治��Ҫ���ж��Ҳ���pos�����

	LT* ret = LTFind(phead,x);


	LT* newnode = buyNode(x);

	newnode->next = pos->next;
	newnode->next->perv = newnode;

	newnode->perv = pos;
	pos->next = newnode;


	
}

void LTErase(LT* phead, LT* pos)										// ɾ��ָ���ڵ�
{
	assert(phead && pos);

	pos->perv->next = pos->next;
	pos->next->perv = pos->perv;

	free(pos);
	pos = NULL;


}

//void DesTroy(LT** pphead)
//{
//	assert(*pphead);
//
//	LT* ret = (*pphead)->next;
//	LT* exit = ret;
//
//	while (ret != *pphead)
//	{
//		ret = ret->next;
//		free(exit);
//		exit = NULL;
//	}
//
//	free(ret);
//	ret = NULL;
//
//}

void DesTroy(LT* phead)													// ����
{

	assert(phead);

	LT* ret = phead->next;
	LT* exit = ret;

	while (ret != phead)
	{
		ret = ret->next;
		free(exit);
		exit = NULL;
	}

	free(ret);
	ret = NULL;

}