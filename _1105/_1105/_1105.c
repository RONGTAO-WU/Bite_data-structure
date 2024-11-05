#define _CRT_SECURE_NO_WARNINGS

#include"Sort.h"

void printArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void test()
{
	int arr[] = { 8,4,6,2,5,9,7,1,3 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printArr(arr, n);
	InsertSort(arr, n);
	printArr(arr, n);

	int arr2[] = { 60,20,80,40,50,30,70,10,90 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	printArr(arr2, n2);
	ShellSort(arr2, n2);
	printArr(arr2, n2);

}

int main()
{
	test();
	

	return 0;
}