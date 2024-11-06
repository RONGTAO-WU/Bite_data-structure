#define _CRT_SECURE_NO_WARNINGS

#include"Sort.h"

void print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test()
{
	int arr[] = { 9,6,3,2,5,8,7,4,1,0 };
	int n = sizeof(arr) / sizeof(arr[0]);

	print(arr, n);
	SelectSort(arr, n);
	print(arr, n);
}

void HeadSort(int *arr,int n)								// ½¨¶Ñ
{
	int child = n - 1;
	int parent = (child - 1) / 2;

	for (int i = parent; i >= 0; i--)
		AdjustDown(arr, i, n);

	print(arr, n);

	int end = n - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, 0, end);
		end--;
	}

	print(arr, n);

}

int main()
{

	test();

	int arr[] = { 1,4,7,8,5,2,3,6,9,0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	HeadSort(arr,n);

	return 0;
}
