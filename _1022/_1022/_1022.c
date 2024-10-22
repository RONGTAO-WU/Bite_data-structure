#define _CRT_SECURE_NO_WARNINGS

#include"Queue.h"



void test()
{
	QE pq;
	Init(&pq);

	Pust(&pq, 10);
	Pust(&pq, 20);
	Pust(&pq, 30);
	Pust(&pq, 40);
	Pust(&pq, 50);

	while (Empty(&pq))
	{
		printf("%d\n", Front(&pq));
		Pop(&pq);
	}

	Destroy(&pq);
	printf("%x %d", &pq, (&pq)->size);

}

int main()
{
	test();

	return 0;
}