#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
void QueueInit(Queue* pque)
{
	assert(pque);
	pque->_head = pque->_tail = NULL;
}
void QueueDestroy(Queue* pque)
{
	assert(pque);
	while (pque->_head)
	{
		QueueNode* tmp = pque->_head;
		pque->_head = pque->_head->_next;
		free(tmp);
		tmp = NULL;
	}
	pque->_head = pque->_tail = NULL;
}
void QueuePush(Queue* pque, QueueDataType x)
{
	assert(pque);
	QueueNode* newNode = (QueueNode*)malloc(1 * sizeof(QueueNode));
	if (NULL == newNode)
	{
		perror("malloc fail");
		QueueDestroy(pque);//申请内存失败直接退出程序,并且退出之前销毁队列
		exit(-1);
	}
	newNode->_next = NULL;
	newNode->_data = x;
	if (pque->_head == pque->_tail && pque->_head == NULL)
	{
		pque->_head = pque->_tail = newNode;
	}
	else
	{
		pque->_tail->_next = newNode;
		pque->_tail = pque->_tail->_next;
	}
}
void QueuePop(Queue* pque)
{
	assert(pque);
	assert(!QueueEmpty(pque));
	QueueNode* tmp = pque->_head;
	pque->_head = pque->_head->_next;
	free(tmp);
	tmp = NULL;
	if (pque->_head == NULL)
	{
		pque->_tail = NULL;
	}
}
QueueDataType QueueFront(Queue* pque)
{
	assert(pque);
	assert(!QueueEmpty(pque));
	return pque->_head->_data;
}
QueueDataType QueueBack(Queue* pque)
{
	assert(pque);
	assert(!QueueEmpty(pque));
	return pque->_tail->_data;
}
bool QueueEmpty(Queue* pque)
{
	assert(pque);
	return pque->_head == NULL;
}
int QueueSize(Queue* pque)//容易出错
{
	assert(pque);
	QueueNode* pt = pque->_head;
	int r = 0;
	while (pt)
	{
		r++;
		pt = pt->_next;
	}
	return r;
}