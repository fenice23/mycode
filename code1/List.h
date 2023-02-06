#pragma once
#include "common.h"
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
} LTNode;
LTNode* ListInit();
void ListInit(LTNode** pphead);
void ListPrintO(LTNode* phead);
void ListPrintR(LTNode* phead);
void ListPushBack(LTNode* phead, LTDataType x);
void ListPushFront(LTNode* phead, LTDataType x);
void ListPopBack(LTNode* phead);
void ListPopFront(LTNode* phead);
LTNode* ListFind(LTNode* phead, LTDataType k);
void ListInsert(LTNode* pos, LTDataType x);
void ListErase(LTNode* pos);
void ListDestroy(LTNode** pphead);