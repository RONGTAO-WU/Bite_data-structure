#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>



//	189. ��ת����
//	https://leetcode.cn/problems/rotate-array/description/



//	����һ��ԭ������˫ѭ��				O(n ^ 2)
//	1.ȡ�����һ��Ԫ��
//	2.������������ƶ�
//	3.�����һ��Ԫ�ط��������һ��λ��

//void rotate(int* nums, int numsSize, int k) {
//
//     k %= numsSize;
//
//     while(k--)
//     {
//         int tmp = nums[numsSize-1];
//         for(int i = numsSize-1;i > 0;i--)
//         {
//             nums[i] = nums[i-1];
//         }
//         nums[0] = tmp;
//     }
//}

//	������������޷�ͨ�����������5����Ԫ��





//	������������һ�������飬����ת�������η���Ԫ��		O(n)



//void rotate(int* nums, int numsSize, int k) {
//  
//    k %= numsSize;
//    int* tmp = (int*)malloc(numsSize * sizeof(int));
//
//    int j = 0;
//        for (int i = numsSize - k; i < numsSize; i++)
//    {
//        tmp[j++] = nums[i];
//    }
//        for (int i = 0; i < numsSize - k; i++)
//    {
//        tmp[j++] = nums[i];
//    }
//
//        for (int i = 0; i < numsSize; i++)
//    {
//        nums[i] = tmp[i];
//    }
//}





//	�����������鰴����ת������Ϊ�����֣��ֱ�������ֽ�������Ȼ�����������������			O(1)



//void revolve(int* nums, int left, int right)                        // �������
//{
//    while (left < right)
//    {
//        int tmp = nums[left];
//        nums[left] = nums[right];
//        nums[right] = tmp;
//        left++;
//        right--;
//    }
//}
//
//void rotate(int* nums, int numsSize, int k) {
//
//    k %= numsSize;
//    revolve(nums, 0, numsSize - k - 1);                              // �������鳤���йأ����ܵ���дk
//    revolve(nums, numsSize - k, numsSize - 1);
//    revolve(nums, 0, numsSize - 1);
//
//
//}
//
//int main()
//{
//    int arr[] = { -1,-100,3,99 };
//    int sz = sizeof(arr) / sizeof(arr[0]);
//
//    rotate(arr, sizeof(arr) / sizeof(arr[0]), 2);
//
//    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//    {
//        printf("%d ", arr[i]);
//    }
//
//    return 0;
//}






//	27. �Ƴ�Ԫ��
//	https://leetcode.cn/problems/remove-element/description/

//int removeElement(int* nums, int numsSize, int val) {
//
//    assert(nums);
//
//    int dest = 0;
//    int src = 0;
//
//    while (src < numsSize)
//    {
//        if (nums[src] != val)
//        {
//            nums[dest++] = nums[src++];
//        }
//        else
//            src++;
//    }
//    return dest;
//
//
//}







//	26. ɾ�����������е��ظ���
//	https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/

//int removeDuplicates(int* nums, int numsSize) {
//    int src = 0;
//    int dest = src+1;
//
//    while(dest < numsSize)
//    {
//        if(nums[src] == nums[dest])
//        {
//            dest++;
//        }
//        else
//        {
//           src++;
//           nums[src] = nums[dest];
//        }
//        
//    }
//
//    return src+1;
//}







void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	
	int j = 0;

	for (int i = m; i < m + n; i++)
	{
		nums1[i] = nums2[j++];
	}

	for (int i = 0; i < nums1Size; i++)
	{
		printf("%d ", nums1[i]);
	}
	printf("\n");

	int temp = 0;

	for (int i = 0; i < m + n - 1; i++)
	{
		for (int j = 0; j < m + n -1 - i; j++)									// �ٸ�-1���½���Խ��
		{
			if (nums1[j] > nums1[j + 1])
			{
				temp = nums1[j];
				nums1[j] = nums1[j + 1];
				nums1[j + 1] = temp;
			}
		}
		
	}

}

int main()
{
	int nums1[] = { 1,2,3,0,0,0};
	int nums2[] = { 2,4,5 };

	merge(nums1, 6, 3, nums2, 3, 3);

	for (int i = 0; i < 6; i++)
	{
		printf("%d ", nums1[i]);
	}

	return 0;
}





//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
//
//	int s = m + n - 1;
//	int l1 = m - 1;
//	int l2 = n - 1;
//
//	if (m == 0)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			nums1[i] = nums2[i];
//		}
//	}
//
//	while (l1 >= 0 && l2 >= 0) {
//		if (nums1[l1] > nums2[l2]) {
//			nums1[s] = nums1[l1];
//			s--;
//			l1--;
//		}
//		else {
//			nums1[s] = nums2[l2];
//			s--;
//			l2--;
//		}
//	}
//
//	while (l2 >= 0) {
//		nums1[s] = nums2[l2];
//		s--;
//		l2--;
//	}
//}
//
//
//
//int main()
//{
//
//	int arr1[] = { 2 ,0 };
//	int arr2[] = { 1 };
//
//	merge(arr1, 2, 1, arr2, 1, 1);
//
//	for (int i = 0; i < 2; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//
//
//	return 0;
//}