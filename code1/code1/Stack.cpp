#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
void StackInit(ST* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		int newCapacity = ((ps->_capacity == 0) ? DEFAULT_STACK_CAPACITY : MULTIPLE * ps->_capacity);
		ps->_capacity = newCapacity;
		STDataType* pt = (STDataType*)realloc(ps->_a, ps->_capacity * sizeof(STDataType));
		if (NULL == pt)
		{
			perror("realloc fail");
			free(ps->_a);
			ps->_a = NULL;
			ps->_top = ps->_capacity = 0;
			exit(-1);
		}
		ps->_a = pt;
	}
	ps->_a[ps->_top++] = x;
}
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));//assert(ps->_top > 0);
	ps->_top--;
}
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));//assert(ps->_top > 0);
	return ps->_a[ps->_top - 1];
}
int StackSize(ST* ps)
{
	assert(ps);
	return ps->_top;
}
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->_top == 0;
}