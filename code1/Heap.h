#pragma once
#include "common.h"
typedef int HPDataType;
typedef struct _Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
} Heap;
void HeapInit(Heap* php, HPDataType* p, int n);
void HeapDestroy(Heap* php);
void HeapPush(Heap* php, HPDataType x);
void HeapPop(Heap* php);
HPDataType HeapTop(Heap* php);
bool HeapEmpty(Heap* php);
int HeapSize(Heap* php);