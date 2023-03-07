#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
void SListInit(SLTNode** pphead)
{
	assert(pphead);
	*pphead = NULL;
}
void SListPrint(SLTNode* phead)
{
	while (phead)
	{
		printf("%d->", phead->_data);
		phead = phead->_next;
	}
	printf("NULL\n");
}
static SLTNode* BuyNewNode(SLTDataType x)
{
	SLTNode* newNode = (SLTNode*)malloc(1 * sizeof(SLTNode));
	if (NULL == newNode)
	{
		perror("newNode malloc fail");
		exit(-1);
	}
	newNode->_data = x;
	newNode->_next = NULL;
	return newNode;
}
void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* tail = *pphead;
	SLTNode* newNode = BuyNewNode(x);
	if (!tail)
	{
		*pphead = newNode;
	}
	else
	{
		while (tail->_next)
		{
			tail = tail->_next;
		}
		tail->_next = newNode;
	}
}
void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newNode = BuyNewNode(x);
	newNode->_next = *pphead;
	*pphead = newNode;
}
void SListPopBack(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* phead = *pphead;
	if (!phead)
	{
		printf("单链表已空,无法进行尾删!\n");
	}
	else if (!phead->_next)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		while (phead->_next->_next)
		{
			phead = phead->_next;
		}
		free(phead->_next);
		phead->_next = NULL;
	}
}
void SListPopFront(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* phead = *pphead;
	if (!phead)
	{
		printf("单链表已空,无法进行头删!\n");
	}
	else
	{
		*pphead = (*pphead)->_next;
		free(phead);
		phead = NULL;
	}
}
void SListDestroy(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* phead = *pphead;
	while (phead)
	{
		SLTNode* pt = phead->_next;
		free(phead);
		phead = pt;
	}
	*pphead = NULL;
}
SLTNode* SListFind(SLTNode* phead, SLTDataType k)
{
	while (phead)
	{
		if (phead->_data == k)
			return phead;
		else
			phead = phead->_next;
	}
	return NULL;
}
void SListInsert(SLTNode** pphead, SLTNode* pfind, SLTDataType x)
{
	assert(pphead && pfind);
	SLTNode* newNode = BuyNewNode(x);
	SLTNode* curr = *pphead;
	if (curr == pfind)
	{
		*pphead = newNode;
		newNode->_next = curr;
	}
	else
	{
		while (curr->_next != pfind)
		{
			curr = curr->_next;
		}
		curr->_next = newNode;
		newNode->_next = pfind;
	}
}
void SListInsertAfter(SLTNode* pfind, SLTDataType x)
{
	assert(pfind);
	SLTNode* newNode = BuyNewNode(x);
	newNode->_next = pfind->_next;
	pfind->_next = newNode;
}
void SListErase(SLTNode** pphead, SLTNode* pfind)
{
	assert(pphead && pfind);
	SLTNode* phead = *pphead;
	if (*pphead == pfind)
	{
		*pphead = (*pphead)->_next;
		free(phead);
		phead = NULL;
	}
	else
	{
		while (phead->_next != pfind)
		{
			phead = phead->_next;
		}
		phead->_next = pfind->_next;
		free(pfind);
		pfind = NULL;
	}
}
void SListEraseAfter(SLTNode* pfind)
{
	assert(pfind && pfind->_next);
	SLTNode* pt = pfind->_next;
	pfind->_next = pfind->_next->_next;
	free(pt);
	pt = NULL;
}