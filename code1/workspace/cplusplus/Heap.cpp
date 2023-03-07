#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
static void MySwap(HPDataType* p1, HPDataType* p2)
{
	assert(p1 && p2);
	HPDataType t = *p1;
	*p1 = *p2;
	*p2 = t;
}
static void AdjustDown(HPDataType* p, int n, int root)//���µ����㷨ʱ�临�Ӷ�O(logn)
{
	assert(p);//��С��	ǰ��������������С��
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{		//С��Խ��
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
	//�����
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
	//��С��	�ӵ�����һ����Ҷ�ӽڵ㿪ʼ����		����ʱ�临�Ӷ�O(n)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)	AdjustDown(php->_a, php->_size, i);
}
void HeapDestroy(Heap* php)
{
	assert(php);
	if (php->_a)	free(php->_a);
	php->_a = nullptr;
	php->_size = php->_capacity = 0;
}
static void AdjustUp(HPDataType* p, int n, int child)
{
	assert(p);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (p[parent] > p[child])
		{
			MySwap(p + parent, p + child);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapPush(Heap* php, HPDataType x)
{
	assert(php);
	if (php->_capacity == php->_size)
	{
		php->_capacity *= 2;
		HPDataType* pt = (HPDataType*)realloc(php->_a, php->_capacity * sizeof(HPDataType));
		if (!pt)
		{
			perror("realloc fail");
			free(php->_a);
			php->_a = NULL;
			php->_capacity = php->_size = 0;
			exit(errno);
		}
		php->_a = pt;
	}
	php->_a[php->_size++] = x;
	AdjustUp(php->_a, php->_size, php->_size - 1);
}
bool HeapEmpty(Heap* php)
{
	assert(php);
	return php->_size == 0;
}
void HeapPop(Heap* php)
{
	assert(php);
	assert(!HeapEmpty(php));
	MySwap(php->_a, php->_a + php->_size - 1);
	php->_size--;
	AdjustDown(php->_a, php->_size, 0);
}
HPDataType HeapTop(Heap* php)
{
	assert(php);
	assert(!HeapEmpty(php));
	return php->_a[0];
}
int HeapSize(Heap* php)
{
	assert(php);
	return php->_size;
}