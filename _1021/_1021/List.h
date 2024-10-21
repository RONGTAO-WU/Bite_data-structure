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

//void DesTroy(LT** pphead);					// 为了保持接口一致性（即项目中所有的传参最好保持一致），这里最好使用一级指针
												// 不用二级指针改变不了实参，在函数调用后需要手动将实参置为NULL;
void DesTroy(LT* phead);