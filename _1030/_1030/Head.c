#define _CRT_SECURE_NO_WARNINGS

#include"Head.h"



void print(HP* php)
{
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->arr[i]);
	}
	printf("\n");
}

void Init(HP* php)
{
	assert(php);

	php->arr = NULL;
	php->capacity = php->size = 0;

}

void Destroy(HP* php)
{
	assert(php);

	free(php->arr);
	php->arr = NULL;
	php->capacity = php->size = 0;

}

void Swap(HPDatatype* x, HPDatatype* y)						// 交换
{
	HPDatatype tmp = *x;
	*x = *y;
	*y = tmp;
}

void Adjustup(HPDatatype* arr, int child)					// 向上调整
{
	int parent = (child - 1) / 2;

	while (child > 0)										// 当前结点为0时说明是根结点
	{
		if (arr[child] > arr[parent])						// > : 大堆			< : 小堆
		{
			Swap(&arr[child], &arr[parent]);
			child = parent;									// 当前位置跳到父结点上
			parent = (child - 1) / 2;						// 指向下一个父结点
		}
		else
			break;
	}

}

void push(HP* php, HPDatatype x)
{
	assert(php);

	if (php->capacity == php->size)
	{
		int tmp = php->capacity == 0 ? 4 : php->capacity * 2;

		HPDatatype* ret = (HPDatatype*)realloc(php->arr, sizeof(HPDatatype) * tmp);
		if (ret == NULL)
		{
			perror("realloc");
			return -1;
		}

		php->arr = ret;
		php->capacity = tmp;
	}

	php->arr[php->size] = x;
	Adjustup(php->arr, php->size);							// 每插入一次数据调整一次
	php->size++;

}

void Adjustdown(HPDatatype *arr,int parent,int size)
{
	assert(Empty(arr));
	int child = parent * 2 + 1;

	while (child < size)											// 向下调整孩子结点不能越界
	{
		if (child +1 < size && arr[child] < arr[child + 1])			// 左孩子 大于/小于 右孩子，找小的那个孩子	child+1 < size 保证右孩子不越界
		{
			child++;
		}

		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);						// 交换两个结点
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void pop(HP* php)
{
	assert(Empty(php));

	Swap(&php->arr[0], &php->arr[php->size-1]);				// 堆顶元素跟堆尾元素互换(堆尾元素是size-1)，size-1，堆顶向下调整
	php->size--;

	Adjustdown(php->arr, 0, php->size);

}

bool Empty(HP* php)
{
	return php->size != 0;
}

int size(HP* php)
{
	assert(php);
	return php->size;
}

HPDatatype Top(HP* php)
{
	assert(Empty(php));

	return php->arr[0];
}

