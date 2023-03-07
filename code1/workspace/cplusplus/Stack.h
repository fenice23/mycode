#pragma once
#include "common.h"
#define DEFAULT_STACK_CAPACITY 4
#define MULTIPLE 2
typedef int STDataType;
typedef struct _Stack
{
	STDataType* _a;
	int _top;
	int _capacity;
} ST;
void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps, STDataType x);
void StackPop(ST* ps);
STDataType StackTop(ST* ps);
int StackSize(ST* ps);
bool StackEmpty(ST* ps);