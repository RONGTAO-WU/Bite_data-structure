#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int HPDatatype;

typedef struct Head 
{

	HPDatatype* arr;									// 数组
	int size;											// 有效数据
	int capacity;										// 容量

}HP;



void Init(HP* php);
void Destroy(HP* php);

void push(HP* php, HPDatatype x);						// 堆中插入数据
void pop(HP* php);										// 删除堆顶数据

bool Empty(HP* php);

int size(HP* php);