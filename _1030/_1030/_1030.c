#define _CRT_SECURE_NO_WARNINGS

#include"Head.h"



void test()
{
	HP hp;
	Init(&hp);

	push(&hp, 10);
	push(&hp, 20);
	push(&hp, 30);
	push(&hp, 40);
	push(&hp, 50);

	print(&hp);

	pop(&hp);
	pop(&hp);

	print(&hp);
}



int main()
{

	test();

	return 0;
}