#define _CRT_SECURE_NO_WARNINGS

#include"SList.h"






void test(SL *sl)							// ͬ����ָ�����ָ��
{
	print(sl);
	SLPushBack(&sl,1);
	SLPushBack(&sl,2);
	SLPushBack(&sl,3);
	SLPushBack(&sl,4);
	SLPushBack(&sl,5);
	print(sl);

	SLPushFront(&sl, 10);
	SLPushFront(&sl, 20);
	SLPushFront(&sl, 30);
	SLPushFront(&sl, 40);
	SLPushFront(&sl, 50);
	print(sl);

	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPopBack(&sl);
	SLPopBack(&sl);
	print(sl);

	SLPopFront(&sl);
	SLPopFront(&sl);
	SLPopFront(&sl);
	SLPopFront(&sl);
	print(sl);

	SL* Find = SLFind(sl, 3);
	if (Find == NULL)
	{
		printf("δ�ҵ�\n");
	}
	else
		printf("�ҵ���\n");

//	print(Find);
	SLInsert(&sl, Find, 40);
	print(sl);

	SLInsertAfter(Find, 400);
	print(sl);

//	Find = SLFind(sl, 10);						// ���������posΪͷ�ڵ�ʱ
	SLErase(&sl, Find);							// ɾ��pos
	print(sl);

	Find = SLFind(sl, 40);
	Find = SLFind(sl, 4);						// ���������posΪβ�ڵ�ʱ

	SLEraseAfter(Find);
	print(sl);

	SLDestroy(&sl);
	print(sl);



}

int main()
{
	/*SL sl;

	test(&sl);*/

	SL* Node1 = (SL*)malloc(sizeof(SL));
	SL* Node2 = (SL*)malloc(sizeof(SL));
	SL* Node3 = (SL*)malloc(sizeof(SL));
	SL* Node4 = (SL*)malloc(sizeof(SL));

	Node1->data = 1;
	Node2->data = 2;
	Node3->data = 3;
	Node4->data = 4;

	Node1->next = Node2;
	Node2->next = Node3;
	Node3->next = Node4;
	Node4->next = NULL;

	SL* plist = Node1;
	test(plist);
	//Init(plist);


	return 0;
}