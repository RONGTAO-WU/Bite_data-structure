#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"



void test1(sl)
{
	SLInit(&sl);
	SLPushBack(&sl , 1);				// 尾插
	SLPushBack(&sl , 2);
	SLPushBack(&sl , 3);
	SLPushBack(&sl , 4);
	SLPushBack(&sl , 5);

	print(&sl);

	SLPushFront(&sl, 1);				// 头插
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 5);
	print(&sl);


	SLPopBack(&sl);						// 尾删
	print(&sl);
	SLPopBack(&sl);
	print(&sl);


	SLPopFront(&sl);					// 头删
	print(&sl);

	SLInsert(&sl, 4, 99);				// 任意(下标)位置插入
	print(&sl);

	SLErase(&sl, 6);					// 任意位置删除
	print(&sl);

	SLFind(&sl, 99);

	SLDesTroy(&sl);
}

int main()
{
	SL sl;

	test1(&sl);


	return 0;
}