#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
void SeqListInit(SL* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_size = 0;
}
void SeqListDestroy(SL* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = 0;
	ps->_size = 0;
}
void SeqListPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->_size; i++)
	{
		printf("%d ", ps->_a[i]);
	}
	printf("\n");
}
static void CheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->_size == ps->_capacity)
	{
		int newCapacity = (ps->_capacity == 0) ? DEFAULT_SEQLIST_CAPACITY : MULTIPLE * ps->_capacity;
		SLDataType * pt = (SLDataType*)realloc(ps->_a, newCapacity * sizeof(SLDataType));
		if (NULL == pt)
		{
			perror("realloc fail!");
			free(ps->_a);
			ps->_a = NULL;
			ps->_capacity = 0;
			ps->_size = 0;
			exit(-1);
		}
		ps->_a = pt;
		ps->_capacity = newCapacity;
	}
}
void SeqListPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->_a[ps->_size++] = x;
}
void SeqListPopBack(SL* ps)
{
	assert(ps);
	if (ps->_size == 0)
	{
		printf("顺序表已空,无法进行尾部删除!\n");
		return;
	}
	ps->_size--;
}
void SeqListPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	for (int i = ps->_size - 1; i >= 0; i--)
	{
		ps->_a[i + 1] = ps->_a[i];
	}
	ps->_a[0] = x;
	ps->_size++;
}
void SeqListPopFront(SL* ps)
{
	assert(ps);
	if (ps->_size == 0)
	{
		printf("顺序表已空,无法进行头部删除!\n");
		return;
	}
	for (int i = 0; i < ps->_size - 1; i++)
	{
		ps->_a[i] = ps->_a[i + 1];
	}
	ps->_size--;
}