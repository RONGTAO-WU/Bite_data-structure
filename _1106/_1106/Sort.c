#define _CRT_SECURE_NO_WARNINGS

#include"Sort.h"

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void SelectSort(int* arr, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int mini = begin;
		int maxi = begin;
		for (int i = begin+1; i <= end; i++)
		{
			if (arr[mini] > arr[i])							// 符号改变数组升降序
				mini = i;
			if (arr[maxi] < arr[i])
				maxi = i;
		}

		if (begin == maxi)									// 特殊处理begin刚好是最大值
		{
			maxi = mini;									// 将maxi和mini放在同一个位置，防止两次交换
		}

		Swap(&arr[mini], &arr[begin]);
		Swap(&arr[maxi], &arr[end]);
		begin++;
		end--;
	}
}

void AdjustDown(int* arr, int parent, int n)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child] < arr[child + 1])
			child++;

		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}

}