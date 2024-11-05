#define _CRT_SECURE_NO_WARNINGS

#include"Sort.h"


void InsertSort(int* arr, int n)							// ֱ�Ӳ�������
{
	for (int i = 0; i < n-1; i++)
	{
		int end = i;										// end��ʾ��Ч�����β
		int tmp = arr[end+1];								// tmp��ʾ���������Ԫ��
		
		while (end >= 0)									// �����Ԫ�������������Ԫ�أ��Ӻ���ǰ�����αȽ�
		{
			if (arr[end] > tmp)								// ǰ�����ֵ���ں������ֵ������ֵ��������
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
				break;

			arr[end + 1] = tmp;								// ����if��end�Ѿ���1�ˣ�end+1����ԭ��end��λ��
															// ����Ļ�����if������ֵ������������ĺ���
		}
	}

}

void ShellSort(int* arr, int n)								// ϣ������
{
	int gap = n;											// ��ʼ��gapΪ���鳤��
	while (gap > 1)
	{
		gap = gap / 3 + 1;									// �������������
		for (int i = 0; i < n - gap; i += gap)				// ��ÿ�������������
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