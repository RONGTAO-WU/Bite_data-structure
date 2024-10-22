#define _CRT_SECURE_NO_WARNINGS

#include"Stack.h"



void Init(ST* st)												// ³õÊ¼»¯
{
	assert(st);

	st->arr = NULL;
	st->capacity = st->top = 0;

}

void Destroy(ST* st)											// Ïú»Ù
{
	free(st->arr);
	st->arr = NULL;
	st->capacity = st->top = 0;
}

void stackpush(ST* st, int x)									// ÈëÕ»
{
	assert(st);


	if (st->top == st->capacity)
	{
		int tmp = st->capacity == 0 ? 4 : st->capacity * 2;
		Datatype* space = (Datatype*)realloc(st->arr, sizeof(Datatype) * tmp);
		if (space == NULL)
		{
			perror("realloc");
			return -1;
		}
		st->arr = space;
		st->capacity = tmp;
	}

	st->arr[st->top++] = x;
	

}

void stackpop(ST* st)											// ÒÆ³ýÕ»¶¥ÔªËØ
{
	assert(stackEmpty(st));

	st->top--;

}

Datatype stacktop(ST* st)										// È¡Õ»¶¥ÔªËØ
{
	assert(stackEmpty(st));

	return st->arr[st->top - 1];

}

bool stackEmpty(ST* st)											// ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
{
	assert(st);

	return st->top != 0;

}

void print(ST* st)												
{
	assert(st);
	
	for (int i = 0; i < st->top; i++)
	{
		printf("%d ", st->arr[i]);
	}
	printf("\n");

}

int STsize(ST* st)
{
	return st->top;
}