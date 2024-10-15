#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>



typedef int SLDatatype;

typedef struct SeqList
{
	SLDatatype* arr;			// 非固定类型数组
	int size;					// 数组长度
	int capacity;				// 有效数据

}SL;


void SLInit(SL *ps);
void SLPushBack(SL* ps, SLDatatype x);
void SLPushFront(SL* ps, SLDatatype x);
void SLPopBack(SL* ps);
void SLPopFront(SL* ps);
void SLInsert(SL* ps, int pos, SLDatatype x);
void SLErase(SL* ps, int pos);
void SLFind(SL* ps, SLDatatype x);
void SLDesTroy(SL* ps);
void print(SL* ps);