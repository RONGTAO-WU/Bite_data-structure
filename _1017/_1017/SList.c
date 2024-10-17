#define _CRT_SECURE_NO_WARNINGS

#include"SList.h"


void print(SL* phead)
{
	SL* Pcur = phead;
	while (Pcur)
	{
		printf("%d-> ", Pcur->data);
		Pcur = Pcur->next;
	}
	printf("NULL\n");
}

SL* SLNode(TypeData x)											// ��̬���ٿռ�
{
	SL* newnode = (SL*)malloc(sizeof(SL));
	if (newnode == NULL)
	{
		perror("malloc");
		return -1;
	}

	newnode->data = x;
	newnode->next = NULL;

	return newnode;

}

void SLPushBack(SL** pphead, TypeData x)						// β�壨���ٿռ䣬��β��������������
{
	assert(*pphead);

	SL* newnode = SLNode(x);									// ���½ڵ㿪�ٿռ�

	if (newnode == -1)
		return 0;

	if (*pphead == NULL)										// ����Ϊ�յ����
	{
		*pphead = newnode;
	}
	else 
	{															// ����Ϊ�գ���β
		SL* ptail = *pphead;									// ���׵�ַ����һ��������Ȼ������������β
		while (ptail->next)									
		{
			ptail = ptail->next;
		}
		ptail->next = newnode;
		newnode->next = NULL;
	}



}

void SLPushFront(SL** pphead, TypeData x)						// ͷ��
{
	assert(*pphead);

	SL* newnode = SLNode(x);									// ���½ڵ㿪�ٿռ�

	newnode->next = *pphead;									// �ض���
	*pphead = newnode;											// ���½ڵ���βͷ��

}

void SLPopBack(SL** pphead)										// βɾ
{
	assert(*pphead);

	

	if ((*pphead)->next == NULL)								// ����һ���ڵ���������
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SL* ptail = *pphead;
		SL* prev = NULL;										// ����һ��ָ������λ̽·ָ���ǰһ���ڵ�

		while (ptail->next)										// ��β��������->next->next���������Ϊ���ܴ���ֻ��һ���ڵ�������
		{
			prev = ptail;
			ptail = ptail->next;
		}
		prev->next = NULL;
		free(ptail);
		ptail = NULL;
	}

}

void SLPopFront(SL** pphead)									// ͷɾ
{
	assert(*pphead);

	SL* prev = (*pphead)->next;									// ����һ��������ָ��						
	
	free(*pphead);												// ���ͷ��ڸ�ֵ
	*pphead = NULL;

	*pphead = prev;

}

SL* SLFind(SL* pphead, TypeData x)
{
	assert(pphead);

	SL* ptail = pphead;

	while (ptail)
	{
		if (ptail->data == x)
		{
			return ptail;
		}
		ptail = ptail->next;
	}

	return NULL;

}

void SLInsert(SL** pphead, SL* pos, TypeData x)					// ��ָ���ڵ�λ��֮ǰ��������
{
	assert(*pphead && pos);

	SL* newnode = SLNode(x);


	if (*pphead == pos)											// pos������ͷ�ڵ�
	{
		newnode->next = pos;
		*pphead = newnode;
	}
	else
	{ 	
		SL* prev = *pphead;

		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = newnode;
		newnode->next = pos;
	}


}

void SLInsertAfter(SL** pphead, int pos, TypeData x)			// ��ָ���ڵ�λ��֮���������
{


}
