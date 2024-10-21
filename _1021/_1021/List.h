#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int Datatype;

typedef struct ListNode {

	Datatype Data;
	struct ListNode* next;
	struct ListNode* perv;

}LT;



LT* LTInit();

void print(LT* phead);

void LTPustBack(LT* phead, Datatype x);

void LTPustFront(LT* phead, Datatype x);

void LTPopBack(LT* phead);

void LTPopFront(LT* phead);

bool Empty(LT* phead);

LT* LTFind(LT* phead, Datatype x);

void LTInsert(LT* phead, LT* pos,Datatype x);

void LTErase(LT* phead, LT* pos);

//void DesTroy(LT** pphead);					// Ϊ�˱��ֽӿ�һ���ԣ�����Ŀ�����еĴ�����ñ���һ�£����������ʹ��һ��ָ��
												// ���ö���ָ��ı䲻��ʵ�Σ��ں������ú���Ҫ�ֶ���ʵ����ΪNULL;
void DesTroy(LT* phead);