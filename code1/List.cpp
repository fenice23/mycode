#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
static LTNode* BuyNewListNode(LTDataType x)
{
	LTNode* newNode = (LTNode*)malloc(1 * sizeof(LTNode));
	if (NULL == newNode)
	{
		perror("malloc fail");
		exit(-1);
	}
	newNode->_next = newNode->_prev = NULL;
	newNode->_data = x;
	return newNode;
}
void ListInit(LTNode** pphead)
{
	assert(pphead);
	*pphead = BuyNewListNode(88888);
	(*pphead)->_next = *pphead;
	(*pphead)->_prev = *pphead;
}
LTNode* ListInit()
{
	LTNode* phead = BuyNewListNode(88888);
	phead->_next = phead;
	phead->_prev = phead;
	return phead;
}
void ListPrintO(LTNode* phead)
{
	assert(phead);
	printf("ÕýÐò´òÓ¡:");
	LTNode* p = phead->_next;
	while (p != phead)
	{
		printf("%d ", p->_data);
		p = p->_next;
	}
	printf("\n");
}
void ListPrintR(LTNode* phead)
{
	assert(phead);
	printf("ÄæÐò´òÓ¡:");
	LTNode* p = phead->_prev;
	while (p != phead)
	{
		printf("%d ", p->_data);
		p = p->_prev;
	}
	printf("\n");
}
void ListPushBack(LTNode* phead, LTDataType x)
{
	//assert(phead);
	//LTNode* newNode = BuyNewListNode(x);
	//phead->_prev->_next = newNode;
	//newNode->_prev = phead->_prev;
	//phead->_prev = newNode;
	//newNode->_next = phead;
	assert(phead);
	ListInsert(phead, x);
}
void ListPushFront(LTNode* phead, LTDataType x)
{
	//assert(phead);
	//LTNode* newNode = BuyNewListNode(x);
	//LTNode* next = phead->_next;
	//newNode->_next = next;
	//next->_prev = newNode;
	//phead->_next = newNode;
	//newNode->_prev = phead;
	assert(phead);
	ListInsert(phead->_next, x);
}
void ListPopBack(LTNode* phead)
{
	//assert(phead);
	//assert(phead->_prev != phead);
	//LTNode* tmp = phead->_prev;
	//tmp->_prev->_next = phead;
	//phead->_prev = tmp->_prev;
	//free(tmp);
	//tmp = NULL;
	assert(phead);
	assert(phead->_prev != phead);
	ListErase(phead->_prev);
}
void ListPopFront(LTNode* phead)
{
	//assert(phead);
	//assert(phead->_prev != phead);
	//LTNode* tmp = phead->_next;
	//phead->_next = tmp->_next;
	//tmp->_next->_prev = phead;
	//free(tmp);
	//tmp = NULL;
	assert(phead);
	assert(phead->_prev != phead);
	ListErase(phead->_next);
}
LTNode* ListFind(LTNode* phead, LTDataType k)
{
	assert(phead);
	LTNode* cur = phead->_next;
	while (cur != phead)
	{
		if (k == cur->_data)
			return cur;
		else
			cur = cur->_next;
	}
	return NULL;
}
void ListInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newNode = BuyNewListNode(x);
	LTNode* prev = pos->_prev;
	prev->_next = newNode;
	newNode->_next = pos;
	pos->_prev = newNode;
	newNode->_prev = prev;
}
void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* prev = pos->_prev;
	prev->_next = pos->_next;
	pos->_next->_prev = prev;
	free(pos);
	pos = NULL;
}
void ListDestroy(LTNode** pphead)
{
	assert(pphead);
	LTNode* phead = *pphead;
	LTNode* tmp = NULL;
	phead->_prev->_next = NULL;
	while (phead)
	{
		tmp = phead->_next;
		free(phead);
		phead = tmp;
	}
	*pphead = NULL;
}