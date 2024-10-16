#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"


void SLcheckCapacity(SL* ps)								// 开空间
{
	if (ps->capacity == ps->size)							// 表长度等于有效长度时空间不足开辟空间
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

void SLInit(SL* ps)											// 初始化
{

	ps->arr = NULL;
	ps->capacity = 0;
	ps->size = 0;

}

void SLPushBack(SL* ps, SLDatatype x)						// 尾插
{
	assert(ps);
	SLcheckCapacity(ps);

	ps->arr[ps->size] = x;
	ps->size++;
}

void SLPushFront(SL* ps, SLDatatype x)						// 头插
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

void SLPopBack(SL* ps)										// 尾删
{
	assert(ps && ps->size);

	ps->size--;

}

void SLPopFront(SL* ps)										// 头删
{
	assert(ps && ps->size);

	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i+1];
	}

	ps->size--;
}

void SLInsert(SL* ps, int pos,SLDatatype x)					// 任意(下标)位置插入
{
	assert(ps);
	
	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = x;
	ps->size++;

}

void SLErase(SL* ps, int pos)								// 任意位置删除
{
	assert(ps);

	for (int i = pos; i < ps->size-1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

void SLFind(SL* ps, SLDatatype x)							// 查找任意元素
{
	assert(ps);

	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
		{
			printf("找到了\n");
			break;
		}
		if(i == ps->size)
			printf("未找到\n");
	}
	

}

void SLDesTroy(SL* ps)										// 销毁顺序表
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