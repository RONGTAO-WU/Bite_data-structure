#define _CRT_SECURE_NO_WARNINGS

#include"List.h"



void test()
{

	LT* plist = LTInit();

	LTPustBack(plist, 1);
	LTPustBack(plist, 2);
	LTPustBack(plist, 3);
	LTPustBack(plist, 4);
	LTPustBack(plist, 5);

	LTPustFront(plist, 10);
	LTPustFront(plist, 20);
	LTPustFront(plist, 30);
	LTPustFront(plist, 40);
	LTPustFront(plist, 50);

	LTPopBack(plist);
	LTPopBack(plist);

	LTPopFront(plist);
	LTPopFront(plist);

	print(plist);

	LT* ret = LTFind(plist,1);
	if (ret)
		printf("’“µΩ¡À\n");
	else
		printf("Œ¥’“µΩ\n");

	LTInsert(plist, ret, -40);
	print(plist);

	LTErase(plist, ret);
	print(plist);

//	DesTroy(&plist);

	DesTroy(plist);
	plist = NULL;

	printf("%x", plist);

}




int main()
{
	test();


	return 0;
}