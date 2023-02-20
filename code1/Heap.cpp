#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
static void MySwap(HPDataType* p1, HPDataType* p2)
{
	assert(p1 && p2);
	HPDataType t = *p1;
	*p1 = *p2;
	*p2 = t;
}
static void AdjustDown(HPDataType* p, int n, int root)//向下调整算法时间复杂度O(logn)
{
	assert(p);//建小堆	前提左右子树都是小堆
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{		//小心越界
		if ((child + 1 < n) && (p[child + 1] < p[child]))
		{
			child++;
		}
		if (p[child] < p[parent])
		{
			MySwap(p + child, p + parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
static void AdjustDown1(HPDataType* p, int n, int root)
{
	//建大堆
	assert(p);
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{
		if ((child + 1 < n) && (p[child + 1] > p[child]))
		{
			child++;
		}
		if (p[child] > p[parent])
		{
			MySwap(p + child, p + parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapInit(Heap* php, HPDataType* p, int n)
{
	assert(php && p);
	php->_a = (HPDataType*)malloc(n * sizeof(HPDataType));
	if (!php->_a)
	{
		perror("malloc fail");
		exit(errno);
	}
	php->_capacity = php->_size = n;
	memmove(php->_a, p, n * sizeof(HPDataType));
	//建小堆	从倒数第一个非叶子节点开始建堆		建堆时间复杂度O(n)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)	AdjustDown(php->_a, php->_size, i);
}
void HeapDestroy(Heap* php)
{
	assert(php);
	if (php->_a)	free(php->_a);
	php->_a = nullptr;
	php->_size = php->_capacity = 0;
}