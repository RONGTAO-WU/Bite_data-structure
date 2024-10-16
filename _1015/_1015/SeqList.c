#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"


void SLcheckCapacity(SL* ps)								// ���ռ�
{
	if (ps->capacity == ps->size)							// ���ȵ�����Ч����ʱ�ռ䲻�㿪�ٿռ�
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;				
		SLDatatype* tmp = (SLDatatype*)realloc(ps->arr, newcapacity * sizeof(SLDatatype));
		if (tmp == NULL)
		{
			perror("realloc");
			return -1;
		}
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}

}

void SLInit(SL* ps)											// ��ʼ��
{

	ps->arr = NULL;
	ps->capacity = 0;
	ps->size = 0;

}

void SLPushBack(SL* ps, SLDatatype x)						// β��
{
	assert(ps);
	SLcheckCapacity(ps);

	ps->arr[ps->size] = x;
	ps->size++;
}

void SLPushFront(SL* ps, SLDatatype x)						// ͷ��
{
	assert(ps);
	SLcheckCapacity(ps);

	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	ps->size++;

}

void SLPopBack(SL* ps)										// βɾ
{
	assert(ps && ps->size);

	ps->size--;

}

void SLPopFront(SL* ps)										// ͷɾ
{
	assert(ps && ps->size);

	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i+1];
	}

	ps->size--;
}

void SLInsert(SL* ps, int pos,SLDatatype x)					// ����(�±�)λ�ò���
{
	assert(ps);
	
	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = x;
	ps->size++;

}

void SLErase(SL* ps, int pos)								// ����λ��ɾ��
{
	assert(ps);

	for (int i = pos; i < ps->size-1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

void SLFind(SL* ps, SLDatatype x)							// ��������Ԫ��
{
	assert(ps);

	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
		{
			printf("�ҵ���\n");
			break;
		}
		if(i == ps->size)
			printf("δ�ҵ�\n");
	}
	

}

void SLDesTroy(SL* ps)										// ����˳���
{

	assert(ps && ps->size);
	free(ps->arr);
	ps->arr = NULL;
	ps->capacity = 0;
	ps->size = 0;

}

void print(SL* ps)
{
	assert(ps);

	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}