#pragma once
#include "common.h"
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType _data;
	struct SListNode* _next;
} SLTNode;
void SListInit(SLTNode** pphead);
void SListDestroy(SLTNode** pphead);
void SListPrint(SLTNode* phead);
void SListPushBack(SLTNode** pphead, SLTDataType x);
void SListPushFront(SLTNode** pphead, SLTDataType x);
void SListPopBack(SLTNode** pphead);
void SListPopFront(SLTNode** pphead);
SLTNode* SListFind(SLTNode* phead, SLTDataType k);
void SListInsert(SLTNode** pphead, SLTNode* pfind, SLTDataType x);
void SListInsertAfter(SLTNode* pfind, SLTDataType x);
void SListErase(SLTNode** pphead, SLTNode* pfind);
void SListEraseAfter(SLTNode* pfind);