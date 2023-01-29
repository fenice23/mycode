#pragma once
#include "common.h"
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
} SLTNode;
void SListInit(SLTNode** pphead);
void SListPrint(SLTNode* phead);
void SListPushBack(SLTNode** pphead, SLTDataType x);