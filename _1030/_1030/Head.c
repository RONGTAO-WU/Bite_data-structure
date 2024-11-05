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

void Swap(HPDatatype* x, HPDatatype* y)						// ����
{
	HPDatatype tmp = *x;
	*x = *y;
	*y = tmp;
}

void Adjustup(HPDatatype* arr, int child)					// ���ϵ���
{
	int parent = (child - 1) / 2;

	while (child > 0)										// ��ǰ���Ϊ0ʱ˵���Ǹ����
	{
		if (arr[child] > arr[parent])						// > : ���			< : С��
		{
			Swap(&arr[child], &arr[parent]);
			child = parent;									// ��ǰλ�������������
			parent = (child - 1) / 2;						// ָ����һ�������
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
	Adjustup(php->arr, php->size);							// ÿ����һ�����ݵ���һ��
	php->size++;

}

void Adjustdown(HPDatatype *arr,int parent,int size)
{
	assert(Empty(arr));
	int child = parent * 2 + 1;

	while (child < size)											// ���µ������ӽ�㲻��Խ��
	{
		if (child +1 < size && arr[child] < arr[child + 1])			// ���� ����/С�� �Һ��ӣ���С���Ǹ�����	child+1 < size ��֤�Һ��Ӳ�Խ��
		{
			child++;
		}

		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);						// �����������
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

	Swap(&php->arr[0], &php->arr[php->size-1]);				// �Ѷ�Ԫ�ظ���βԪ�ػ���(��βԪ����size-1)��size-1���Ѷ����µ���
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

