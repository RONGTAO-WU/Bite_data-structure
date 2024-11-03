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

	while (Empty(&hp))
	{
		printf("%d ", Top(&hp));
		pop(&hp);
	}

}

void HeapSort(int* arr, int n)									// O(n*logn)
{
	int child = n - 1;
	int parent = (child - 1) / 2;
	for (int i = parent; i >= 0; i--)							// 从最后一个结点的父结点开始向下调整，必须保证跟结点以下的结点是有序的
	{															// 向下调整建堆
		Adjustdown(arr, i, n);
	}

	int end = n - 1;

	while (end > 0)												// 堆排序，从堆顶取数据
	{
		Swap(&arr[0], &arr[end]);
		Adjustdown(arr, 0, end);
		end--;
	}


}

void test2()
{

	int arr[] = { 15,30,60,75,90,25,45,80 };
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
	HeapSort(arr, n);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}

void test1()													// O(N^2)
{
	int arr[] = { 60,80,40,20,30,90,70,10 };
	int n = sizeof(arr) / sizeof(arr[0]);

	HP hp;
	Init(&hp);

	for (int i = 0; i < n; i++)
	{
		push(&hp, arr[i]);
	}
	int j = 0;
	while (Empty(&hp))
	{
		arr[j++] = Top(&hp);
		pop(&hp);
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	Destroy(&hp);
}


void BubbleSort(int* arr, int n)							// 冒泡排序排序数组
{
	for (int i = 0; i < n; i++)
	{
		int flag = 0;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				flag = 1;
				Swap(&arr[j], &arr[j + 1]);
			}
		}
			
		if (flag == 0)										// flag为发生改变说明数组有序
			break;
	}
}

void CreateNDate()
{
	int n = 100000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");							// 文件指针打开文件
	if (fin == NULL)
	{
		perror("fopen");
		return -1;
	}

	for (int i = 0; i < n; i++)
	{
		int x = (rand() + i) % 100000;						// 生成的随机数不能超过10万
		fprintf(fin, "%d\n", x);							// 向文件中写入10万个随机数			
	}

	fclose(fin);
}

void TopK()
{
	int k = 0;
	printf("请输入K:");
	scanf("%d", &k);

	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen");
		return -2;
	}

	int* minHeap = (int*)malloc(sizeof(int) * k);
	if (minHeap == NULL)
	{
		perror("minHeap");
		return -3;
	}

	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &minHeap[i]);
	}

	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		Adjustdown(minHeap, i, k);
	}

	int x = 0;
	while (fscanf(fout, "%d", &x) != EOF)
	{
		if (x > minHeap[0])
		{
			minHeap[0] = x;
			Adjustdown(minHeap, 0, k);
		}
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", minHeap[i]);
	}

	fclose(fout);
	
}

int main()
{

//	test();
//	test1();												// 利用堆结构排序
	test2();												// 数组建堆

	//int arr[] = { 20,60,80,40,90,70,30,10 };
	//int n = sizeof(arr) / sizeof(arr[0]);
	//BubbleSort(arr,n);									// 数组手动排序

	//for (int i = 0; i < n; i++)
	//{
	//	printf("%d ", arr[i]);
	//}

//	CreateNDate();											// 生成随机数
//	TopK();													

	return 0;
}