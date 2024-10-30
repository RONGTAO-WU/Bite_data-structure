#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int HPDatatype;

typedef struct Head 
{

	HPDatatype* arr;									// ����
	int size;											// ��Ч����
	int capacity;										// ����

}HP;



void Init(HP* php);
void Destroy(HP* php);

void push(HP* php, HPDatatype x);						// ���в�������
void pop(HP* php);										// ɾ���Ѷ�����

bool Empty(HP* php);

int size(HP* php);