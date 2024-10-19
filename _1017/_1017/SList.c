#define _CRT_SECURE_NO_WARNINGS

#include"SList.h"


void print(SL* phead)
{
	SL* Pcur = phead;
	while (Pcur)
	{
		printf("%d-> ", Pcur->data);
		Pcur = Pcur->next;
	}
	printf("NULL\n");
}

SL* SLNode(TypeData x)											// 动态开辟空间
{
	SL* newnode = (SL*)malloc(sizeof(SL));
	if (newnode == NULL)
	{
		perror("malloc");
		return -1;
	}

	newnode->data = x;
	newnode->next = NULL;

	return newnode;

}

void SLPushBack(SL** pphead, TypeData x)						// 尾插（开辟空间，找尾，空链表的情况）
{
	assert(*pphead);

	SL* newnode = SLNode(x);									// 对新节点开辟空间

	if (newnode == -1)
		return -1;

	if (*pphead == NULL)										// 链表为空的情况
	{
		*pphead = newnode;
	}
	else 
	{															// 链表不为空，找尾
		SL* ptail = *pphead;									// 对首地址进行一个拷贝，然后让它往后找尾
		while (ptail->next)									
		{
			ptail = ptail->next;
		}
		ptail->next = newnode;
		newnode->next = NULL;
	}



}

void SLPushFront(SL** pphead, TypeData x)						// 头插
{
	assert(*pphead);

	SL* newnode = SLNode(x);									// 对新节点开辟空间

	newnode->next = *pphead;									// 重定向
	*pphead = newnode;											// 将新节点置尾头部

}

void SLPopBack(SL** pphead)										// 尾删
{
	assert(*pphead);

	

	if ((*pphead)->next == NULL)								// 处理一个节点的特殊情况
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SL* ptail = *pphead;
		SL* prev = NULL;										// 用另一个指针来定位探路指针的前一个节点

		while (ptail->next)										// 找尾（不能用->next->next来解决，因为可能存在只有一个节点的情况）
		{
			prev = ptail;
			ptail = ptail->next;
		}
		prev->next = NULL;
		free(ptail);
		ptail = NULL;
	}

}

void SLPopFront(SL** pphead)									// 头删
{
	assert(*pphead);

	SL* prev = (*pphead)->next;									// 引入一个第三方指针						
	
	free(*pphead);												// 先释放在赋值
	*pphead = NULL;

	*pphead = prev;

}

SL* SLFind(SL* pphead, TypeData x)
{
	assert(pphead);

	SL* ptail = pphead;

	while (ptail)
	{
		if (ptail->data == x)
		{
			return ptail;
		}
		ptail = ptail->next;
	}

	return NULL;

}

void SLInsert(SL** pphead, SL* pos, TypeData x)					// 在指定节点位置之前插入数据
{
	assert(*pphead && pos);										// 找不到直接

	SL* newnode = SLNode(x);


	if (*pphead == pos)											// pos正好是头节点（这里用头插也可以实现）
	{
		newnode->next = pos;
		*pphead = newnode;
	}
	else
	{ 	
		SL* prev = *pphead;

		while (prev->next != pos)
		{
			prev = prev->next;
		}
		
		newnode->next = pos;
		prev->next = newnode;
	}


}

void SLInsertAfter(SL* pos, TypeData x)							// 在指定节点位置之后插入数据
{																// 可以直接通过pos往后访问插入
	assert(pos);

	SL* newnode = SLNode(x);
	
	newnode->next = pos->next;
	pos->next = newnode;
}

void SLErase(SL** pphead, SL* pos)								// 删除pos节点
{
	assert(*pphead && pos);

	SL* prev = *pphead;

	if (*pphead == pos)
	{
		*pphead = pos->next;
	}
	else
	{
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
	}
	free(pos);
	pos = NULL;


}

void SLEraseAfter(SL* pos)										// 删除pos节点之后的节点
{
	assert(pos);

	if (pos->next != NULL)
	{
		SL* ret = pos->next;
		pos->next = ret->next;
		free(ret);
		ret = NULL;
	}


}

void SLDestroy(SL** pphead)										// 销毁链表
{
	assert(*pphead);

	SL* prev = *pphead;

	while (prev->next != NULL)
	{
		prev = prev->next;
		free(*pphead);
		*pphead = prev;
	}
	free(prev);
	prev = NULL;
	*pphead = NULL;


}
