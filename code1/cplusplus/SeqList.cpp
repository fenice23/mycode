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
	//assert(ps);
	//CheckCapacity(ps);
	//ps->_a[ps->_size++] = x;
	SeqListInsert(ps, ps->_size, x);
}
void SeqListPopBack(SL* ps)
{
	//assert(ps);
	//if (ps->_size == 0)
	//{
	//	printf("顺序表已空,无法进行尾部删除!\n");
	//	return;
	//}
	//ps->_size--;
	SeqListErase(ps, ps->_size - 1);
}
void SeqListPushFront(SL* ps, SLDataType x)
{
	//assert(ps);
	//CheckCapacity(ps);
	//for (int i = ps->_size - 1; i >= 0; i--)
	//{
	//	ps->_a[i + 1] = ps->_a[i];
	//}
	//ps->_a[0] = x;
	//ps->_size++;
	SeqListInsert(ps, 0, x);
}
void SeqListPopFront(SL* ps)
{
	//assert(ps);
	//if (ps->_size == 0)
	//{
	//	printf("顺序表已空,无法进行头部删除!\n");
	//	return;
	//}
	//for (int i = 0; i < ps->_size - 1; i++)
	//{
	//	ps->_a[i] = ps->_a[i + 1];
	//}
	//ps->_size--;
	SeqListErase(ps, 0);
}
int SeqListFind(SL* ps, SLDataType k)
{
	assert(ps);
	for (int i = 0; i < ps->_size; i++)
	{
		if (k == ps->_a[i])
			return i;
	}
	return -1;
}
void SeqListBubbleSort(SL* ps)
{
	assert(ps);
	bool flag = false;
	for (int i = 0; i < ps->_size - 1; i++)
	{
		flag = false;
		for (int j = 0; j < ps->_size - 1 - i; j++)
		{
			if (ps->_a[j] > ps->_a[j + 1])
			{
				flag = true;
				SLDataType t = ps->_a[j];
				ps->_a[j] = ps->_a[j + 1];
				ps->_a[j + 1] = t;
			}
		}
		if (!flag)
			break;
	}
}
int SeqListBinarySearch(SL* ps, SLDataType k)
{
	assert(ps);
	int l = 0, r = ps->_size - 1;
	int midIdx = 0;
	while (l <= r)
	{
		midIdx = (l & r) + ((l ^ r) >> 1);
		if (ps->_a[midIdx] > k)
		{
			r = midIdx - 1;
		}
		else if (ps->_a[midIdx] < k)
		{
			l = midIdx + 1;
		}
		else
		{
			return midIdx;
		}
	}
	return -1;
}
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	//if (pos < 0 || pos > ps->_size)
	//{
	//	printf("按 %d 位置插入非法,无法插入数据.\n", pos);
	//	return;
	//}
	assert(pos >= 0 && pos <= ps->_size);
	CheckCapacity(ps);
	for (int i = ps->_size; i > pos; i--)
	{
		ps->_a[i] = ps->_a[i - 1];
	}
	ps->_a[pos] = x;
	ps->_size++;
}
void SeqListErase(SL* ps, int pos)
{
	assert(ps);
	//if (ps->_size == 0)
	//{
	//	printf("顺序表已空,无法按位置进行删除数据.\n");
	//	return;
	//}
	assert(pos < ps->_size && pos >= 0);
	//if (pos < 0 || pos >= ps->_size)
	//{
	//	printf("按 %d 位置插入非法,无法插入数据.\n", pos);
	//	return;
	//}
	for (int i = pos; i < ps->_size - 1; i++)
	{
		ps->_a[i] = ps->_a[i + 1];
	}
	ps->_size--;
}