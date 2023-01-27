#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#include "common.h"
//#define N 100
//typedef int SLDataType;
//typedef struct SeqList//¾²Ì¬Ë³Ðò±í
//{
//	SLDataType a[N];
//	int size;
//} SL;
#define DEFAULT_SEQLIST_CAPACITY 8
#define MULTIPLE 2
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* _a;
	int _size;
	int _capacity;
} SL;
void SeqListInit(SL* ps);
void SeqListDestroy(SL* ps);
void SeqListPrint(SL* ps);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);
#endif//!__SEQLIST_H__