#pragma once
#include "common.h"
typedef int QueueDataType;
typedef struct _QueueNode
{
	QueueDataType _data;
	struct _QueueNode* _next;
} QueueNode;
typedef struct _Queue
{
	QueueNode* _head;
	QueueNode* _tail;
} Queue;
void QueueInit(Queue* pque);
void QueueDestroy(Queue* pque);
void QueuePush(Queue* pque, QueueDataType x);
void QueuePop(Queue* pque);
QueueDataType QueueFront(Queue* pque);
QueueDataType QueueBack(Queue* pque);
int QueueSize(Queue* pque);
bool QueueEmpty(Queue* pque);