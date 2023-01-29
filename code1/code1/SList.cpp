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