#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"



void test1(sl)
{
	SLInit(&sl);
	SLPushBack(&sl , 1);				// β��
	SLPushBack(&sl , 2);
	SLPushBack(&sl , 3);
	SLPushBack(&sl , 4);
	SLPushBack(&sl , 5);

	print(&sl);

	SLPushFront(&sl, 1);				// ͷ��
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 5);
	print(&sl);


	SLPopBack(&sl);						// βɾ
	print(&sl);
	SLPopBack(&sl);
	print(&sl);


	SLPopFront(&sl);					// ͷɾ
	print(&sl);

	SLInsert(&sl, 4, 99);				// ����(�±�)λ�ò���
	print(&sl);

	SLErase(&sl, 6);					// ����λ��ɾ��
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