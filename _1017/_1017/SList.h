#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>



typedef int TypeData;

typedef struct SListNode
{
	TypeData data;
	struct SListNode* next;
}SL;



void print(SL* phead);

void SLPushBack(SL** pphead, TypeData x);

void SLPushFront(SL** pphead, TypeData x);

void SLPopBack(SL** pphead);

void SLPopFront(SL** pphead);

SL* SLFind(SL* pphead, TypeData x);

void SLInsert(SL** pphead, SL* pos, TypeData x);

void SLInsertAfter(SL* pos, TypeData x);

void SLErase(SL** pphead, SL* pos);

void SLEraseAfter(SL* pos);

void SLDestroy(SL** pphead);