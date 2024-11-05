#define _CRT_SECURE_NO_WARNINGS

#include"Sort.h"


void InsertSort(int* arr, int n)							// 直接插入排序
{
	for (int i = 0; i < n-1; i++)
	{
		int end = i;										// end表示有效数组结尾
		int tmp = arr[end+1];								// tmp表示乱序数组的元素
		
		while (end >= 0)									// 乱序的元素与有序数组的元素（从后往前）依次比较
		{
			if (arr[end] > tmp)								// 前面的数值大于后面的数值，将数值大的往后放
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
				break;

			arr[end + 1] = tmp;								// 上面if中end已经减1了，end+1就是原来end的位置
															// 有序的话跳过if，将数值放在有序数组的后面
		}
	}

}

void ShellSort(int* arr, int n)								// 希尔排序
{
	int gap = n;											// 初始化gap为数组长度
	while (gap > 1)
	{
		gap = gap / 3 + 1;									// 对数组分组排序
		for (int i = 0; i < n - gap; i += gap)				// 对每个分组进行排序
		{
			int end = i;
			int tmp = arr[end + gap];

			while (end >= 0)
			{
				if (arr[end] < tmp)
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
					break;

				arr[end + gap] = tmp;
			}
		}
	}
}