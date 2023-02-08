#define _CRT_SECURE_NO_WARNINGS 1

//#include "common.h"//ds-code
#if 0
//void func1(int n)//O(n^n)
//{
//	int count = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			++count;
//		}
//	}
//	for (int k = 0; k < 2 * n; k++)
//	{
//		++count;
//	}
//	int m = 10;
//	while (m--)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}
//void func2(int n)//O(n)
//{
//	int count = 0;
//	for (int k = 0; k < 2 * n; k++)
//	{
//		++count;
//	}
//	int m = 10;
//	while(m--)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}
//void func3(int n, int m)//未知m与n的关系:O(m + n)
//{						//m和n差不多:O(m)或者O(n)
//						//m远大于n:O(m)
//						//n远大于m:O(n)
//	int count = 0;
//	for (int k = 0; k < m; k++)
//	{
//		++count;
//	}
//	for (int k = 0; k < n; k++)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}
//void func4(int n)//O(1)
//{
//	int count = 0;
//	for (int k = 0; k < 100; k++)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}
//const char* strchr(const char* str, int character);//O(n)
//const char* MyStrchr(const char* str, int ch)
//{
//	assert(str);
//	while (*str)
//	{
//		if (*str == ch)
//			return str;
//		str++;
//	}
//	return nullptr;
//}
//void bubblesort(int* p, int n)//O((n - 1) * n / 2)--->O(n^2)	O(1)
//{
//	assert(p);
//	bool flag = false;
//	for (int i = 0; i < n - 1; i++)
//	{
//		flag = false;
//		for (int j = 0; j < n - 1 - i; j++)
//		{
//			if (p[j] < p[j + 1])
//			{
//				int t = p[j];
//				p[j] = p[j + 1];
//				p[j + 1] = t;
//				flag = true;
//			}
//		}
//		if (!flag)
//			break;
//	}
//}
//int binarysearch(int* p, int n, int k)//O(logn)	O(1)
//{
//	assert(p);
//	int l = 0;
//	int r = n - 1;
//	int mid = 0;
//	while (l <= r)
//	{
//		mid = (l & r) + ((l ^ r) >> 1);
//		if (p[mid] == k)
//			return mid;
//		else if (p[mid] > k)
//			r = mid - 1;
//		else
//			l = mid + 1;
//	}
//	return -1;
//}
//long long fac(size_t n)//O(n)	O(n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return fac(n - 1) * n;
//}
//long long fib(size_t n)//O(2^n)	O(n)
//{
//	if (n <= 1)
//		return n;
//	else
//		return fib(n - 1) + fib(n - 2);
//}
//long long* fib(size_t n)//O(n)	O(n)
//{
//	long long* fibArr = (long long*)malloc((n + 1) * sizeof(long long));
//	if (NULL == fibArr)
//	{
//		perror("fun fib fibArr malloc error");
//		return NULL;
//	}
//	fibArr[0] = 0;
//	if (n == 0)
//		return fibArr;
//	fibArr[1] = 1ll;
//	for (size_t i = 2; i < n + 1; i++)
//	{
//		fibArr[i] = fibArr[i - 1] + fibArr[i - 2];
//	}
//	return fibArr;
//}
//int main()//时间是一去不复返的,要累计,空间是可以重复利用的,不累计
//{
//	//func1(10);
//	//func2(100);
//	//func3(10, 20);
//	//func4(101110);
//	//int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//	//bubblesort(arr, (int)(sizeof(arr) / sizeof(arr[0])));
//	//std::cout << fac(10) << std::endl;
//	//std::cout << fib(100) << std::endl;
//	//long long r = fib(2)[2];
//	//std::cout << r << std::endl;
//	return 0;
//}
//#include "SeqList.h"//SeqList
//void TestSeqList1()
//{
//	SL msl;
//	SeqListInit(&msl);
//	SeqListPushBack(&msl, 1);
//	SeqListPushBack(&msl, 2);
//	SeqListPushBack(&msl, 3);
//	SeqListPushBack(&msl, 4);
//	SeqListPushBack(&msl, 4);
//	SeqListPushBack(&msl, 4);
//	SeqListPushBack(&msl, 4);
//	SeqListPushBack(&msl, 4);
//	SeqListPushBack(&msl, 5);
//	SeqListPrint(&msl);
//	SeqListPopBack(&msl);
//	SeqListPopBack(&msl);
//	SeqListPopBack(&msl);
//	SeqListPopBack(&msl);
//	SeqListPrint(&msl);
//	SeqListPopBack(&msl);
//	SeqListPrint(&msl);
//	SeqListPopBack(&msl);
//	SeqListPrint(&msl);
//	SeqListDestroy(&msl);
//}
//void TestSeqList2()
//{
//	SL msl;
//	SeqListInit(&msl);
//	SeqListPushBack(&msl, 1);
//	SeqListPushBack(&msl, 12);
//	SeqListPushBack(&msl, 13);
//	SeqListPushBack(&msl, 14);
//	SeqListPrint(&msl);
//	SeqListPushFront(&msl, 20);
//	SeqListPushFront(&msl, 21);
//	SeqListPushFront(&msl, 22);
//	SeqListPushFront(&msl, 23);
//	SeqListPushFront(&msl, 244);
//	SeqListPrint(&msl);
//	SeqListPopFront(&msl);
//	SeqListPopFront(&msl);
//	SeqListPrint(&msl);
//	SeqListPopFront(&msl);
//	SeqListPopFront(&msl);
//	SeqListPopFront(&msl);
//	SeqListPopFront(&msl);
//	SeqListPrint(&msl);
//	SeqListPopFront(&msl);
//	SeqListPopFront(&msl);
//	SeqListPopFront(&msl);
//	SeqListPopFront(&msl);
//	SeqListPopFront(&msl);
//	SeqListPopFront(&msl);
//	SeqListPrint(&msl);
//	SeqListDestroy(&msl);
//}
//void TestSeqList3()
//{
//	SL msl;
//	SeqListInit(&msl);
//	SeqListPushBack(&msl, 12);
//	SeqListPushBack(&msl, 21);
//	SeqListPushBack(&msl, 31);
//	SeqListPushBack(&msl, 51);
//	SeqListPrint(&msl);
//	SeqListInsert(&msl, 2, 2);
//	SeqListPrint(&msl);
//	SeqListInsert(&msl, 0, 11);
//	SeqListPrint(&msl);
//	SeqListInsert(&msl, msl._size, 333);
//	SeqListPrint(&msl);
//	int pos = SeqListFind(&msl, 21);
//	if (-1 != pos)
//	{
//		SeqListInsert(&msl, pos, 2222);
//	}
//	SeqListPrint(&msl);
//	SeqListDestroy(&msl);
//}
//void TestSeqList4()
//{
//	SL msl;
//	SeqListInit(&msl);
//	SeqListPushBack(&msl, 4);
//	SeqListPushBack(&msl, 12);
//	SeqListPushBack(&msl, 13);
//	SeqListPushBack(&msl, 14);
//	SeqListPrint(&msl);
//	SeqListPushFront(&msl, 5);
//	SeqListPushFront(&msl, 12);
//	SeqListPushFront(&msl, 13);
//	SeqListPushFront(&msl, 14);
//	SeqListPrint(&msl);
//	SeqListErase(&msl, 1);
//	SeqListPrint(&msl);
//	SeqListPopFront(&msl);
//	SeqListPopFront(&msl);
//	SeqListPrint(&msl);
//	SeqListPopBack(&msl);
//	SeqListPopBack(&msl);
//	SeqListPrint(&msl);
//	SeqListBubbleSort(&msl);
//	SeqListPrint(&msl);
//	int pos = SeqListBinarySearch(&msl, 5);
//	if (-1 != pos)
//	{
//		SeqListErase(&msl, pos);
//	}
//	SeqListPrint(&msl);
//	SeqListDestroy(&msl);
//}
//int main()
//{
//	//TestSeqList1();
//	//TestSeqList2();
//	//TestSeqList3();
//	//TestSeqList4();
//	return 0;
//}
//int main()
//{
//	int* p1 = (int*)malloc(10 * sizeof(int));
//	int* p2 = (int*)realloc(p1, 50 * sizeof(int));
//	return 0;
//}
//#include "SList.h"//SList
//void TestSList1()
//{
//	SLTNode* phead;
//	SListInit(&phead);
//	SListPrint(phead);
//	SListPushBack(&phead, 1);
//	SListPrint(phead);
//	SListPushBack(&phead, 2);
//	SListPrint(phead);
//	SListPushBack(&phead, 3);
//	SListPrint(phead);
//	SListPushFront(&phead, 1);
//	SListPrint(phead);
//	SListPushFront(&phead, 2);
//	SListPrint(phead);
//	SListPushFront(&phead, 3);
//	SListPrint(phead);
//	SListPopFront(&phead);
//	SListPrint(phead);
//	SListPopFront(&phead);
//	SListPrint(phead);
//	SListPopFront(&phead);
//	SListPrint(phead);
//	SListPopFront(&phead);
//	SListPrint(phead);
//	SListPopFront(&phead);
//	SListPrint(phead);
//	SListPopFront(&phead);
//	SListPrint(phead);
//	SListPopFront(&phead);
//	SListPrint(phead);
//	//SListPopBack(&phead);
//	//SListPrint(phead);
//	//SListPopBack(&phead);
//	//SListPrint(phead);
//	//SListPopBack(&phead);
//	//SListPrint(phead);
//	//SListPopBack(&phead);
//	//SListPrint(phead);
//	//SListPopBack(&phead);
//	//SListPrint(phead);
//	//SListPopBack(&phead);
//	//SListPrint(phead);
//	//SListPopBack(&phead);
//	//SListPrint(phead);
//	SListDestroy(&phead);
//	//std::cout << phead;
//}
//void TestSList2()
//{
//	SLTNode* phead;
//	SListInit(&phead);
//	SListPushFront(&phead, 1);
//	SListPrint(phead);
//	SListPushFront(&phead, 2);
//	SListPrint(phead);
//	SListPushFront(&phead, 3);
//	SListPrint(phead);
//	SListPopFront(&phead);
//	SListPrint(phead);
//	SListPopFront(&phead);
//	SListPrint(phead);
//	SListPopFront(&phead);
//	SListPrint(phead);
//	SListPopFront(&phead);
//	SListPrint(phead);
//	//SListPopBack(&phead);
//	//SListPrint(phead);
//	//SListPopBack(&phead);
//	//SListPrint(phead);
//	//SListPopBack(&phead);
//	//SListPrint(phead);
//	//SListPopBack(&phead);
//	//SListPrint(phead);
//	//SListPopBack(&phead);
//	//SListPrint(phead);
//	//SListPopBack(&phead);
//	//SListPrint(phead);
//	//SListPopBack(&phead);
//	//SListPrint(phead);
//	SListDestroy(&phead);
//}
//void TestSList3()
//{
//	SLTNode* phead;
//	SListInit(&phead);
//	SListPushFront(&phead, 1);
//	SListPushFront(&phead, 2);
//	SListPushFront(&phead, 3);
//	SListPushFront(&phead, 2);
//	SListPushFront(&phead, 4);
//	SListPushFront(&phead, 2);
//	SListPushFront(&phead, 2);
//	SListPushFront(&phead, 4);
//	SListPushFront(&phead, 2);
//	SListPrint(phead);
//	SLTNode* pfind = SListFind(phead, 2);
//	int c = 0;
//	while (pfind)//多个重复元素进行查找
//	{
//		printf("第%d个2, %p--->%d\n", ++c, pfind, pfind->_data);
//		pfind = SListFind(pfind->_next, 2);
//	}
//	pfind = SListFind(phead, 3);
//	if (pfind)
//	{
//		pfind->_data = 30;
//	}
//	SListPrint(phead);
//	SListDestroy(&phead);
//}
//void TestSList4()
//{
//	SLTNode* phead;
//	SListInit(&phead);
//	SListPushFront(&phead, 1);
//	SListPushFront(&phead, 2);
//	SListPushFront(&phead, 3);
//	SListPushFront(&phead, 4);
//	SListPrint(phead);
//	SLTNode* pfind = SListFind(phead, 3);
//	if (pfind)
//	{
//		SListInsert(&phead, pfind, 30);
//	}
//	SListPrint(phead);
//	pfind = SListFind(phead, 4);
//	if (pfind)
//	{
//		SListInsert(&phead, pfind, 40);
//	}
//	SListPrint(phead);
//	SListDestroy(&phead);
//}
//void Test()
//{
//	//TestSList1();
//	//TestSList2();
//	//TestSList3();
//	//TestSList4();
//}
//int main()
//{
//	Test();
//	return 0;
//}
//#include "List.h"//List
//void TestList1()
//{
//	//LTNode* phead = ListInit();
//	LTNode* phead;
//	ListInit(&phead);
//	ListPushBack(phead, 1);
//	ListPushBack(phead, 2);
//	ListPushBack(phead, 3);
//	ListPushBack(phead, 4);
//	ListPrintO(phead);
//	ListPrintR(phead);
//	ListDestroy(&phead);
//}
//void TestList2()
//{
//	LTNode* phead;
//	ListInit(&phead);
//	//ListPushFront(phead, 1);
//	//ListPushFront(phead, 2);
//	//ListPushFront(phead, 3);
//	//ListPushFront(phead, 4);
//	ListPushBack(phead, 1);
//	ListPushBack(phead, 2);
//	ListPushBack(phead, 3);
//	ListPushBack(phead, 4);
//	ListPrintO(phead);
//	//ListPrintR(phead);
//	//ListPopBack(phead);
//	//ListPrintO(phead);
//	//ListPopBack(phead);
//	//ListPrintO(phead);
//	//ListPopBack(phead);
//	//ListPrintO(phead);
//	//ListPopBack(phead);
//	//ListPrintO(phead);
//	//ListPopBack(phead);
//	//ListPrintO(phead);
//
//	ListPopFront(phead);
//	ListPrintO(phead);
//	ListPopFront(phead);
//	ListPrintO(phead);
//	ListPopFront(phead);
//	ListPrintO(phead);
//	ListPopFront(phead);
//	ListPrintO(phead);
//	ListPopFront(phead);
//	ListPrintO(phead);
//
//	ListDestroy(&phead);
//}
//int main()
//{
//	//TestList1();
//	TestList2();
//	return 0;
//}
//#include "Stack.h"//Stack
//void TestStack1()
//{
//	ST st;
//	StackInit(&st);
//	printf("%d\n", StackSize(&st));
//	StackPush(&st, 1);
//	printf("%d\n", StackSize(&st));
//	StackPush(&st, 2);
//	printf("%d\n", StackSize(&st));
//	StackPush(&st, 3);
//	printf("%d\n", StackSize(&st));
//	StackPush(&st, 4);
//	while (!StackEmpty(&st))
//	{
//		printf("%d ", StackTop(&st));
//		StackPop(&st);
//	}
//	printf("%d\n", StackSize(&st));
//	StackDestroy(&st);
//}
//int main()
//{
//	TestStack1();
//	return 0;
//}
//#include "Queue.h"//Queuee
//void TestQueue1()
//{
//	Queue que;
//	QueueInit(&que);
//	printf("%d\n", QueueSize(&que));
//	QueuePush(&que, 1);
//	printf("%d\n", QueueSize(&que));
//	QueuePush(&que, 2);
//	printf("%d ", QueueFront(&que));
//	QueuePop(&que);
//	QueuePush(&que, 3);
//	QueuePush(&que, 4);
//	printf("%d\n", QueueSize(&que));
//	while (!QueueEmpty(&que))
//	{
//		printf("%d ", QueueFront(&que));
//		QueuePop(&que);
//	}
//	QueueDestroy(&que);
//}
//int main()
//{
//	TestQueue1();
//	return 0;
//}
#endif
//#include "common.h"//cpp-code
#if 0
int main()
{
	return 0;
}
#endif
//OJ测试调试
#if 0
//class Node {
//public:
//	int val;
//	Node* next;
//	Node* random;
//	Node(int _val) {
//		val = _val;
//		next = NULL;
//		random = NULL;
//	}
//};
//Node* copyRandomList(Node* head) {
//	if (!head)  return head;
//	auto headCpy = head;
//	while (headCpy) {
//		auto newNode = new Node(headCpy->val);
//		auto next = headCpy->next;
//		newNode->next = next;
//		headCpy->next = newNode;
//		headCpy = next;
//	}
//	headCpy = head;
//	Node* copyHead = head->next;
//	while (headCpy) {
//		if (headCpy->random)
//			copyHead->random = headCpy->random->next;
//		else
//			copyHead->random = nullptr;
//		headCpy = copyHead->next;
//		if (headCpy)
//			copyHead = headCpy->next;
//	}
//	copyHead = head->next;
//	auto copy = copyHead;
//	headCpy = head;
//	while (headCpy) {
//		auto nexth = copy->next;
//		headCpy = headCpy->next = nexth;
//		if (headCpy) {
//			auto nextc = headCpy->next;
//			copy = copy->next = nextc;
//		}
//	}
//	return copyHead;
//}
//int main()
//{
//	Node* n1 = new Node(1);
//	Node* n2 = new Node(2);
//	Node* n3 = new Node(3);
//	Node* n4 = new Node(4);
//	Node* n5 = new Node(5);
//	Node* n6 = new Node(6);
//	Node* n7 = new Node(7);
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = n5;
//	n5->next = n6;
//	n6->next = n7;
//	n7->next = nullptr;
//	n1->random = n4;
//	n2->random = n5;
//	n3->random = n1;
//	n4->random = nullptr;
//	n5->random = n5;
//	n6->random = n3;
//	n7->random = n6;
//	Node* ret = copyRandomList(n1);
//	return 0;
//}
#endif
#include "common.h"//c-code
#if 0
//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//int a = 100;
//int main()
//{
//	//printf("C");
//	//char ch = 'a';
//	//int age = 20;
//	//short num = 10;
//	//float w = 55.5f;
//	//double d = 0.0;
//	//printf("hehe\n");
//	//printf("C lanuage.\n");
//	//printf("%d\n", 100);
//	//printf("%d\n", sizeof(char));
//	//printf("%d\n", sizeof(short));
//	//printf("%d\n", sizeof(int));
//	//printf("%d\n", sizeof(long));
//	//printf("%d\n", sizeof(long long));
//	//printf("%d\n", sizeof(float));
//	//printf("%d\n", sizeof(double));
//	//printf("%d\n", sizeof(long double));
//	//int age = 20;
//	//double w = 75.3;
//	//age = age + 1;
//	//w = w - 10;
//	//printf("%d\n", age);
//	//printf("%lf\n", w);
//	//int a = 10;
//	//printf("%d\n", a);
//	//int a = 0;
//	//int b = 0;
//	//int s = 0;
//	//scanf("%d%d", &a, &b);
//	//s = a + b;
//	//printf("s = %d\n", s);
//	//int a = 9 / 2;
//	//printf("a = %d\n", a);
//	//float aa = 9 / 2;
//	//printf("aa = %f\n", aa);
//	//float b = 9 / 2.0;
//	//printf("b = %f\n", b);
//	//int c = 9 % 2;
//	//printf("c = %d\n", c);
//	//int a = 2;
//	//a = a + 5;
//	//a = 6;
//	//a += 5;
//	//a = a - 3;
//	//a -= 3;
//	//a = a % 3;
//	//a %= 3;
//	//printf("%d\n", a);
//	//int a = 2;
//	//int b = a << 1;
//	//printf("a = %d, b = %d\n", a, b);
//	//int a = 10;
//	//printf("%d\n", !a);
//	//if (a) {}
//	//if (!a) {}
//	//int a = 10;
//	//a = -5;
//	//a = -a;
//	//a = +a;
//	//printf("a = %d\n", a);
//	//int a = 10;
//	//printf("%d\n", sizeof 10);
//	//printf("%d, %d, %d, %d\n", sizeof(int), sizeof(a), sizeof(10), sizeof a);
//	//int arr[10] = { 0 };
//	//printf("%d, %d, %d\n", sizeof(arr), sizeof(int[10]), sizeof(arr[0]));
//	//int sz = (int)(sizeof(arr) / sizeof(arr[0]));
//	//printf("sz = %d\n", sz);
//	//int input = 0;
//	//printf("学习CS:>\n");
//	//printf("是否好好学习?(1/0):>");
//	//scanf("%d", &input);
//	//if (input == 1)
//	//{
//	//	printf("好Offer\n");
//	//}
//	//else
//	//{
//	//	printf("拧螺丝\n");
//	//}
//	//int line = 0;
//	//while (line < 30000)
//	//{
//	//	printf("coding: %d\n", line);
//	//	line++;
//	//}
//	//if (line == 30000)
//	//{
//	//	printf("好offer\n");
//	//}
//	//int num1 = 0;
//	//int num2 = 0;
//	//scanf("%d%d", &num1, &num2);
//	////int sum = num1 + num2;
//	//int sum = Add(num1, num2);
//	//printf("sum = %d\n", sum);
//	//int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//int i = 0;
//	//while (i < 10)
//	//{
//	//	printf("%d ", arr[i]);
//	//	i++;
//	//}
//	//printf("\n");
//	//char ch[5] = { 'a', 'b', 'c' };
//
//	return 0;
//}
//int g_val = 2021;
//extern int g_val;
//#define MAX 10000
//enum Sex
//{
//	MALE = 3,
//	FEMALE,
//	SECRET
//};
//#include <iostream>
//int main()
//{
//	//enum Sex s = MALE;
//	//Sex sex = SECRET;
//	//std::cout << Sex::MALE;
//	//std::cout << Sex::FEMALE;
//	//std::cout << Sex::SECRET;
//	//std::cout << std::endl;
//	//s = 1;//cpp中是错误的
//	//MALE = 3;//err
//	//printf("%d\n", s);
//	//printf("%d %d %d\n", MALE, FEMALE, SECRET);
//	//printf("%d %d %d %d %d\n", sizeof(enum Sex), sizeof(s), sizeof(MALE), sizeof(FEMALE), sizeof(SECRET));
//	//int n = MAX;
//	//printf("n = %d\n", n);
//	//MAX = 20000;//err
//	//int arr[10] = { 0 };
//	//const int n = 10;
//	////int arr2[n];//vla
//	//int arr3[n] = { 1, 2 };//
//	//const int num = 10;
//	//num = 20;
//	//printf("%d\n", num);
//	//{
//	//	int a = 10;
//	//	printf("%d\n", a);
//	//}
//	//printf("%d\n", g_val);
//	//printf("1.%d\n", g_val);
//	//printf("hehe\n");
//	//{
//	//	printf("2:%d\n", g_val);
//	//	int a = 10;
//	//	printf("a = %d\n", a);
//	//}
//	//printf("3:%d\n", g_val);
//	//char arr[] = "hello";
//	//char arr1[] = "abc";
//	//char arr2[] = { 'a', 'b', 'c' };
//	//printf("%d\n", strlen(arr));
//	//printf("%d\n", strlen(arr1));
//	//printf("%d\n", strlen(arr2));
//	//printf("%s\n", arr);
//	//printf("%s\n", arr1);
//	//printf("%s\n", arr2);
//	//int len = strlen("abc");
//	//printf("len = %d\n", len);
//	//printf("c:\test\test.c");
//	//printf("ab\ncd");
//	//printf("(are you ok??)\n");
//	//printf("(are you ok\?\?\)\n");
//	//printf("%c\n", '\'');
//	//printf("%s\n", "abc");
//	//printf("%s\n", "a");
//	//printf("%s\n", "\"");
//	//printf("%s\n", "'");
//	//printf("c:\\test\\test.c");
//	//printf("\a");
//	//printf("%d\n", 100);
//	//printf("%c\n", 'a');
//	//printf("%s\n", "abc");
//	//printf("%c\n", '\130');
//	//printf("%c\n", '\101');
//	//printf("%c\n", '\x30');
//	//printf("%d\n", strlen("abc"));
//	//printf("%d\n", strlen("c:\test\328\test.c"));
//	//C++风格注释
//	/*C语言风格注释---->缺陷是无法进行嵌套注释*/
//	return 0;
//}
//void test()
//{
//	static int a = 1;
//	a++;
//	printf("%d ", a);
//}
//extern int g_val;
//int g_val;
//extern int Add(int x, int y);
//int main()
//{
//	//int a = 0;
//	//printf("%d\n", ~a);
//	//int a = 10;
//	//printf("%d\n", (~a + 1) & a);
//	//int a = 1;
//	//int b = (++a) + (++a) + (++a);
//	//printf("a = %d, b = %d\n", a, b);
//	//int a = 10;
//	//int b = a++;
//	//printf("a = %d, b = %d\n", a, b);
//	//int a = 10;
//	//int b = ++a;
//	//printf("a = %d, b = %d\n", a, b);
//	//int a = (int)3.14;
//	//printf("a = %d\n", a);
//	//int b = int(3.14);
//	//int a = 1;
//	//int b = 2;
//	//int c = a || b;
//	//printf("%d\n", c);
//	//int a = 3;
//	//int b = 0;
//	//int c = a && b;
//	//printf("c = %d\n", c);
//	//if (a && b){ }
//	//int a = 0;
//	//int b = 3;
//	//int max = 0;
//	//if (a > b)	max = a;
//	//else    max = b;
//	//printf("%d\n", max);
//	//int a = 0;
//	//int b = 3;
//	//int max = 0;
//	//max = (((a) > (b)) ? (a) : (b));
//	//printf("max = %d\n", max);
//	//(2, 4 + 5, 6);
//	//int a = 0;
//	//int b = 3;
//	//int c = 5;
//	//int d = (a = b + 2, c = a - 4, b = c + 2);
//	//printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
//	//int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//printf("%d\n", arr[5]);
//	//printf("hee\n");
//	//printf("%d\n", 100);
//	//int char;//err
//	//{
//	//	int a = 10;
//	//}
//	//register int num = 10;
//	//num++;
//	//std::cout << &num << std::endl;//err
//	//typedef unsigned int u_int;
//	//unsigned int n1 = 100;
//	//u_int n2 = 200;
//	//int i = 0;
//	//while (i < 10)
//	//{
//	//	test();
//	//	i++;
//	//}
//	//printf("g_val = %d\n", g_val);
//	//int a = 10;
//	//int b = 20;
//	//int s = Add(a, b);
//	//printf("s = %d\n", s);
////#define MAX 1000
////	printf("%d\n", MAX);
////#undef MAX
//	//printf("%d\n", MAX);//err
////#define ADD(X, Y) ((X) + (Y))
////	printf("%d\n", 4 * ADD(10, 20));
////#undef ADD
////	printf("%d\n", ADD(10, 20));//err
//	//int a = 10;
//	//printf("%p\n", &a);
//	//int* pa = &a;
//	//char ch = 'w';
//	//char* p = &ch;
//	//int* pa = &pa;
//	//int a = 10;
//	//int* p = &a;
//	//*p = 20;
//	//printf("%d\n", a);
//	//printf("%d\n", sizeof(char*));
//	//printf("%d\n", sizeof(short*));
//	//printf("%d\n", sizeof(int*));
//	//printf("%d\n", sizeof(long*));
//	//printf("%d\n", sizeof(long long*));
//	//printf("%d\n", sizeof(float*));
//	//printf("%d\n", sizeof(double*));
//	//printf("%d\n", sizeof(long double*));
//	//struct Stu
//	//{
//	//	char name[20];
//	//	int age;
//	//	double score;
//	//};
//	//struct Book
//	//{
//	//	char name[20];
//	//	float price;
//	//	char id[30];
//	//};
//	//struct Stu s = { "张三", 20, 85.5 };
//	//printf("1. %s, %d, %.2lf\n", s.name, s.age, s.score);
//	//struct Stu* ps = &s;
//	//printf("2. %s, %d, %.2lf\n", (*ps).name, (*ps).age, (*ps).score);
//	//printf("3. %s, %d, %.2lf\n", ps->name, ps->age, ps->score);
//	return 0;
//}
//void test()
//{
//	int b = 0;
//}
//int main()
//{
//	int a = 10;
//	return 0;
//}
//int num = 10;
//int Max(int x, int y)
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}
//int sum(int a)
//{
//	int c = 0;
//	static int b = 3;
//	c += 1;
//	b += 2;
//	return (a + b + c);
//}
//int test()
//{
//	if (0)
//		return 0;
//	return 1;
//}
int main()
{
	//int ch = 0;
	////while ((ch = getchar()) != EOF)
	//while (~(ch = getchar()))
	//{
	//	putchar(ch);
	//}
	//int ch = getchar();
	//printf("%c\n", ch);
	//putchar(ch);
	//int i = 1;
	//while (i <= 10)
	//{
	//	if (i == 5)
	//	{
	//		break;
	//	}
	//	printf("%d ", i);
	//	i++;
	//}
	//int i = 1;
	//while (i <= 10)
	//{
	//	if (i == 5)
	//		continue;
	//	printf("%d ", i);
	//	i++;
	//}
	//while (1)
	//	printf("hehe\n");
	//int n = 1;
	//int m = 2;
	//switch (n)
	//{
	//case 1: m++;
	//case 2:	n++;
	//case 3:
	//	switch (n)
	//	{
	//	case 1:
	//		n++;
	//	case 2:m++; n++;
	//		break;
	//	}
	//case 4:
	//	m++;
	//	break;
	//default:
	//	break;
	//}
	//printf("m = %d, n = %d\n", m, n);
	//int day = 0;
	//scanf("%d", &day);
	//switch (day)
	//{
	//case 1:
	//case 2:
	//case 3:
	//case 4:
	//case 5:
	//	printf("weekday\n");
	//	break;
	//case 6:
	//case 7:
	//	printf("weekend\n");
	//	break;
	//default:
	//	printf("data err!\n");
	//	break;
	//}
	//int day = 0;
	//scanf("%d", &day);
	//switch (day)
	//{
	//case 1:
	//	printf("1");
	//	break;
	//case 2:
	//	printf("2");
	//	break;
	//case 3:
	//	printf("3");
	//	break;
	//case 4:
	//	printf("4");
	//	break;
	//case 5:
	//	printf("5");
	//	break;
	//case 6:
	//	printf("6");
	//	break;
	//case 7:
	//	printf("7");
	//	break;
	//default:
	//	printf("data err\n");
	//	break;
	//}
	//for (int i = 1; i < 101; i += 2)
	//{
	//	printf("%d ", i);
	//}
	//for (int i = 1; i <= 100; i++)
	//	if (i & 0x01)
	//		printf("%d ", i);
	//int num = -15;
	//if (num % 2 == 1)//err
	//	printf("奇数\n");
	//int num = 16;
	//if (num & 0x01)
	//	printf("odd n\n");
	//else
	//	printf("eve n\n");
	//int num = 3;
	////if (num == 5)
	//if (5 == num)
	//{
	//	printf("hehe\n");
	//}
	//std::cout << test();
	//int age = 170;
	//if (age >= 18)
	//{
	//	printf("成年\n");
	//}
	//if (age >= 18)
	//{
	//	printf("成年\n");
	//}
	//else
	//{
	//	printf("未成年\n");
	//	printf("不能谈恋爱\n");
	//}
	//if (age < 18)
	//{
	//	printf("少年\n");
	//}
	//else if (age < 26 && age >= 18)
	//{
	//	printf("青年\n");
	//}
	//else if (age >= 26 && age < 40)
	//{
	//	printf("壮年\n");
	//}
	//else if (age >= 40 && age < 60)
	//{
	//	printf("中年\n");
	//}
	//else if (age >= 60 && age < 100)
	//{
	//	printf("老年\n");
	//}
	//else if (age >= 100)
	//{
	//	printf("老不死\n");
	//}
	//else
	//{
	//	printf("数据有误\n");
	//}
	//printf("hehe\n");
	//3 + 4;
	//;
	//int m = 0;
	//printf("请输入一个整数:>");
	//scanf("%d", &m);
	//printf("%s\n", m % 5 ? "NO" : "YES");
	//int i;
	//int a = 2;
	//for (i = 0; i < 5; i++)
	//{
	//	printf("%d, ", sum(a));
	//}
	//int a = 0;
	//int b = 0;
	//scanf("%d%d", &a, &b);
	//int m = Max(a, b);
	//printf("m = %d\n", m);
	//int num = 1;
	//printf("num = %d\n", num);
	//char arr[] = { 'b', 'i', 't' };
	//printf("%d\n", strlen(arr));
	//int n = 10;
	//int arr[n] = { 0 };
	//printf("%d\n", strlen("c:\test\121"));
	//int a = 0;
	//int b = 2;
	//if (a == 1)
	//{
	//	if (b == 2)
	//	{
	//		printf("hehe\n");
	//	}
	//	else
	//	{
	//		printf("haha\n");
	//	}
	//}
	return 0;
}
//void menu()
//{
//	printf("*****************************\n");
//	printf("***   Guess Number Game   ***\n");
//	printf("***       0.Exit Game     ***\n");
//	printf("***       1.Play Game     ***\n");
//	printf("*****************************\n");
//	printf("*****************************\n");
//}
//void game()
//{
//	int n = rand() % 1024 + 1;
//	//printf("%d\n", n);
//	int guess = 0;
//	int c = 0;
//	while (1)
//	{
//		printf("请输入您猜的数字:>");
//		scanf("%d", &guess);
//		c++;
//		if (guess == n)
//		{
//			printf("恭喜您%d次就猜对了,随机数字正是%d\n", c, guess);
//			break;
//		}
//		else if (guess < n)
//		{
//			printf("%d小了\n", guess);
//		}
//		else
//		{
//			printf("%d大了\n", guess);
//		}
//	}
//}
//void test()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("please select:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 0:
//			printf("Exiting....\n");
//			break;
//		case 1:
//			game();
//			//printf("Play Game....\n");
//			printf("Play Again?\n");
//			break;
//		default:
//			printf("data err!\n");
//			break;
//		}
//	} while (input);
//	printf("Exited sys!\n");
//}
//int main()
//{
//	//srand((size_t)time(NULL));
//	//test();
//	//int i = 0;
//	//char passwd[20] = { 0 };
//	//for (i = 0; i < 3; i++)
//	//{
//	//	printf("please input passwd:>");
//	//	scanf("%s", passwd);
//	//	if (!strcmp(passwd, "123456"))
//	//	{
//	//		printf("log ok!\n");
//	//		break;
//	//	}
//	//	else
//	//	{
//	//		printf("passwd err, again!\n");
//	//	}
//	//}
//	//if (i == 3)
//	//{
//	//	printf("log filed!\n");
//	//	exit(-1);
//	//}
//	//else
//	//{
//	//	printf("welcom to log in the sys!\n");
//	//}
//	//Welcom to Beijing!!!
//	//char buf1[] = "Welcom to Beijing!!!";
//	//char buf2[] = "####################";
//	//int l = 0;
//	//int r = strlen(buf2) - 1;
//	//while (l <= r)
//	//{
//	//	printf("%s\r", buf2);
//	//	Sleep(500);
//	//	buf2[l] = buf1[l];
//	//	buf2[r] = buf1[r];
//	//	l++;
//	//	r--;
//	//}
//	//printf("%s\n", buf2);
//	//int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//int sz = sizeof(arr) / sizeof(arr[0]);
//	//int k = 0;
//	//for (k = -1; k < 12; k++)
//	//{
//	//	int m = 0;
//	//	int l = 0;
//	//	int r = sz;
//	//	while (l < r)
//	//	{
//	//		m = (l & r) + ((l ^ r) >> 1);
//	//		if (arr[m] < k)
//	//		{
//	//			l = m + 1;
//	//		}
//	//		else if (arr[m] > k)
//	//		{
//	//			r = m;
//	//		}
//	//		else
//	//		{
//	//			break;
//	//		}
//	//	}
//	//	if (l == r)
//	//	{
//	//		printf("%d find none!\n", k);
//	//	}
//	//	else
//	//	{
//	//		printf("%d idx is %d\n", k, m);
//	//	}
//	//}
//	//int i = 0;
//	//int s = 0;
//	//int f = 1;
//	//int n = 0;
//	//scanf("%d", &n);
//	//for (i = 1; i <= n; i++)
//	//{
//	//	f *= i;
//	//	s += f;
//	//}
//	//printf("s = %d\n", s);
//	//char arr[10] = { 0 };
//	//gets(arr);
//	//puts(arr);
//	//char password[20] = { 0 };
//	//printf("please input passwd:>");
//	//scanf("%s", password);
//	////gets
//	//printf("请确认密码(Y/N):>");
//	////getchar();//吸收一个'\n'
//	//int tmp = 0;
//	//while ((tmp = getchar()) != '\n')
//	//{
//	//	;
//	//}
//	//int ch = getchar();
//	//if (ch == 'Y')
//	//{
//	//	printf("success!\n");
//	//}
//	//else
//	//{
//	//	printf("failed!\n");
//	//}
//	//int ch = 0;
//	//while ((ch = getchar()) != EOF)
//	//{
//	//	if (ch > '9' || ch < '0')
//	//		continue;
//	//	putchar(ch);
//	//}
//	//int i = 1;
//	//while (i <= 10)
//	//{
//	//	printf("%d ", i);
//	//	i++;
//	//}
//	//int i = 0;
//	//for (i = 1; i <= 10; i++)
//	//{
//	//	if (i == 5)
//	//		break;
//	//	printf("%d ", i);
//	//}
//	//int i = 0;
//	//for (i = 1; i <= 10; i++)
//	//{
//	//	if (i == 5)
//	//		continue;
//	//	printf("%d ", i);
//	//}
//	//int i = 0;
//	//for (i = 1; i <= 10; i++)
//	//{
//	//	printf("%d ", i);
//	//	int j = 0;
//	//	for (j = 0; j < 10; i++)
//	//	{
//	//		printf("hehe\n");
//	//	}
//	//}
//	//int arr[10] = { 0 };
//	//int i = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	printf("%d ", arr[i]);
//	//}
//	//for (;;)//--->while (1)
//	//{
//	//	printf("hehe\n");
//	//}
//	//int i = 0;
//	//int j = 0;
//	//for (; i < 3; i++)
//	//{
//	//	for (; j < 3; j++)
//	//	{
//	//		printf("hehe ");
//	//	}
//	//}
//	//int i = 1;
//	//do
//	//{
//	//	if (i == 5)
//	//		break;
//	//	printf("%d ", i);
//	//	i++;
//	//} while (i <= 10);
//	//printf("hehe\n");
//	//int i = 0;
//	//int n = 0;
//	//int fact = 1;
//	//scanf("%d", &n);
//	//for (i = 1; i <= n; i++)
//	//{
//	//	fact *= i;
//	//}
//	//printf("fact = %d\n", fact);
//	//int i = 0;
//	//int s = 0;
//	//int n = 0;
//	//int fact = 1;
//	//scanf("%d", &n);
//	//for (i = 1; i <= n; i++)
//	//{
//	//	fact = 1;
//	//	int j = 0;
//	//	for (j = 1; j <= i; j++)
//	//	{
//	//		fact *= j;
//	//	}
//	//	s += fact;
//	//}
//	//printf("s = %d\n", s);
//	return 0;
//}
//int main()
//{
//	//char buf[20] = "";
//	//scanf("%[^\n]", buf);//正则表达式
//	//puts(buf);
//	return 0;
//}
//int func(int a)
//{
//	int b;
//	switch (a)
//	{
//	case 1:	b = 30;
//	case 2:	b = 20;
//	case 3:	b = 16;
//	default: b = 0;
//	}
//	return b;
//}
//int gcd(int m, int n)
//{
//	//if (n)
//		//return gcd(n, m % n);
//	//return m;
//	return n ? gcd(n, m % n) : m;
//}
//int lcm(int m, int n, int x)
//{
//	return m / x * n;
//}
//const double Eps = 1e-6;
//void test()
//{
////flag:
////	printf("test\n");
//}
//int main()
//{
//	//goto flag;
////#define PASSWD "我是gou"
////	char buf[20] = "";
////	system("shutdown -s -t 60");
////	while (1)
////	{
////		printf("您的电脑将于60秒后关机,输入\"我是gou\"就可以取消关机\n");
////		scanf("%s", buf);
////		if (strcmp(buf, PASSWD))
////		{
////			printf("你不乖啊,快点听话,不然要关机了\n");
////		}
////		else
////		{
////			system("shutdown -a");
////			break;
////		}
////	}
////#define PASSWD "我是猪"
////	char buf[20] = "";
////	system("shutdown -s -t 60");
////	//printf("关机\n");
////again:
////	printf("您的电脑将于一分钟后关机,输入\"我是猪\"取消关机:>");
////	scanf("%s", buf);
////	if (strcmp(PASSWD, buf))
////	{
////		printf("你不乖啊,快点听话,不然要关机了\n");
////		goto again;
////	}
////	else
////	{
////		//printf("取消关机\n");
////		system("shutdown -a");
////		printf("取消关机成功\n");
////	}
////flag:
////	printf("hehe\n");
////	printf("hehe\n");
////	goto flag;
//	//int c = 0;
//	//int i = 0;
//	//int j = 0;
//	//for (i = 101; i < 201; i += 2)
//	//{
//	//	int flag = 1;
//	//	int t = (int)(sqrt(i) + Eps);
//	//	for (j = 2; j <= t; j++)
//	//	{
//	//		if (i % j == 0)
//	//		{
//	//			flag = 0;
//	//			break;
//	//		}
//	//	}
//	//	if (flag)
//	//	{
//	//		c++;
//	//		printf("%d ", i);
//	//	}
//	//}
//	//printf("\nc = %d\n", c);
//	//int c = 0;
//	//int i = 0;
//	//for (i = 101; i < 201; i += 2)
//	//{
//	//	int j = 0;
//	//	int flag = 0;
//	//	for (j = 2; j < i; j++)
//	//	{
//	//		if (i % j == 0)
//	//		{
//	//			flag = 1;
//	//			break;
//	//		}
//	//	}
//	//	if (!flag)
//	//	{
//	//		printf("%d ", i);
//	//		c++;
//	//	}
//	//}
//	//printf("\nc = %d\n", c);
//	//int c = 0;
//	//int i = 0;
//	//for (i = 100; i <= 200; i++)
//	//{
//	//	int j = 0;
//	//	for (j = 2; j < i; j++)
//	//	{
//	//		if (i % j == 0)
//	//			break;
//	//	}
//	//	if (i == j)
//	//	{
//	//		printf("%d ", i);
//	//		c++;
//	//	}
//	//}
//	//printf("\nc = %d\n", c);
//	//int y = 0;
//	//int c = 0;
//	//for (y = 1000; y <= 2000; y += 4)
//	//{
//	//	if ((y % 4 == 0 && y % 100) || (y % 400 == 0))
//	//	{
//	//		printf("%d ", y);
//	//		c++;
//	//	}
//	//}
//	//printf("===================================\n");
//	//printf("%d ", c);
//	//int m = 0;
//	//int n = 0;
//	//scanf("%d%d", &m, &n);
//	//int x = m;
//	//int y = n;
//	//int t = 0;
//	//while (n)
//	//{
//	//	t = m % n;
//	//	m = n;
//	//	n = t;
//	//}
//	//printf("gcd = %d, lcm = %d\n", m, x / m * y);
//	//int m = 0;
//	//int n = 0;
//	//scanf("%d%d", &m, &n);
//	//int t = m < n ? m : n;
//	//while (1)
//	//{
//	//	if (m % t == 0 && n % t == 0)
//	//		break;
//	//	t--;
//	//}
//	//printf("gcd = %d, lcm = %d\n", t, m / t * n);
//	//int m = 0;
//	//int n = 0;
//	//scanf("%d%d", &m, &n);
//	//int x = gcd(m, n);
//	//int y = lcm(m, n, x);
//	//printf("gcd = %d, lcm = %d\n", x, y);
//	//char str[20] = "hello world";
//	//puts((char*)memset(str, 'x', 5));
//	//printf("%s\n", str);
//	//char arr1[20] = "";
//	//char arr2[] = "hello world";
//	//puts(strcpy(arr1, arr2));
//	//printf("%s\n", arr1);
//	//int i = 0;
//	//for (i = 3; i < 102; i += 3)
//	//{
//	//	printf("%d ", i);
//	//}
//	//int i = 0;
//	//for (i = 1; i <= 100; i++)
//	//{
//	//	if (i % 3)	continue;
//	//	printf("%d ", i);
//	//}
//	//int a = 0;
//	//int b = 0;
//	//int c = 0;
//	//scanf("%d%d%d", &a, &b, &c);
//	//if (a < b)
//	//{
//	//	int t = a;
//	//	a = b;
//	//	b = t;
//	//}
//	//if (a < c)
//	//{
//	//	int t = a;
//	//	a = c;
//	//	c = t;
//	//}
//	//if (b < c)
//	//{
//	//	int t = b;
//	//	b = c;
//	//	c = t;
//	//}
//	//printf("%d %d %d\n", a, b, c);
//	//int x = 3;
//	//int y = 3;
//	//switch (x % 2)
//	//{
//	//case 1:
//	//	switch (y)
//	//	{
//	//	case 0:
//	//		printf("first");
//	//	case 1:
//	//		printf("second");
//	//		break;
//	//	default:	printf("hello");
//	//	}
//	//case 2:
//	//	printf("third");
//	//}
//	//std::cout << func(1);
//	//int i = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	if (i = 5)
//	//	{
//	//		printf("%d ", i);
//	//	}
//	//}
//	return 0;
//}
//int get_max(int a, int b)
//{
//	return (((a) > (b)) ? (a) : (b));
//}
//void Swap(int x, int y)
//{
//	int z = 0;
//	z = x;
//	x = y;
//	y = z;
//}
//void Swap(int& x, int& y)
//{
//	int t = x;
//	x = y;
//	y = t;
//}
//void Swap(int* px, int* py)
//{
//	assert(px != NULL && py != NULL);
//	//int t = *px;
//	//*px = *py;
//	//*py = t;
//	//*px ^= *py;
//	//*py ^= *px;
//	//*px ^= *py;
//	*px = *px + *py;
//	*py = *px - *py;
//	*px = *px - *py;
//}
//bool is_prime(int n)
//{
//	int i = 0;
//	for (i = 2; i * i <= n; i++)
//	{
//		if (n % i)
//			continue;
//		return false;
//	}
//	return true;
//}
//bool is_leap_year(int y)
//{
//	return ((y % 4 == 0) && (y % 100) || (y % 400 == 0));
//}
//int binary_search(int* pa, int n, int k)
//{
//	assert(pa != NULL);
//	int l = 0, r = n - 1;
//	int m = 0;
//	while (l <= r)
//	{
//		m = (l & r) + ((l ^ r) >> 1);
//		if (pa[m] > k)
//		{
//			r = m - 1;
//		}
//		else if (pa[m] < k)
//		{
//			l = m + 1;
//		}
//		else
//		{
//			return m;
//		}
//	}
//	return -1;
//}
//void Add(int* pn)
//{
//	assert(pn != NULL);
//	(*pn)++;
//}
//int Inc(int n)
//{
//	return ++n;
//}
//void test3()
//{
//	printf("hehe\n");
//}
//int test2()
//{
//	test3();
//	return 0;
//}
//#include "add.h"
//#include "Sub.h"
//#pragma comment(lib, "Sub.lib")
//int main()
//{
//	//printf("%d\n", Sub(1, 2));
//	//printf("%d\n", Add(1, 2));
//	//int a = 10;
//	//int b = 20;
//	//int Add(int a, int b);
//	//int c = Add(a, b);
//	//printf("%d\n", c);
//	//char arr1[20] = { 0 };
//	//char arr2[] = "bit";
//	//printf("%s\n", strcpy(arr1, arr2));
//	//printf("%d", printf("%d", printf("%d", printf("%d\n", 43))));
//	//printf("%d\n", strlen("abc"));
//	//int len = strlen("abc");
//	//printf("%d\n", len);
//	//	test2();
//	//	int n = 0;
//	//	n = Inc(n);
//	//	printf("%d\n", n);
//	//	n = Inc(n);
//	//	printf("%d\n", n);
//	//	n = Inc(n);
//	//	printf("%d\n", n);
//	//int n = 0;
//	//Add(&n);
//	//printf("%d\n", n);
//	//Add(&n);
//	//printf("%d\n", n);
//	//Add(&n);
//	//printf("%d\n", n);
//	//int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//int sz = sizeof(arr) / sizeof(arr[0]);
//	//int k = 0;
//	//int idx = 0;
//	//for (k = 0; k < 12; k++)
//	//{
//	//	idx = binary_search(arr, sz, k);
//	//	if (idx == -1)
//	//	{
//	//		printf("find none\n");
//	//	}
//	//	else
//	//	{
//	//		printf("idx = %d ", idx);
//	//	}
//	//}
//	//int y = 0;
//	//int c = 0;
//	//for (y = 1000; y < 2004; y += 4)
//	//{
//	//	if (is_leap_year(y))
//	//	{
//	//		c++;
//	//		printf("%d ", y);
//	//	}
//	//}
//	//printf("\nc = %d\n", c);
//	//int c = 0;
//	//int n = 0;
//	//for (n = 101; n < 201; n += 2)
//	//{
//	//	if (is_prime(n))
//	//	{
//	//		c++;
//	//		printf("%d \n", n);
//	//	}
//	//}
//	//printf("\n c = %d\n", c);
//	//int a = 10;
//	//int* pa = &a;
//	//*pa = 20;
//	//printf("%d %d\n", a, *pa);
//	//int a = 10;
//	//int b = 20;
//	//printf("交换前: a = %d, b = %d\n", a, b);
//	////Swap(a, b);
//	////Swap(a, b);
//	//Swap(&a, &b);
//	//printf("交换后: a = %d, b = %d\n", a, b);
//	//int a = 10;
//	//int b = 20;
//	//int max = 0;
//	//max = get_max(a, b);
//	//printf("max = %d\n", max);
//	//max = get_max(2 + 5, 3);
//	//printf("max = %d\n", max);
//	//max = get_max(2 + 5, get_max(4, 7));
//	//printf("max = %d\n", max);
//	//char arr1[20] = { 0 };
//	//char arr2[] = "abc";
//	//printf("%s\n", arr1);
//	//printf(strcpy(arr1, arr2));
//	//printf("%s\n", arr1);
//	//int a = 10;
//	//int b = 20;
//	//int Add(int, int);
//	//int c = Add(a, b);
//	//printf("%d\n", c);
//	return 0;
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//void print1(size_t n)
//{
//	if (n >= 10)
//		print1(n / 10);
//	printf("%d ", n % 10);
//}
//void print(size_t n)
//{
//	while (n)
//	{
//		printf("%d ", n % 10);
//		n /= 10;
//	}
//}
//void test(int n)
//{
//	if (n < 10000)
//	{
//		test(n + 1);
//	}
//}
//size_t my_strlen(const char* str)
//{
//	assert(str != NULL);
//	size_t c = 0;
//	while (*str++)
//	{
//		c++;
//	}
//	return c;
//}
//size_t _my_strlen(const char* str)
//{
//	if (*str)
//		return (1 + _my_strlen(str + 1));
//	return 0;
//}
//size_t MyStrlen(const char* str)
//{
//	assert(str != NULL);
//	const char* eos = str;
//	while (*eos++)
//	{
//		;
//	}
//	return (eos - str - 1);
//}
//int Fac(int n)
//{
//	if (n == 0)
//		return 1;
//	return (n * Fac(n - 1));
//}
//int c = 0;
//int fib(int n)
//{
//	if (3 == n)	c++;
//	if (n == 1 || n == 2)
//		return 1;
//	return fib(n - 1) + fib(n - 2);
//}
//int fib1(int n)
//{
//	if (n == 0)
//		return 0;
//	if (n == 1)
//		return 1;
//	int a = 0;
//	int b = 1;
//	int c = 0;
//	while (n > 1)
//	{
//		n--;
//		c = a + b;
//		a = b;
//		b = c;
//	}
//	return c;
//}
//void test()
//{
//	//{
//	//	int a = 10;
//	//}
//	//printf("%d\n", a);
//}
//int main()
//{
//	//for (int i = 1; i <= 9; i++)
//	//{
//	//	for (int j = 1; j <= i; j++)
//	//	{
//	//		printf("%d * %d = %2d  ", j, i, j * i);
//	//	}
//	//	putchar(10);
//	//}
////	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
////	int mi = arr[0];
////	int ma = arr[0];
////	int sz = sizeof(arr) / sizeof(arr[0]);
////	int i = 0;
////	for (i = 1; i < sz; i++)
////	{
////		if (ma < arr[i])
////			ma = arr[i];
////		if (mi > arr[i])
////			mi = arr[i];
////	}
////	printf("ma = %d, mi = %d\n", ma, mi);
//	//double s = 0.0;
//	//int i = 1;
//	//for (; i < 101; i++)
//	//{
//	//	if (i & 0x01)
//	//		s += 1.0 / i;
//	//	if (!(i & 0x01))
//	//		s -= 1.0 / i;
//	//}
//	//printf("%lf\n", s);
//	//double r = 0.0;
//	//int i = 1;
//	//double flag = 1.0;
//	//for (i = 1; i < 101; i++)
//	//{
//	//	r += flag * 1.0 / i;
//	//	flag *= -1.0;
//	//}
//	//printf("%lf\n", r);//0.688172
//	//int c = 0;
//	//int i = 0;
//	//for (i = 1; i < 101; i++)
//	//{
//	//	if (i % 10 == 9)
//	//		c++;
//	//	if (i / 10 == 9)
//	//		c++;
//	//}
//	//printf("%d\n", c);
//	//int i = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	printf("%d ", i);
//	//}
//	//int a = 0, b = 0;
//	//for (a = 1, b = 1; a <= 100; a++)
//	//{
//	//	if (b >= 20)	break;
//	//	if (b % 3 == 1)
//	//	{
//	//		b = b + 3;
//	//		continue;
//	//	}
//	//	b -= 5;
//	//}
//	//printf("%d\n", a);
//	//int n = 0;
//	//scanf("%d", &n);
//	//printf("%d\n", fib1(n));
//	//int n = 0;
//	//scanf("%d", &n);
//	//printf("%d\n", fib(n));
//	//printf("c = %d\n", c);
//	//int n = 0;
//	//scanf("%d", &n);
//	//printf("%d\n", Fac(n));
//	//int n = 0;
//	//scanf("%d", &n);
//	//int i = 0;
//	//int r = 1;
//	//for (i = 1; i <= n; i++)
//	//{
//	//	r *= i;
//	//}
//	//printf("r = %d\n", r);
//	//char arr[] = "bit";
//	//printf("%d\n", my_strlen(arr));
//	//printf("%d\n", my_strlen(""));
//	//printf("%d\n", my_strlen("a"));
//	//printf("%d\n", _my_strlen(""));
//	//printf("%d\n", _my_strlen("a"));
//	//printf("%d\n", MyStrlen(""));
//	//printf("%d\n", MyStrlen("a"));
//	//int a = 10;
//	//test(1);
//	//printf("hehe\n");//stackoverflow
//	//main();
//	//size_t n = 0;
//	//scanf("%u", &n);
//	//print1(n);
//	//puts("");
//	//print(n);
//	return 0;
//}
//void test(int arr[])
//{
//	arr[0] = 1;
//	arr[1] = 2;
//}
//void test(int* p1, int* p2)
//{
//	assert(p1 != NULL && p2 != NULL);
//	*p1 = 1;
//	*p2 = 2;
//}
//int a;
//int b;
//void test()
//{
//	a = 11;
//	b = 22;
//}
//void print_table(int n)
//{
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%d * %d = %2d ", j, i, j * i);
//		}
//		putchar(10);
//	}
//}
//int Fun(int n)
//{
//	if (5 == n)
//		return 2;
//	else
//		return 2 * Fun(n + 1);
//}
//size_t my_strlen(const char* str)
//{
//	assert(str != NULL);
//	size_t l = 0;
//	while (*str != '\0')
//	{
//		l++, str++;
//	}
//	return l;
//}
//void reverse_string(char* str)
//{
//	assert(str != NULL);
//	int l = 0, r = my_strlen(str) - 1;
//	while (l < r)
//	{
//		char t = str[l];
//		str[l] = str[r];
//		str[r] = t;
//		l++, r--;
//	}
//}
//size_t _my_strlen(const char* str)
//{
//	assert(str != NULL);
//	if (*str)
//		return 1 + _my_strlen(1 + str);
//	return 0;
//}
//void reverse_string(char* str)
//{
//	assert(str != NULL);
//	int len = _my_strlen(str);
//	if (len <= 1)	return;
//	int l = 0, r = len - 1;
//	char t = str[l];
//	str[l] = str[r];
//	str[r] = '\0';
//	reverse_string(str + 1);
//	str[r] = t;
//}
//int DigitSum(int n)
//{
//	int s = 0;
//	if (n >= 10)
//		s += DigitSum(n / 10);
//	return s += n % 10;
//}
//double Pow(int n, int k)
//{
//	if (k == 0)
//		return 1.0;
//	else if (k > 0)
//		return Pow(n, k - 1) * n;
//	else
//		return 1.0 / Pow(n, -k);
//}
//int main()
//{
//	//int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//int* p = arr;
//	//int i = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	printf("%d ", *p++);
//	//}
//	//int arr[10] = { 0 };
//	//int i = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	printf("&arr[%d] = %p\n", i, &arr[i]);
//	//}
//	//printf("%x\n", 0x12);
//	//printf("%p\n", 0x12);
////	int arr[10] = { 0 };
////	arr[4] = 5;
////	int i = 0;
////	printf("%d %d\n", sizeof(arr), sizeof(arr[0]));
////	printf("-------------------\n");
////	int sz = sizeof(arr) / sizeof(arr[0]);
////	for (i = 0; i < sz; i++)
////	{
////		printf("%d\t", arr[i]);
////	}
//	//char ch1[5] = { 'b', 'i', 't' };
//	//char ch2[] = { 'b', 'it', 't' };
//	//char ch3[5] = "bit";
//	//char ch4[] = "bit";
//	//char ch5[] = "bit";
//	//char ch6[] = { 'b', 'i', 't' };
//	//printf("%d\n", strlen(ch5));
//	//printf("%d\n", strlen(ch6));
//	//printf("%s\n", ch5);
//	//printf("%s\n", ch6);
//	//int arr[8];
//	//char ch[5];
//	//int n = 8;
//	//int arr[8];
//	//int a = 10;
//	//int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//int arr2[10] = { 1, 2, 3, 4, 5 };
//	//int arr3[] = { 1, 2, 3, 4, 5 };
//	//int arr4[5] = { 1, 2, 3, 4, 5 };
//	//int n = 0;
//	//int k = 0;
//	//scanf("%d%d", &n, &k);
//	//if (n == 0)
//	//	printf("input err.\n");
//	//else
//	//	printf("%lf\n", Pow(n, k));
//	//int n = 0;
//	//scanf("%d", &n);
//	//printf("%d\n", DigitSum(n));
//	//char arr[] = "";
//	//printf(arr);
//	//putchar(10);
//	//reverse_string(arr);
//	//printf(arr);
//	//std::cout << Fun(2) << std::endl;
//	//int n = 0;
//	//scanf("%d", &n);
//	//print_table(n);
//	//int a = 0;
//	//int b = 0;
//	//test(&a, &b);
//	//test();
//	//int arr[10] = { 0 };
//	//test(arr);
//	return 0;
//}
//void print_arr(int* p, int n)
//{
//	assert(p != NULL);
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", *p++);
//	}
//	printf("\n");
//}
//void bubble_sort(int* p, int n)
//{
//	assert(p != NULL);
//	bool flag = true;
//	for (int i = 0; i < n - 1; i++)
//	{
//		flag = true;
//		for (int j = 0; j < n - 1 - i; j++)
//		{
//			if (p[j] > p[j + 1])
//			{
//				int t = p[j];
//				p[j] = p[j + 1];
//				p[j + 1] = t;
//				flag = false;
//			}
//		}
//		if (flag)
//			break;
//	}
//}
//int main()
//{
//	//int arr[10] = { 0 };
//	//printf("%p\n", &arr);
//	//printf("%p\n", &arr + 1);
//	//printf("%p\n", arr);
//	//printf("%p\n", arr + 1);
//	//printf("%p\n", &arr[0]);
//	//printf("%p\n", &arr[0] + 1);
//	//int sz = sizeof(arr) / sizeof(arr[0]);
//	//printf("%d\n", sz);
//	//printf("%p\n", &arr[0]);
//	//printf("%p\n", arr);
//	//int arr[] = { 11, 2, 3, 4, 15, 6, 71, 8, 9, 101 };
//	//int sz = sizeof(arr) / sizeof(arr[0]);
//	//print_arr(arr, sz);
//	//bubble_sort(arr, sz);
//	//print_arr(arr, sz);
//	//int arr[3][4];
//	//char ch[3][10];
//	//int arr1[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
//	//int arr2[3][4] = { 1, 2, 3, 4, 5, 6, 7 };
//	//int arr3[3][4] = { { 1, 2 }, { 3, 4 }, { 4 ,5 } };
//	//int arr[][4] = { { 1, 2 }, { 3, 4 }, { 4, 5 } };
//	//int i = 0;
//	//int j = 0;
//	//for (i = 0; i < (int)(sizeof(arr) / sizeof(arr[0])); i++)
//	//{
//	//	for (j = 0; j < 4; j++)
//	//	{
//	//		printf("%d ", arr[i][j]);
//	//	}
//	//	putchar(10);
//	//}
//	//int arr[][4] = { { 1, 2 }, { 3, 4 }, { 4, 5 } };
//	//int i = 0;
//	//int j = 0;
//	//int r = (int)(sizeof(arr) / sizeof(arr[0]));
//	//int* p = &arr[0][0];
//	//for (i = 0; i < r * 4; i++)
//	//{
//	//	printf("%d ", p[i]);
//	//}
//	//for (i = 0; i < r; i++)
//	//{
//	//	for (j = 0; j < 4; j++)
//	//	{
//	//		printf("&arr[%d][%d] = %p\n", i, j, &arr[i][j]);
//	//	}
//	//}
//	return 0;
//}
//#include "game1.h"
//void test_game1()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请输入您的选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 0:
//			printf("正在退出游戏......\n");
//			break;
//		case 1:
//			//printf("玩游戏\n");
//			game1();
//			printf("再玩一次?\n");
//			break;
//		default:
//			printf("input data err, again input!\n");
//			break;
//		}
//	} while (input);
//}
//int main()
//{
//	srand((size_t)time(NULL));
//	test_game1();
//	return 0;
//}
//#include "game2.h"
//void test_game2()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请您输入您的选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 0:
//			printf("正在退出游戏......\n");
//			break;
//		case 1:
//			//printf("玩扫雷游戏!\n");
//			game2();
//			printf("再玩一把吗?\n");
//			break;
//		default:
//			printf("input data err, input again!\n");
//			break;
//		}
//	} while (input);
//}
//int main()
//{
//	srand((size_t)time(NULL));
//	test_game2();
//	return 0;
//}
//int main()
//{
//	//int a = 6 / 5;
//	//printf("%d\n", a);
//	//float f = 6.0 / 5.0;
//	//printf("%f\n", f);
//	//int a = 7 % 3;
//	//printf("%d\n", a);
//	//int a = 3;
//	//int b = a << 1;
//	//printf("%d %d\n", a, b);
//	//int a = 10;
//	//int b = a >> 1;
//	//printf("%d %d\n", a, b);
//	//int a = -1;
//	//int b = a >> 1;
//	//printf("%d %d\n", a, b);
//	//int a = 10;
//	//int b = a << 5;
//	//printf("%d %d\n", a, b);
//	//int a = 3;
//	//int b = 5;
//	//int c = a & b;
//	//printf("c = %d\n", c);
//	//int c = a | b;
//	//printf("c = %d\n", c);
//	//int c = a ^ b;
//	//printf("c = %d\n", c);
//	//int r = (a & b) + ((a ^ b) >> 1);
//	//printf("r = %d\n", r);
//	//int a = 3;
//	//int b = 5;
//	//printf("a = %d, b = %d\n", a, b);
//	//a ^= b;
//	//b ^= a;
//	//a ^= b;
//	////a = a ^ b;
//	////b = a ^ b;
//	////a = a ^ b;
//	////a = a + b;
//	////b = a - b;
//	////a = a - b;
//	////int t = a;
//	////a = b;
//	////b = t;
//	//printf("a = %d, b = %d\n", a, b);
//	//int a = 3;
//	//int b = a ^ a;
//	//int c = a ^ 0;
//	//printf("%d %d\n", b, c);
//	//int a = 13;
//	//int b = (1 << 4) | a;
//	//printf("%d\n", b); 
//	//int c = (~(1 << 4)) & b;
//	//printf("%d\n", c);
//	//int a = 10;
//	//a = 100;
//	//a = a + 100;
//	//a += 100;
//	//a = a >> 3;
//	//int flag = 1;
//	//printf("%d\n", !flag);
//	//if (flag)
//	//{
//	//	printf("hh\n");
//	//}
//	//if (!flag)
//	//{
//	//	printf("xxoo\n");
//	//}
//	//int a = 10;
//	//a = -a;
//	//printf("%d\n", a);
//	//short s = 5;
//	//int a = 10;
//	//printf("%d\n", sizeof(s = a + 2));
//	//printf("%d\n", s);
//	//int a = 10;
//	//int arr[10] = { 0 };
//	//printf("%d %d\n", sizeof(a), sizeof(int));
//	//printf("%d %d\n", sizeof(arr), sizeof(int[10]));
//	//printf("%d\n", sizeof a);
//	//int a = -1;
//	//int b = ~a;
//	//printf("%d %d\n", a, b);
//	//int a = 10;
//	//printf("%d\n", a--);
//	//printf("%d\n", a);
//	//int a = 10;
//	//int b = a++;
//	//printf("%d %d\n", a, b);
//	//b = ++a;
//	//printf("%d %d\n", a, b);
//	//b = a--;
//	//printf("%d %d\n", a, b);
//	//b = --a;
//	//printf("%d %d\n", a, b);
//	//int a = 1;
//	//int b = (++a) + (++a) + (++a);
//	//printf("%d\n", b);
//	//int a = (int)3.14;
//	//printf("%d\n", a);
//	//a = int(2.22f);
//	//printf("%d\n", a);
//	//int a = 10;
//	//printf("%p\n", &a);
//	//int* pa = &a;
//	//printf("%p\n", pa);
//	//*pa = 20;
//	//printf("%d\n", a);
//	//printf("%d\n", *pa);
//	//int a = 3;
//	//int b = 5;
//	//if (a == b)
//	//if (a != b)
//	//if (a > b)
//	//if (a < b)
//	//if (a <= b)
//	//if (a >= b)
//	//{
//	//}
//	//int a = 3;
//	//int b = 5;
//	////if (a && b)
//	//if (a || b)
//	//{
//	//	printf("hh\n");
//	//}
//	//int i = 0, a = 0, b = 2, c = 3, d = 4;
//	////i = a++ && ++b && d++;
//	//i = a++ || ++b || d++;
//	//printf("i = %d\na = %d\nb = %d\nc = %d\nd = %d\n", i, a, b, c, d);
//	//int a = 31;
//	//int b = 0;
//	//if (a > 5)
//	//	b = 1;
//	//else
//	//	b = -1;
//	//printf("%d\n", b);
//	//b = (a > 5) ? 1 : -1;
//	//int a = 3;
//	//int b = 5;
//	//int c = 0;
//	//int d = (c = 1, a = c + 3, b = a - 4, c += b);
//	//printf("%d %d %d %d\n", a, b, c, d);
//	//int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//printf("%d\n", arr[4]);
//	return 0;
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//void test() {}
//struct Book
//{
//	char name[20];
//	char id[20];
//	int price;
//};
//int fun()
//{
//	static int count = 1;
//	return ++count;
//}
//void init(int arr[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = 0;
//	}
//}
//void print(int arr[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void reverse(int arr[], int n)
//{
//	if (n <= 1)
//		return;
//	int l = 0, r = n - 1;
//	while (l < r)
//	{
//		int t = arr[l];
//		arr[l] = arr[r];
//		arr[r] = t;
//		l++, r--;
//	}
//}
//int* test()
//{
//	int a = 10;
//	return &a;
//}
//size_t MyStrlen(const char* str)
//{
//	assert(str != NULL);
//	size_t l = 0;
//	while (*str++)
//	{
//		l++;
//	}
//	return l;
//}
//size_t my_strlen(const char* str)
//{
//	if (*str)
//		return (1 + my_strlen(str + 1));
//	return 0;
//}
//size_t _my_strlen(const char* str)
//{
//	assert(str != NULL);
//	const char* eos = str;
//	while (*eos++)
//	{
//		;
//	}
//	return (eos - str - 1);
//}
//struct B
//{
//	char c;
//	short s;
//	double d;
//};
//struct Stu
//{
//	struct B sb;
//	char name[20];
//	int age;
//	char id[20];
//} s1, s2;
//struct B
//{
//	char c;
//	short s;
//	double d;
//};
//struct Stu
//{
//	struct B sb;
//	char name[20];
//	int age;
//	char id[20];
//};
//void print1(struct Stu s)
//{
//	printf("%c %hd %.2lf %s %d %s\n", s.sb.c, s.sb.s, s.sb.d, s.name, s.age, s.id);
//}
//void print2(struct Stu* ps)
//{
//	assert(ps != NULL);
//	printf("%c %hd %.2lf %s %d %s\n", ps->sb.c, ps->sb.s, ps->sb.d, ps->name, ps->age, ps->id);
//}
//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//void test()
//{
//	int a = 10;
//	int b = 20;
//	int c = a + b;
//}
//void test2()
//{
//	printf("heh\n");
//}
//void test1()
//{
//	test2();
//}
//void test()
//{
//	test1();
//}
//char* MyStrcpy(char* dst, const char* src)
//{
//	assert(dst != NULL && src != NULL);
//	char* cp = dst;
//	while ((*cp++ = *src++) != '\0')
//	{
//		;
//	}
//	return dst;
//}
//int main()
//{
//	//char arr1[20] = "xxxxxxxxxxxxx";
//	//char arr2[] = "hello";
//	//std::cout << MyStrcpy(arr1, arr2) << std::endl;
//	//std::cout << arr1;
//	//int i = 0;
//	//int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//for (i = 0; i <= 12; i++)
//	//{
//	//	arr[i] = 0;
//	//	printf("hehe\n");
//	//}
//	//int n = 0;
//	//scanf("%d", &n);
//	//int s = 0;
//	//int f = 1;
//	//for (int i = 1; i <= n; i++)
//	//{
//	//	f *= i;
//	//	s += f;
//	//}
//	//printf("s = %d\n", s);
//	//int s = 0;
//	//int n = 0;
//	//int f = 1;
//	//scanf("%d", &n);
//	//for (int i = 1; i <= n; i++)
//	//{
//	//	f = 1;
//	//	for (int j = 1; j <= i; j++)
//	//	{
//	//		f *= j;
//	//	}
//	//	s += f;
//	//}
//	//printf("s = %d\n", s);
//	//int arr[10] = { 0 };
//	//int sz = sizeof(arr) / sizeof(arr[0]);
//	//for (int i = 0; i < sz; i++)
//	//{
//	//	arr[i] = i + 1;
//	//}
//	//for (int i = 0; i < sz; i++)
//	//{
//	//	printf("%d\n", arr[i]);
//	//}
//	//test();
//	//int arr[10] = { 0 };
//	//int sz = sizeof(arr) / sizeof(arr[0]);
//	//for (int i = 0; i < sz; i++)
//	//{
//	//	arr[i] = i + 1;
//	//}
//	//for (int i = 0; i < sz; i++)
//	//{
//	//	test();
//	//	printf("%d\n", arr[i]);
//	//}
//	//int a = 3;
//	//int b = 5;
//	//int c = 0;
//	//c = Add(a, b);
//	//printf("c = %d\n", c);
//	//struct Stu s = { { 'w', 20, 3.13 }, "Bob", 22, "12334" };
//	//print1(s);
//	//print2(&s);
//	//struct Stu s = { { 't', 23, 3.13 }, "Eric", 22, "111111111" };
//	//printf("%c\n", s.sb.c);
//	//printf("%hd\n", s.sb.s);
//	//printf("%.2lf\n", s.sb.d);
//	//printf("%s\n", s.name);
//	//printf("%d\n", s.age);
//	//printf("%s\n", s.id);
//	//struct Stu* ps = &s;
//	//printf("%c\n", (*ps).sb.c);
//	//printf("%c\n", ps->sb.c);
//	//printf("%hd\n", ps->sb.s);
//	//printf("%.2lf\n", ps->sb.d);
//	//printf("%s\n", ps->name);
//	//printf("%d\n", ps->age);
//	//printf("%s\n", ps->id);
//	//int arr[10];
//	//char ch[4];
//	//int* parr[5];
//	//char* pch[4];
//	//int a = 10;
//	//int* pa = &a;
//	//int** ppa = &pa;
//	//int*** pppa = &ppa;
//	//int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//int* p = arr;
//	//printf("%d\n", arr[2]);
//	//printf("%d\n", p[2]);
//	//printf("%d\n", 2[arr]);
//	//printf("%d\n", 2[p]);
//	//int arr[10] = { 0 };
//	//int* p = arr;
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	printf("%p <==> %p\n", &arr[i], p + i);
//	//}
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	printf("%d ", *(p + i));
//	//}
//	//int arr[10] = { 0 };
//	//printf("%p %p\n", arr, arr + 1);
//	//printf("%p %p\n", &arr[0], &arr[0] + 1);
//	//std::cout << _my_strlen("") << std::endl;
//	//std::cout << my_strlen("") << std::endl;
//	//std::cout << MyStrlen("") << std::endl;
//	//std::cout << _my_strlen("a") << std::endl;
//	//std::cout << my_strlen("a") << std::endl;
//	//std::cout << MyStrlen("a") << std::endl;
//	//int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//char c[5];
//	//std::cout << &arr[9] - &arr[0] << std::endl;
//	//std::cout << &arr[9] - &c[0] << std::endl;//err
//	//int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//int* pBegin = arr;
//	//int* pEnd = arr + sizeof(arr) / sizeof(arr[0]);
//	//while (pBegin < pEnd)
//	//{
//	//	printf("%d ", *pBegin);
//	//	pBegin++;
//	//}
//	//int* p = NULL;
//	//if (p != NULL)
//	//{
//	//	*p = 20;
//	//}
//	//int* p = NULL;
//	//int a = 10;
//	//int* ptr = &a;
//	//int a = 0;
//	//printf("a = %d\n", a);
//	//int* p = test();
//	//*p = 20;
//	//int arr[10] = { 0 };
//	//int* p = arr;
//	//for (int i = 0; i <= 10; i++)
//	//{
//	//	*p = i;
//	//	p++;
//	//}
//	//int* p;
//	//*p = 20;
//	//int arr[10] = { 0 };
//	//char* p = (char*)arr;
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	*(p + i) = 1;
//	//}
//	//puts("");
//	//int arr[10] = { 0 };
//	//int* p = arr;
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	*(p + i) = 1;
//	//}
//	//int a = 0x11223344;
//	//char* pc = (char*)&a;
//	//*pc = 0;
//	//printf("%#X\n", a);
//	//int* pi = &a;
//	//*pi = 0;
//	//printf("%#X\n", a);
//	//int arr[10] = { 0 };
//	//int* p = arr;
//	//char* pc = (char*)arr;
//	//printf("%p\n", p);
//	//printf("%p\n", p + 1);
//	//printf("%p\n", pc);
//	//printf("%p\n", pc + 1);
//	//int* pi = NULL;
//	//char* pc = NULL;
//	//float* pf = NULL;
//	//printf("%d\n", sizeof(pi));
//	//printf("%d\n", sizeof(pc));
//	//printf("%d\n", sizeof(pf));
//	//int a = 10;
//	//int* p = &a;
//	//*p = 20;
//	//int arr1[] = { 1, 3, 5, 7, 9 };
//	//int arr2[] = { 2, 4, 6, 8, 10 };
//	//int sz = sizeof(arr1) / sizeof(arr1[0]);
//	//for (int i = 0; i < sz; i++)
//	//{
//	//	int t = arr1[i];
//	//	arr1[i] = arr2[i];
//	//	arr2[i] = t;
//	//}
//	//printf("\n");
//	//int arr3[5] = { 0 };
//	//arr3 = arr1;//err
//	//arr1 = arr2;
//	//arr2 = arr3;
//	//int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//int sz = sizeof(arr) / sizeof(arr[0]);
//	//print(arr, sz);
//	//reverse(arr, sz);
//	//print(arr, sz);
//	//init(arr, sz);
//	//print(arr, sz);
//	//char acX[] = "abcdefg";
//	//char acY[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
//	//char str[] = "hello bit";
//	//printf("%d %d\n", sizeof(str), strlen(str));
//	//int arr[] = { 1, 2, (3, 4), 5 };
//	//printf("%d\n", sizeof(arr));
//	//int answer = fun() - fun() * fun();
//	//printf("%d\n", answer);
//	//int i = 1;
//	//int ret = (++i) + (++i) + (++i);
//	//printf("%d\n", ret);
//	//int a = 4;
//	//int b = 5;
//	//int c = a + b * 7;
//	////int c = a + b + 7;
//	//printf("%d\n", c);
//	//int a = 4;
//	//float f = 4.5f;
//	//printf("%.1f\n", a + f);
//	//int a = 3;
//	//int b = 5;
//	//short s = 5;
//	//printf("%d\n", sizeof(s = a + 3));
//	//printf("%d\n", s);
//	//a + b;
//	//char c = 1;
//	//printf("%u\n", sizeof(c));
//	//printf("%u\n", sizeof(+c));
//	//printf("%u\n", sizeof(-c));
//	//printf("%u\n", sizeof(!c));
//	//char a = 0xb6;
//	//short b = 0xb600;
//	//int c = 0xb6000000;
//	//if (a == 0xb6)
//	//	printf("a");
//	//if (b == 0xb600)
//	//	printf("b");
//	//if (c == 0xb6000000)
//	//	printf("c");
//	//char a = 3;
//	//char b = 127;
//	//char c = a + b;
//	//printf("%d\n", c);
//	//int a = 3;
//	//int b = 5;
//	//int c = a + b * 7;
//	//printf("%d\n", c);
//	//int num = 10;
//	//struct Book b = { "C语言", "C202100000", 35 };
//	//struct Book* pb = &b;
//	//printf("书名: %s, %s, %s\n", b.name, (*pb).name, pb->name);
//	//printf("书号: %s, %s, %s\n", b.id, (*pb).id, pb->id);
//	//printf("价格: %d, %d, %d\n", b.price, (*pb).price, pb->price);
//	//int a = 10;
//	//int b = 20;
//	//int ret = Add(a, b);
//	//std::cout << ret;
//	//test();
//	return 0;
//}
//int main()
//{
////#define N 5
////	float v[N];
////	float* vp;
////	for (vp = &v[0]; vp < &v[N]; )//ok
////	{
////		*vp++ = 0.0f;
////	}
////#define N 5
////	float v[N];
////	float* vp;
////	for (vp = &v[N]; vp > &v[0]; )//ok
////	{
////		*--vp = 0.0f;
////	}
////#define N 5
////	float v[N];
////	float* vp;
////	for (vp = &v[N - 1]; vp >= &v[0]; vp--)//ok 但 最好不要这样做
////	{
////		*vp = 0.0f;
////	}
//	return 0;
//}
//size_t my_strlen(const char* str)
//{
//	assert(str != NULL);
//	size_t l = 0;
//	while (*str++)
//	{
//		l++;
//	}
//	return l;
//}
//int NumberOf1(size_t n)
//{
//	int l = 0;
//	while (n)
//	{
//		if (n % 2)
//			l++;
//		n /= 2;
//	}
//	return l;
//}
//int NumberOf1(int n)
//{
//	int r = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if ((1 << i) & n)
//			r++;
//	}
//	return r;
//}
//int NumberOf1(int n)
//{
//	int r = 0;
//	while (n)
//	{
//		r++;
//		n &= (n - 1);
//	}
//	return r;
//}
//int NumberOf1(int n)
//{
//	int r = 0;
//	while (n)
//	{
//		n -= (n & ((~n) + 1));
//		r++;
//	}
//	return r;
//}
//bool is_pow(int n)
//{
//	for (int i = 0; i < 32; i++)
//	{
//		if ((1 << i) == n)
//			return true;
//	}
//	return false;
//}
//bool is_pow(int n)
//{
//	return !(n & (n - 1));
//}
//int NumberOf1(int n)
//{
//	int r = 0;
//	while (n)
//	{
//		n &= (n - 1);
//		r++;
//	}
//	return r;
//}
//void PrintOddBit(int n)
//{
//	for (int i = 30; i >= 0; i -= 2)
//	{
//		if ((n << i) & 1)
//			printf("%d ", 1);
//		else
//			printf("%d ", 0);
//	}
//}
//void PrintEveBit(int n)
//{
//	for (int i = 31; i >= 1; i -= 2)
//	{
//		if ((1 << i) & n)
//		{
//			printf("%d ", 1);
//		}
//		else
//		{
//			printf("%d ", 0);
//		}
//	}
//}
//char* MyStrcpy(char* dst, const char* src)
//{
//	assert(dst != NULL && src != NULL);
//	char* cp = dst;
//	while ((*cp++ = *src++) != '\0')
//	{
//		;
//	}
//	return dst;
//}
//size_t MyStrlen(const char* str)
//{
//	assert(str != NULL);
//	if (*str)
//		return (1 + MyStrlen(1 + str));
//	return 0;
//}
//int main()
//{
//	//const int num = 10;
//	////num = 20;//err
//	//int const * p = &num;
//	//char arr[] = "abc";
//	//std::cout << strlen(arr) << std::endl;
//	//printf("%d\n", MyStrlen(""));
//	//printf("%d\n", MyStrlen("a"));
//	//extern size_t my_strlen(const char* str);
//	//int num = 10;
//	//int* p = &num;
//	//*p = 20;
//	//printf("%d\n", num);
//	//printf("%d\n", *p);
//	//char arr1[20] = "xxxxxxxxxxxxx";
//	//char arr2[] = "hello";
//	//std::cout << MyStrcpy(arr1, arr2) << std::endl;
//	//int arr[] = { 1, 2, 3, 4, 5 };
//	//short* p = (short*)arr;
//	//int n = sizeof(arr) / sizeof(arr[0]);
//	//for (int i = 0; i < 4; i++)
//	//{
//	//	*(p + i) = 0;
//	//}
//	//for (int i = 0; i < n; i++)
//	//{
//	//	std::cout << arr[i] << " ";
//	//}
//	//std::cout << std::endl;
//	//int a = 10;
//	//int b = 20;
//	//a = a ^ b;
//	//b = a ^ b;
//	//a = a ^ b;
//	//std::cout << a << " " << b << std::endl;
//	//int n = 0;
//	//std::cin >> n;
//	//PrintOddBit(n);
//	//putchar(10);
//	//PrintEveBit(n);
//	//int m = 0;
//	//int n = 0;
//	//std::cin >> m >> n;
//	//int r = 0;
//	//for (int i = 0; i < 32; i++)
//	//{
//	//	if (((1 << i) & m) != ((1 << i) & n))
//	//		r++;
//	//}
//	//std::cout << r << std::endl;
//	//int m = 0;
//	//int n = 0;
//	//scanf("%d%d", &m, &n);
//	//int t = m ^ n;
//	//std::cout << "diff num is : " << NumberOf1(t) << std::endl;
//	//int n = 0;
//	//std::cin >> n;
//	//if (is_pow(n))
//	//{
//	//	std::cout << "ok" << std::endl;
//	//}
//	//else
//	//{
//	//	std::cout << "no" << std::endl;
//	//}
//	//int n = 0;
//	//scanf("%d", &n);
//	//std::cout << NumberOf1(n) << std::endl;
//	//std::cout << my_strlen("") << std::endl;
//	//std::cout << my_strlen("abcd") << std::endl;
//	//int a, b, c;
//	//a = 5;
//	//c = ++a;
//	//b = ++c, c++, ++a, a++;
//	//b += a++ + c;
//	//printf("a = %d, b = %d, c = %d\n", a, b, c);
//	return 0;
//}
//int cnt = 0;
//int fib(int n)
//{
//	cnt++;
//	if (0 == n)
//		return 1;
//	else if (1 == n)
//		return 2;
//	else
//		return fib(n - 1) + fib(n - 2);
//}
//int a = 1;
//void test()
//{
//	int a = 2;
//	a += 1;
//}
//int gcd(int a, int b)
//{
//	return b ? gcd(b, a % b) : a;
//}
//int lcm(int r, int a, int b)
//{
//	return a / r * b;
//}
//void reverse(char* pl, char* pr)
//{
//	assert(pl && pr);
//	if (pr - pl <= 1)
//		return;
//	while (pl < pr)
//	{
//		char t = *pl;
//		*pl = *pr;
//		*pr = t;
//		pl++, pr--;
//	}
//}
//int main()
//{
//	//char arr[105] = "";
//	//scanf("%[^\n]", arr);
//	//reverse(arr, arr + strlen(arr) - 1);
//	//char* curr = arr;
//	//while (*curr)
//	//{
//	//	char* t = curr;
//	//	while (*curr != ' ' && *curr)
//	//		curr++;
//	//	reverse(t, curr - 1);
//	//	curr++;
//	//}
//	//puts(arr);
//	//int a = 0;
//	//int b = 0;
//	//std::cin >> a >> b;
//	//int r1 = gcd(a, b);
//	//int r2 = lcm(r1, a, b);
//	//std::cout << r1 << " " << r2 << std::endl;
//	//int y = 1009, * p = &y;
//	//int year = 1009;
//	//int* p = &year;
//	//int x = 0;
//	//int y = 0;
//	//int l = 0;
//	//for (x = 0, y = 0; (y = 123) && (x < 4); x++)
//	//{
//	//	l++;
//	//}
//	//printf("%d\n", l);
//	//int a = 0, c = 0;
//	//do
//	//{
//	//	--c;
//	//	a = a - 1;
//	//} while (a > 0);
//	//printf("%d %d\n", a, c);
//	//test();
//	//std::cout << a << std::endl;
//	//int a = 10;
//	//int b = 20;
//	//std::cout << a << std::endl;
//	//int i = 10;
//	//int j = 20;
//	//int k = 3;
//	//k *= (i + j);
//	//std::cout << k << std::endl;
//	//int x = 1;
//	//do
//	//{
//	//	printf("%2d\n", x++);
//	//} while (x--);
//	//fib(8);
//	//printf("%d\n", cnt);
//	return 0;
//}
//int main()
//{
//	int i, h;
//	float o, p;
//	printf("请选择红包发放形式:\n");
//	printf("1.均分  2.随机\n");
//	scanf("%d", &h);
//	if (h == 1)
//	{
//		printf("请输入红包总金额:\n");
//		scanf("%f", &o);
//		printf("请输入分发红包个数:\n");
//		scanf("%f", &p);
//		for (int i = 1; i <= (int)(p + 1e-6); i++)
//		{
//			printf("恭喜你抢到了第%d个红包:金额为%.2f\n", i, o / p);
//		}
//	}
//	return 0;
//}
//bool check_sys_endian_1(int a)
//{
//	return *(char*)(&a);
//}
//bool check_sys_endian_2()
//{
//	union
//	{
//		char _c;
//		int _in;
//	} U;
//	U._in = 1;
//	return U._c;
//}
//unsigned char i = 0;
//int main()
//{
//	//int n = 9;
//	//float* pf = (float*)(&n);
//	//printf("%d\n", n);
//	//printf("%f\n", *pf);
//	//*pf = 9.0f;
//	//printf("%d\n", n);
//	//printf("%f\n", *pf);
//	//for (i = 0; i <= 255; i++)
//	//{
//	//	printf("hello world!\n");
//	//}
//	//INT_MAX;
//	//char a[1000];
//	//int i;
//	//for (i = 0; i < 1000; i++)
//	//	a[i] = -1 - i;
//	//std::cout << strlen(a) << std::endl;
//	//unsigned int i;
//	//for (i = 9; i >= 0; i--)
//	//	printf("%u\n", i);
//	//int i = -20;
//	//unsigned int j = 10;
//	//printf("%u\n", i + j);
//	//char a = -129;
//	//printf("%u\n", a);
//	//char a = 129;
//	//printf("%u\n", a);
//	//char a = 128;
//	//printf("%u\n", a);
//	//char a = -128;
//	//printf("%u\n", a);
//	//char a = -1;
//	//signed char b = -1;
//	//unsigned char c = -1;
//	//printf("%d %d %d\n", a, b, c);
//	//char ch = -129;
//	//printf("%d\n", ch);
//	//if (check_sys_endian_2())
//	//{
//	//	printf("small endian!\n");
//	//}
//	//else
//	//{
//	//	printf("big endian!\n");
//	//}
//	//int a = 1;
//	//if (check_sys_endian_1(a))
//	//{
//	//	printf("small endian!\n");
//	//}
//	//else
//	//{
//	//	printf("big endian!\n");
//	//}
//	//int a = -10;
//	//int b = 10;
//	//int arr[10];//int[10]
//	//int arr2[5];//int[5]
//	//int i = 0;
//	//int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//printf("%p\n", &i);
//	//printf("%p\n", &arr[9]);
//	//for (i = 0; i <= 12; i++)
//	//{
//	//	arr[i] = 0;
//	//	printf("hehe\n");
//	//}
//	return 0;
//}
//int arr[10];
//int(*fun(int i))[10]
//{
//	for (int j = 0; j < 10; j++)
//		arr[j] = i;
//	return &arr;
//}
//int main()
//{
//	int(*pt)[10] = fun(2);
//	int* p = (int*)pt;
//	for (int i = 0; i < 10; i++)
//		std::cout << arr[i] << " ";
//	std::cout << std::endl;
//	return 0;
//}
//void print1(int p[][5], int r)
//{
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			printf("%d ", p[i][j]);
//		}
//		printf("\n");
//	}
//}
//void print2(int(*p)[5], int r)
//{
//	assert(p);
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			//printf("%d ", p[i][j]);
//			printf("%d ", *(*(p + i) + j));
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	//int arr[3][5] = { { 1, 2, 3, 4, 5 }, { 2, 3, 4, 5, 6 }, { 3, 4, 5, 6, 7 } };
//	//print1(arr, 3);
//	//printf("\n");
//	//print2(arr, 3);
//	//int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//int(*pa)[10] = &arr;
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	printf("%d ", (*pa)[i]);
//	//}
//	//int arr[10] = { 0 };
//	//int* p1 = arr;
//	//int(*p2)[10] = &arr;
//	//printf("%p\n", p1);
//	//printf("%p\n", p1 + 1);
//	//printf("%p\n", p2);
//	//printf("%p\n", p2 + 1);
//	//int arr[10] = { 1, 2, 3, 4, 5 };
//	//int(*parr)[10] = &arr;
//	//int a = 10;
//	//int* pa = &a;
//	//char ch = 'w';
//	//char* pc = &ch;
//	//double* d[5];
//	//double* (*pd)[5] = &d;
//	//float f = 9.0f;
//	//int* p = (int*)& f;
//	//printf("%d\n", *p);
////	int a[5] = { 1, 2, 3, 4, 5 };
////	int b[] = { 2, 3, 4, 5, 6 };
////	int c[] = { 3, 4, 5, 6, 7 };
////	int* arr[3] = { a, b, c };
////	for (int i = 0; i < 3; i++)
////	{
////		for (int j = 0; j < 5; j++)
////		{
////			printf("%d ", *(arr[i] + j));
////			printf("%d ", arr[i][j]);
////		}
////		printf("\n");
////	}
//	//int a = 10;
//	//int b = 20;
//	//int c = 30;
//	//int* arr[3] = { &a, &b, &c };
//	//for (int i = 0; i < 3; i++)
//	//{
//	//	printf("%d ", *(arr[i]));
//	//}
//	//int* arr[3];
//	//char str1[] = "hello world";
//	//char str2[] = "hello world";
//	//const char* str3 = "hello world";
//	//const char* str4 = "hello world";
//	////*str3 = 'w';//err
//	//if (str1 == str2)
//	//	std::cout << "str1 and str2 are same" << std::endl;
//	//else
//	//	std::cout << "str1 and str2 are not same" << std::endl;
//	//if (str3 == str4)
//	//	std::cout << "str3 and str4 are same" << std::endl;
//	//else
//	//	std::cout << "str3 and str4 are not same" << std::endl;
//	////float f = 5.5f;
//	//char ch = 'q';
//	//char* pc = &ch;
//	//const char* ps = "hello world";
//	//char arr[] = "hello world";
//	////*ps = 'w';
//	//arr[0] = 'w';
//	//puts(arr);
//	//printf("%c\n", *ps);
//	//printf("%s\n", ps);
//	//printf("%s\n", arr);
//	return 0;
//}
//int i;
//const double Eps = 1e-6;
//struct stu
//{
//	int num;
//	char name[10];
//	int age;
//};
//void fun(struct stu* p)
//{
//	printf("%s\n", (*p).name);
//}
//int main()
//{
//	struct stu students[3] = { { 9801, "zhang", 20 }, { 9802, "wang", 19 }, { 9803, "zhao", 18 } };
//	fun(students + 1);
//	//unsigned long pulArray[] = { 6, 7, 8, 9, 10 };
//	//unsigned long* pulPtr = pulArray;
//	//*(pulPtr + 3) += 3;
//	//printf("%d, %d\n", *pulPtr, *(pulPtr + 3));
//	//for (int i = 1; i <= 100000; i++)
//	//{
//	//	int t = i;
//	//	int c = 0;
//	//	int s = 0;
//	//	while (t)
//	//	{
//	//		c++;
//	//		t /= 10;
//	//	}
//	//	t = i;
//	//	while (t)
//	//	{
//	//		s += (int)(pow(t % 10, c) + Eps);
//	//		t /= 10;
//	//	}
//	//	if (s == i)
//	//	{
//	//		std::cout << s << std::endl;
//	//	}
//	//}
//	//int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//int n = sizeof(arr) / sizeof(arr[0]);
//	//int* p = arr;
//	//int* pend = arr + n - 1;
//	//while (p <= pend)
//	//{
//	//	std::cout << *p++ << " ";
//	//}
//	//std::cout << std::endl;
//	//p = arr;
//	//for (int i = 0; i < n; i++)
//	//{
//	//	printf("%d ", *(p + i));
//	//}
//	//putchar(10);
//	//std::cout << "c plus plus" << std::endl;
//	//int n = 0;
//	//std::cin >> n;
//	//int s = n;
//	//int t = n;
//	//for (int i = 1; i < 5; i++)
//	//{
//	//	t = t * 10 + n;
//	//	s += t;
//	//}
//	//std::cout << s << std::endl;
//	//i--;
//	//if (i > sizeof(i))
//	//{
//	//	printf(">\n");
//	//}
//	//else
//	//{
//	//	printf("<\n");
//	//}
//	return 0;
//}
//struct S
//{
//	int a;
//	int b;
//};
//int main()
//{
//	//struct S a, * p = &a;
//	//a.a = 99;
//	//printf("%d\n", a.a);
//	//printf("%d\n", p->a);
//	//printf("%d\n", (*p).a);
//	return 0;
//}
//void reverse(char* str)
//{
//	assert(str != NULL);
//	int l = 0, r = strlen(str) - 1;
//	if (r - l <= 0)
//		return;
//	while (l < r)
//	{
//		char t = str[l];
//		str[l] = str[r];
//		str[r] = t;
//		l++, r--;
//	}
//}
//bool is_odd(int n)
//{
//	return n & 0x01;
//}
//void swap(int* p1, int* p2)
//{
//	assert(p1 != NULL && p2 != NULL);
//	*p1 ^= *p2;
//	*p2 ^= *p1;
//	*p1 ^= *p2;
//}
//void move_arr(int* p, int n, bool(*funp)(int))
//{
//	assert(p != NULL && funp != NULL);
//	int* pB = p, * pE = p + n - 1;
//	while (pB < pE)
//	{
//		while ((pB < pE) && (funp(*pB)))	pB++;
//		while ((pB < pE) && (!funp(*pE)))	pE--;
//		if (pB < pE)
//		{
//			swap(pB, pE);
//			pB++, pE--;
//		}
//	}
//}
//void print_arr(int* p, int n)
//{
//	assert(p != NULL);
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", *p++);
//	}
//	printf("\n");
//}
//int main()
//{
//	//char k = 0;
//	//for (k = 'a'; k <= 'd'; k++)
//	//{
//	//	if ((k != 'a') + (k == 'c') + (k == 'd') + (k != 'd') == 3)
//	//	{
//	//		break;
//	//	}
//	//}
//	//int arr[10][10] = { 0 };
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	arr[i][0] = arr[i][i] = 1;
//	//}
//	//for (int i = 2; i < 10; i++)
//	//{
//	//	for (int j = 1; j < i; j++)
//	//	{
//	//		arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
//	//	}
//	//}
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	for (int j = 0; j <= i; j++)
//	//	{
//	//		printf("%d ", arr[i][j]);
//	//	}
//	//	putchar(10);
//	//}
//	//printf("%c\n", k);
//	//unsigned int a = 0x1234;
//	//unsigned char b = *(unsigned char*)(&a);
//	//printf("%#X\n", b);
//	//int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//int n = sizeof(arr) / sizeof(arr[0]);
//	//print_arr(arr, n);
//	//move_arr(arr, n, is_odd);
//	//print_arr(arr, n);
//	//int m = 0;
//	//scanf("%d", &m);
//	//if (m > 0)
//	//	printf("%d\n", m * 2 - 1);
//	//int m = 0;
//	//std::cin >> m;
//	//int t = m / 1;
//	//int e = t;
//	//while (e > 1)
//	//{
//	//	t += e / 2;
//	//	e = e % 2 + e / 2;
//	//}
//	//std::cout << t << std::endl;
//	//int line = 0;
//	//scanf("%d", &line);
//	//for (int i = 0; i < line; i++)
//	//{
//	//	for (int j = 0; j < line - 1 - i; j++)
//	//	{
//	//		printf(" ");
//	//	}
//	//	for (int j = 0; j < 2 * (i + 1) - 1; j++)
//	//	{
//	//		printf("*");
//	//	}
//	//	printf("\n");
//	//}
//	//for (int i = 0; i < line - 1; i++)
//	//{
//	//	for (int j = 0; j < i + 1; j++)
//	//	{
//	//		printf(" ");
//	//	}
//	//	for (int j = 0; j < (line - 1) * 2 - 1 - 2 * i; j++)
//	//	{
//	//		printf("*");
//	//	}
//	//	printf("\n");
//	//}
//	//char arr[] = "abcdef";
//	//reverse(arr);
//	//puts(arr);
//	//unsigned char a = 200;
//	//unsigned char b = 100;
//	//unsigned char c = a + b;
//	//printf("%d %d\n", a + b, c);
//	return 0;
//}
//void print(int arr[], int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void test(char* p) {}
//void test(int** pp) 
//{
//	**pp = 20;
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//void test(char* str) {}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	//void( * signal(int, void(*)(int)))(int);//函数声明
//	//typedef void(*pf)(int);
//	//typedef unsigned int u_int;
//	//pf func(int, pf);
//	//( * ( void (*) () ) 0 ) ();//函数调用
//	//int(*pf)(int, int) = &Add;
//	//int(*pff)(int, int) = Add;//Add == pff
//	//int ret = (*pff)(2, 3);
//	////int ret = *pff(2, 3);//err
//	//ret = pff(2, 3);
//	//ret = Add(2, 3);
//	//ret = (***pff)(2, 3);
//	//std::cout << ret << std::endl;
//	//void(*pf)(char*) = &test;
//	//int(*pf1)(int, int) = Add;
//	//int(*pf2)(int, int) = &Add;
//	//printf("%p, %p, %p, %p\n", Add, &Add, pf1, pf2);
//	//std::cout << Add(2, 3) << std::endl;
//	//std::cout << (&Add)(2, 3) << std::endl;
//	//std::cout << pf1(2, 3) << std::endl;
//	//std::cout << pf2(2, 3) << std::endl;
//	//int a = 10;
//	//int* pa = &a;
//	//char ch = 'w';
//	//char* pc = &ch;
//	//int arr[10] = { 0 };
//	//int(*parr)[10] = &arr;
//	//int a = 10;
//	//int* pa = &a;
//	//int** ppa = &pa;
//	//test(&pa);
//	//test(ppa);
//	//int* arr[10] = { NULL };
//	//test(arr);
//	//printf("%d\n", a);
//	//int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//int* p = arr;
//	//int sz = sizeof(arr) / sizeof(*arr);
//	//print(arr, sz);
//	//char ch = 'w';
//	//char* p1 = &ch;
//	//test(&ch);
//	//test(p1);
////	int a = 0;
////	int b = 0;
////	int c = 0;
////	int d = 0;
////	int e = 0;
////	for (a = 1; a <= 5; a++)
////	{
////		for (b = 1; b <= 5; b++)
////		{
////			for (c = 1; c <= 5; c++)
////			{
////				for (d = 1; d <= 5; d++)
////				{
////					for (e = 1; e <= 5; e++)
////					{
////						if ((a * b * c * d * e == 120)
////							&& ((b == 2) + (a == 3) == 1)
////							&& ((b == 2) + (e == 4) == 1)
////							&& ((c == 1) + (d == 3) == 1)
////							&& ((e == 4) + (a == 1) == 1) 
////							&& ((c == 5) + (d == 3) == 1))
////						{
////							goto End;
////						}
////					}
////				}
////			}
////		}
////	}
////End:
////	printf("a = %d, b = %d, c = %d, d = %d, e = %d\n", a, b, c, d, e);
//	return 0;
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int main()
//{
//	//int(*pf1)(int, int) = Add;
//	//int(*pf2)(int, int) = Sub;
//	//int(*pf3)(int, int) = Mul;
//	//int(*fparr[])(int, int) = { pf1, pf2, pf3 };
//	return 0;
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//void menu()
//{
//	printf("**************************************\n");
//	printf("*****     1.Add      2.Sub       *****\n");
//	printf("*****     3.Mul      4.Div       *****\n");
//	printf("*****           0.Exit           *****\n");
//	printf("**************************************\n");
//}
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请输入您的选择:>");
//		scanf("%d", &input);
//		int x = 0;
//		int y = 0;
//		int ret = 0;
//		switch (input)
//		{
//		case 0:
//			printf("Exiting....\n");
//			break;
//		case 1:
//			printf("请输入oprands:>");
//			scanf("%d%d", &x, &y);
//			ret = Add(x, y);
//			printf("%d\n", ret);
//			break;
//		case 2:
//			printf("请输入oprands:>");
//			scanf("%d%d", &x, &y);
//			ret = Sub(x, y);
//			printf("%d\n", ret);
//			break;
//		case 3:
//			printf("请输入oprands:>");
//			scanf("%d%d", &x, &y);
//			ret = Mul(x, y);
//			printf("%d\n", ret);
//			break;
//		case 4:
//			printf("请输入oprands:>");
//			scanf("%d%d", &x, &y);
//			ret = Div(x, y);
//			printf("%d\n", ret);
//			break;
//		default:
//			printf("Input Data Err.\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//void menu()
//{
//	printf("*********************************************\n");
//	printf("*****          1.Add  2.Sub             *****\n");
//	printf("*****          3.Mul  4.Div             *****\n");
//	printf("*****             0.Eixt                *****\n");
//	printf("*********************************************\n");
//}
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请输入您的选择:>");
//		scanf("%d", &input);
//		int(*fparr[])(int, int) = { NULL, Add, Sub, Mul, Div };
//		int sz = sizeof(fparr) / sizeof(*fparr);
//		int ret = 0;
//		if (input == 0)
//		{
//			printf("Exiting...\n");
//			break;
//		}
//		else if (input >= 1 && input < sz)
//		{
//			int x = 0;
//			int y = 0;
//			printf("请输入oprands:>");
//			scanf("%d%d", &x, &y);
//			ret = (*fparr[input])(x, y);
//			printf("%d\n", ret);
//		}
//		else
//		{
//			printf("Input Data Err!\n");
//		}
//	} while (input);
//	return 0;
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//void menu()
//{
//	printf("**************************\n");
//	printf("**** 1. Add    2. Sub ****\n");
//	printf("**** 3. Mul    4. Div ****\n");
//	printf("****     0. Exit      ****\n");
//	printf("**************************\n");
//}
//int Calc(int(*funp)(int, int))
//{
//	assert(funp != NULL);
//	int x = 0;
//	int y = 0;
//	printf("请输入oprands:>");
//	scanf("%d%d", &x, &y);
//	return (*funp)(x, y);
//}
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请输入您的选择:>");
//		scanf("%d", &input);
//		int ret = 0;
//		switch (input)
//		{
//		case 0:
//			printf("Exiting....\n");
//			break;
//		case 1:
//			printf("%d\n", Calc(Add));
//			break;
//		case 2:
//			printf("%d\n", Calc(Sub));
//			break;
//		case 3:
//			printf("%d\n", Calc(Mul));
//			break;
//		case 4:
//			printf("%d\n", Calc(Div));
//			break;
//		default:
//			printf("Input Data Err.\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//void print(int* p, int sz)
//{
//	assert(p);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *p++);
//	}
//	printf("\n");
//}
//void bubble_sort(int* p, int sz)
//{
//	assert(p);
//	bool flag = true;
//	for (int i = 0; i < sz - 1; i++)
//	{
//		flag = true;
//		for (int j = 0; j < sz - 1 - i; j++)
//		{
//			if (p[j] > p[j + 1])
//			{
//				int t = p[j];
//				p[j] = p[j + 1];
//				p[j + 1] = t;
//				flag = false;
//			}
//		}
//		if (flag)
//			break;
//	}
//}
//int main()
//{
//	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//	int sz = sizeof(arr) / sizeof(*arr);
//	print(arr, sz);
//	bubble_sort(arr, sz);
//	print(arr, sz);
//	return 0;
//}
//int cmp_str(const void* e1, const void* e2)
//{
//	assert(e1 && e2);
//	return -strcmp(*(char**)e1, *(char**)e2);
//}
//void print_arr(int arr[], int sz)
//{
//	assert(arr);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *arr++);
//	}
//	printf("\n");
//}
//int cmp_int(const void* e1, const void* e2)
//{
//	assert(e1 && e2);
//	//return *(int*)e1 - *(int*)e2;//升序
//	return -(*(int*)e1 - *(int*)e2);//降序
//}
//struct Stu
//{
//	char name[20];
//	int age;
//};
//int cmp_by_name(const void* e1, const void* e2)
//{
//	assert(e1 && e2);
//	return strcmp((((struct Stu*)e1)->name), ((struct Stu*)e2)->name);
//	//return -strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//int cmp_by_age(const void* e1, const void* e2)
//{
//	assert(e1 && e2);
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//	//return -(((struct Stu*)e1)->age - ((struct Stu*)e2)->age);
//}
//int main()
//{
//	//void qsort(void* base, size_t count, size_t ele, int (*cmp)(const void*, const void*));
//	//char* arr[] = { "Microsoft", "Apple", "Google", "IBM", "Huawei", "Facebook" };
//	//int n = sizeof(arr) / sizeof(*arr);
//	//qsort(arr, n, sizeof(*arr), cmp_str);
//	//int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
//	//int n = sizeof(arr) / sizeof(*arr);
//	//print_arr(arr, n);
//	//qsort(arr, n, sizeof(*arr), cmp_int);
//	//print_arr(arr, n);
//	//struct Stu s[] = { { "zhangsan", 30 }, { "lisi", 34}, { "wangwu", 20 } };
//	//int n = sizeof(s) / sizeof(*s);
//	//qsort(s, n, sizeof(*s), cmp_by_name);
//	//qsort(s, n, sizeof(*s), cmp_by_age);
//	return 0;
//}
//void swap(char* p1, char* p2, size_t e)
//{
//	assert(p1 && p2);
//	int c = 0;
//	while (c < e)
//	{
//		char t = *p1;
//		*p1 = *p2;
//		*p2 = t;
//		p1++, p2++;
//		c++;
//	}
//}
//void bubble_sort(void* base, size_t c, size_t e, int(*cmp)(const void*, const void*))
//{
//	assert(base && cmp);
//	bool flag = true;
//	for (size_t i = 0; i < c - 1; i++)
//	{
//		flag = true;
//		for (size_t j = 0; j < c - 1 - i; j++)
//		{
//			if (cmp((char*)base + j * e, (char*)base + (j + 1) * e) > 0)
//			{
//				flag = false;
//				swap((char*)base + j * e, (char*)base + (j + 1) * e, e);
//			}
//		}
//		if (flag)
//			break;
//	}
//}
//int cmp_int(const void* e1, const void* e2)
//{
//	assert(e1 && e2);
//	return *(int*)e1 - *(int*)e2;
//}
//int cmp_str(const void* e1, const void* e2)
//{
//	assert(e1 && e2);
//	return strcmp(*(char**)e1, *(char**)e2);
//}
//int main()
//{
//	//const char* arr[] = { "China", "America", "Canada" };
//	//bubble_sort(arr, sizeof(arr) / sizeof(*arr), sizeof(*arr), cmp_str);
//	//int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
//	//int n = sizeof(arr) / sizeof(*arr);
//	//bubble_sort(arr, n, sizeof(*arr), cmp_int);
//	return 0;
//}
//int main()
//{
//	//int a = 10;
//	//char ch = 'w';
//	//void* p = &a;
//	//p = &ch;
//	//*p;//err
//	//p++;//err
//	//int arr[] = { 100, 2, 3, 4, 5, 6, 7, 8, 9, -10 };
//	//int n = sizeof(arr) / sizeof(*arr);
//	//int min = arr[0];
//	//int max = arr[0];
//	//for (int i = 1; i < n; i++)
//	//{
//	//	if (arr[i] < min)
//	//		min = arr[i];
//	//	if (arr[i] > max)
//	//		max = arr[i];
//	//}
//	//printf("min = %d, max = %d\n", min, max);
//	return 0;
//}
//int main()
//{
//	//const char* p = "abcdef";
//	//printf("%d\n", strlen(p));
//	//printf("%d\n", strlen(p + 1));
//	//printf("%d\n", strlen(*p));
//	//printf("%d\n", strlen(p[0]));
//	//printf("%d\n", strlen(&p));
//	//printf("%d\n", strlen(&p + 1));
//	//printf("%d\n", strlen(&p[0] + 1));
//	//printf("%d\n", sizeof(p));
//	//printf("%d\n", sizeof(p + 1));
//	//printf("%d\n", sizeof(*p));
//	//printf("%d\n", sizeof(p[0]));
//	//printf("%d\n", sizeof(&p));
//	//printf("%d\n", sizeof(&p + 1));
//	//printf("%d\n", sizeof(&p[0] + 1));
//	//char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
//	//printf("%d\n", strlen(arr));
//	//printf("%d\n", strlen(arr + 0));
//	////printf("%d\n", strlen(*arr));
//	////printf("%d\n", strlen(arr[1]));
//	//printf("%d\n", strlen(&arr));
//	//printf("%d\n", strlen(&arr + 1));
//	//printf("%d\n", strlen(&arr[0] + 1));
//	//printf("%d\n", sizeof(arr));
//	//printf("%d\n", sizeof(arr + 0));
//	//printf("%d\n", sizeof(*arr));
//	//printf("%d\n", sizeof(arr[1]));
//	//printf("%d\n", sizeof(&arr));
//	//printf("%d\n", sizeof(&arr + 1));
//	//printf("%d\n", sizeof(&arr[0] + 1));
//	//int a[] = { 1, 2, 3, 4 };
//	//printf("%d\n", sizeof(a));
//	//printf("%d\n", sizeof(a + 0));
//	//printf("%d\n", sizeof(*a));
//	//printf("%d\n", sizeof(a + 1));
//	//printf("%d\n", sizeof(a[1]));
//	//printf("%d\n", sizeof(&a));
//	//printf("%d\n", sizeof(*&a));
//	//printf("%d\n", sizeof(&a + 1));
//	//printf("%d\n", sizeof(&a[0]));
//	//printf("%d\n", sizeof(&a[0] + 1));
//	return 0;
//}
//int main()
//{
//	int a[3][4] = { 0 };
//	//printf("%d\n", sizeof(a));
//	//printf("%d\n", sizeof(a[0][0]));
//	//printf("%d\n", sizeof(a[0]));
//	//printf("%d\n", sizeof(a[0] + 1));
//	//printf("%d\n", sizeof(*(a[0] + 1)));
//	//printf("%d\n", sizeof(a + 1));
//	//printf("%d\n", sizeof(*(a + 1)));
//	//printf("%d\n", sizeof(&a[0] + 1));
//	//printf("%d\n", sizeof(*(&a[0] + 1)));
//	//printf("%d\n", sizeof(*a));
//	//printf("%d\n", sizeof(a[3]));
//	//printf("%d\n", sizeof(a[-1]));
//	//short s = 5;
//	//int aa = 4;
//	//printf("%d\n", sizeof(s = aa + 6));
//	//printf("%d\n", s);
//	return 0;
//}
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//} *p;
//int main()
//{
//	//char* c[] = { "ENTER", "NEW", "POINT", "FIRST" };
//	//char** cp[] = { c + 3, c + 2, c + 1, c };
//	//char*** cpp = cp;
//	//printf("%s\n", **++cpp);
//	//printf("%s\n", *-- * ++cpp + 3);
//	//printf("%s\n", *cpp[-2] + 3);
//	//printf("%s\n", cpp[-1][-1] + 1);
////	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
////	int* ptr1 = (int*)(&aa + 1);
////	int* ptr2 = (int*)(*(aa + 1));
////	printf("%d, %d\n", *(ptr1 - 1), *(ptr2 - 1));
////	char* a[] = { "work", "at", "alibaba" };
////	char** ppa = a;
////	ppa++;
////	printf("%s", *ppa);
//	//int a[5][5];
//	//int(*p)[4] = a;
//	//printf("%p, %d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	//int a[3][2] = { (0, 1), (2, 3), (4, 5) };
//	//int* p = a[0];
//	//printf("%d", p[0]);
//	//int a[4] = { 1, 2, 3, 4 };
//	//int* ptr1 = (int*)(&a + 1);
//	//int* ptr2 = (int*)((int)a + 1);
//	//printf("%x, %x\n", ptr1[-1], *ptr2);
//	//printf("%p\n", p + 0x1);
//	//printf("%p\n", (unsigned long)p + 0x1);
//	//printf("%p\n", (unsigned int*)p + 0x1);
//	//int a[5] = { 1, 2, 3, 4, 5 };
//	//int* ptr = (int*)(&a + 1);
//	//printf("%d, %d\n", *(a + 1), *(ptr - 1));
//	return 0;
//}
//int* f(int x, int y)
//{
//	return NULL;
//}
//int main()
//{
//	//int aa[2][5] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
//	//int* ptr1 = (int*)(&aa + 1);
//	//int* ptr2 = (int*)(*(aa + 1));
//	//printf("%d,%d\n", *(ptr1 - 1), *(ptr2 - 1));
//	//char arr[20] = "hello";
//	//puts(strcat(arr, " bit"));
//	//strcat(arr, arr);//err
//	//puts(strncat(arr, arr, 5));
//	//printf("%s\n", arr);
//	//int(*(*F)(int, int))(int);
//	//int(*(*F)(int, int)) = f;
//	return 0;
//}
//int main()
//{
//	int a[5] = { 5, 4, 3, 2, 1 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d, %d\n", *(a + 1), *(ptr - 1));
//	return 0;
//}
//int find(int(*p)[4], int r, int k, int* px, int* py)
//{
//	assert(p && px && py);
//	int row = 0;
//	int col = 3;
//	while (row < r && col >= 0)
//	{
//		if (p[row][col] < k)
//		{
//			row++;
//		}
//		else if (p[row][col] > k)
//		{
//			col--;
//		}
//		else
//		{
//			*px = row;
//			*py = col;
//			return 0;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	//int arr[3][4] = { { 1, 2, 3, 4 }, { 3, 4, 6, 8 }, { 5, 6, 9, 11 } };
//	//for (int k = 0; k < 13; k++)
//	//{
//	//	int x = 0;
//	//	int y = 0;
//	//	if (find(arr, 3, k, &x, &y) == -1)
//	//	{
//	//		printf("%d === find none!\n", k);
//	//	}
//	//	else
//	//	{
//	//		printf("%d --- x = %d, y = %d\n", k, x, y);
//	//	}
//	//}
//	return 0;
//}
//void left_rotate1(char* str, int l, int k)
//{
//	assert(str);
//	k %= l;
//	if (k)
//	{
//		while (k--)
//		{
//			char t = str[0];
//			for (int i = 0; i < l - 1; i++)
//			{
//				str[i] = str[i + 1];
//			}
//			str[l - 1] = t;
//		}
//	}
//}
//void reverse(char* str1, char* str2)
//{
//	assert(str1 && str2);
//	while (str1 < str2)
//	{
//		char t = *str1;
//		*str1 = *str2;
//		*str2 = t;
//		str1++, str2--;
//	}
//}
//void left_rotate2(char* str, int l, int k)
//{
//	assert(str);
//	k %= l;
//	if (k)
//	{
//		reverse(str, str + k - 1);
//		reverse(str + k, str + l - 1);
//		reverse(str, str + l - 1);
//	}
//}
//int main()
//{
//	char str[] = "abcdef";
//	int l = strlen(str);
//	int k = 0;
//	for (k = 0; k < 18; k++)
//	{
//		left_rotate2(str, l, k);
//		printf("%d --- ", k);
//		puts(str);
//	}
//	return 0;
//}
//void reverse(char* str1, char* str2)
//{
//	assert(str1 && str2);
//	while (str1 < str2)
//	{
//		char t = *str1;
//		*str1 = *str2;
//		*str2 = t;
//		str1++, str2--;
//	}
//}
//void left_rotate2(char* str, int l, int k)
//{
//	assert(str);
//	k %= l;
//	if (k)
//	{
//		reverse(str, str + k - 1);
//		reverse(str + k, str + l - 1);
//		reverse(str, str + l - 1);
//	}
//}
//bool is_rotate(char* s1, char* s2)
//{
//	int l1 = strlen(s1);
//	int l2 = strlen(s2);
//	if (l1 != l2)
//		return false;
//	for (int i = 0; i < l1; i++)
//	{
//		left_rotate2(s2, l2, 1);
//		if (!strcmp(s1, s2))
//			return true;
//	}
//	return false;
//}
//bool is_rotate(char* s1, char* s2)
//{
//	int l1 = strlen(s1);
//	int l2 = strlen(s2);
//	if (l1 == l2)
//	{
//		strncat(s1, s1, l1);
//		if (strstr(s1, s2))
//			return true;
//	}
//	return false;
//}
//int main()
//{
//	char str1[20] = "ABCDEF";
//	char str2[] = "CDDEFA";
//	if (is_rotate(str1, str2))
//	{
//		printf("Yes");
//	}
//	else
//	{
//		printf("No");
//	}
//	return 0;
//}
size_t my_strlen(const char* str)
{
	assert(str);
	size_t r = 0;
	while (*str++)
	{
		r++;
	}
	return r;
}
//size_t MyStrlen(const char* str)
//{
//	assert(str);
//	if (!*str)	return 0;
//	return 1 + MyStrlen(str + 1);
//}
//size_t _my_strlen(const char* str)
//{
//	assert(str);
//	const char* eos = str;
//	while (*eos++)
//	{
//		;
//	}
//	return eos - str - 1;
//}
//char* my_strcat(char* dst, const char* src)
//{
//	assert(dst && src);
//	char* cp = dst;
//	while (*cp)
//	{
//		cp++;
//	}
//	while ((*cp++ = *src++) != '\0')
//	{
//		;
//	}
//	return dst;
//}
//int my_strcmp(const char* s1, const char* s2)
//{
//	assert(s1 && s2);
//	while (*s1 == *s2)
//	{
//		if (*s1)
//			s1++, s2++;
//		else
//			return 0;
//	}
//	return *s1 - *s2;
//}
//const char* MyStrstr(const char* str, const char* subStr)
//{
//	assert(str && subStr);
//	if (!*subStr)	return str;
//	int lenStr = (int)strlen(str);
//	int lenSubStr = (int)strlen(subStr);
//	if (lenStr < lenSubStr)	return NULL;
//	for (int i = 0; i < lenStr; i++)
//	{
//		int j = 0;
//		for (j = 0; j < lenSubStr; j++)
//		{
//			if (str[i + j] != subStr[j])
//				break;
//		}
//		if (j == lenSubStr)
//			return str + i;
//	}
//	return NULL;
//}
//int main()
//{
//	//const char* str1 = "";
//	//const char* str2 = "bbc";
//	//printf("%s\n",strstr(str1, str2));
//	//printf("%p\n", MyStrstr(str1, str2));
//	//char arr[] = "tzh@tenglongedu.tech hehe";
//	//const char* p = "@. ";
//	//char tmp[100] = "";
//	//strcpy(tmp, arr);
//	//for (char* ret = strtok(tmp, p); ret; ret = strtok(NULL, p))
//	//{
//	//	puts(ret);
//	//}
//	//FILE* pf = fopen("test.txt", "r");
//	//if (NULL == pf)
//	//{
//	//	printf("%s\n", strerror(errno));
//	//	return errno;
//	//}
//	//fclose(pf);
//	//pf = NULL;
//	//printf("%s\n", strerror(0));
//	//printf("%s\n", strerror(2));
//	//printf("%s\n", strerror(3));
//	//printf("%s\n", strerror(4));
//	//printf("%s\n", strerror(5));
//	//const char* p = "aqcdef";
//	//const char* q = "abcqwert";
//	//int ret = strcmp(p, q);
//	//cout << ret << endl;
//	//ret = strncmp(p, q, 1);
//	//std::cout << ret << std::endl;
//	//char arr1[20] = "hello \0xxxxxx";
//	//char arr2[] = "world";
//	////printf(strncat(arr1, arr2, 3));
//	//printf(strncat(arr1, arr2, 9));
//	//printf(arr1);
//	//char arr1[20] = "abcdefghi";
//	//char arr2[] = "qwer";
//	////printf(strncpy(arr1, arr2, 6));
//	////printf(strncpy(arr1, arr2, 2));
//	//strcpy(arr1, arr2);
//	//printf("%s\n", arr1);
//	//const char* p = "abcdef";
//	//const char* q = "abcdef";
//	//int ret = my_strcmp(p, q);
//	//if (ret > 0)
//	//{
//	//	printf("p > q\n");
//	//}
//	//else if (ret == 0)
//	//{
//	//	printf("p == q\n");
//	//}
//	//else
//	//{
//	//	printf("p < q\n");
//	//}
//	//cout << my_strcmp("", "") << endl;
//	//cout << my_strcmp("a", "") << endl;
//	//cout << my_strcmp("", "b") << endl;
//	//int ret = strcmp("abbb", "abq");
//	//printf("%d\n", ret);
//	//ret = strcmp("aaa", "aaa");
//	//printf("%d\n", ret);
//	//if ("obc" > "abcdef") {}
//	//const char* p = "obc";
//	//const char* q = "abcdef";
//	//if (p > q)
//	//{
//	//	printf(">\n");
//	//}
//	//else
//	//{
//	//	printf("<=\n");
//	//}
//	//char arr[20] = "abcd";
//	////strcat(arr, arr);//err:死循环
//	//printf("%s\n", arr);
//	//char arr1[20] = "hello ";
//	//char arr2[] = "world";
//	//printf(my_strcat(arr1, arr2));
//	//const char* str = "xxxxxxxxxxxxxxxxxxxxxx";
//	//char arr[5] = "####";
//	////arr = "hello";//err
//	////const char* p = "hello";
//	//char arr2[] = { 'a', 'b', 'c' };
//	//const char* p = "hello world";
//	////strcpy(str, p);
//	//printf("%s\n", arr);
//	//strcpy(arr, "hello");
//	//if (my_strlen("abc") - my_strlen("abcdef") > 0)
//	//{
//	//	printf(">\n");
//	//}
//	//else
//	//{
//	//	printf("<=\n");
//	//}
//	//char arr[] = "abc";
//	//char arr2[] = { 'a', 'b', 'c' };
//	//int len = _my_strlen("");
//	//printf("%d\n", len);
//	return 0;
//}
//const char* MyStrstr(const char* str, const char* subStr)
//{
//	assert(str && subStr);
//	if (!*subStr)	return str;
//	int l1 = (int)strlen(str);
//	int l2 = (int)strlen(subStr);
//	if (l1 < l2)	return NULL;
//	for (int i = 0; i < l1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < l2; j++)
//		{
//			if (str[i + j] != subStr[j])
//				break;
//		}
//		if (j == l2)
//			return str + i;
//	}
//	return NULL;
//}
//void* MyMemcpy(void* dst, const void* src, size_t n)
//{
//	assert(dst && src);
//	char* cp = (char*)dst;
//	char* s = (char*)src;
//	while (n--)
//	{
//		*cp++ = *s++;
//	}
//	return dst;
//}
//void* MyMemmove(void* dst, const void* src, size_t n)
//{
//	assert(dst && src);
//	char* cp = (char*)dst;
//	char* s = (char*)src;
//	if (dst < src)
//	{
//		while (n--)
//		{
//			*cp++ = *s++;
//		}
//	}
//	else
//	{
//		while (n--)
//		{
//			cp[n] = s[n];
//		}
//	}
//	return dst;
//}
//void* MyMemset(void* p, int val, size_t n)
//{
//	assert(p);
//	void* r = p;
//	char* cp = (char*)p;
//	while (n--)
//	{
//		*cp++ = val;
//	}
//	return r;
//}
//struct Book
//{
//	char name[20];
//	int price;
//	char id[12];
//} b4, b5, b6;
//struct
//{
//	char c;
//	int i;
//	char ch;
//	double d;
//} s, *pss;
//struct
//{
//	char c;
//	int i;
//	char ch;
//	double d;
//} *ps;
//struct A
//{
//	int i;
//	char c;
//};
//struct B
//{
//	char c;
//	struct A sa;
//	double d;
//};
//struct N//err
//{
//	int d;
//	struct N n;
//};
//typedef struct _Node
//{
//	struct _Node* _next;
//	int _data;
//} Node;
//typedef struct//err
//{
//	int data;
//	Node* next;
//} Node;
//struct S
//{
//	char c;
//	int i;
//	double* d;
//} s1, s2;
//struct B
//{
//	double d;
//	struct S s;
//	char c;
//};
//struct S
//{
//	int i;
//	char c;
//};
//struct S2
//{
//	char c1;
//	int i;
//	char c2;
//};
//struct S3
//{
//	char c1;
//	char c2;
//	int i;
//};
//int main()
//{
//	//struct S3 s3 = { 0 };
//	//printf("%d %d\n", sizeof(struct S3), sizeof(s3));	
//	//struct S2 s2 = { 0 };
//	//printf("%d %d\n", sizeof(struct S2), sizeof(s2));
//	//struct S s = { 0 };
//	//printf("%d %d\n", sizeof(struct S), sizeof(s));
//	//struct B sb = { 3.14, { 'w', 10, NULL }, 'q' };
//	////printf("%.2lf %c %d %c", sb.d, sb.s.c, sb.s.i, sb.c);
//	//struct B* ps = &sb;
//	//printf("%.2lf %c %d %c %p\n", ps->d, ps->s.c, ps->s.i, ps->c, ps->s.d);
//	//struct S s3 = { 'x', 20 };
//	//Node n;
//	//ps = &s;//err
//	//pss = &s;//ok
//	//struct Book b1;
//	//struct Book b2;
//	//struct Book b3;
//	//int arr[10] = { 0 };
//	//memset(arr, 1, 20);
//	//float arr1[] = { 1.0f, 2.0f, 3.0f, 4.0f };
//	//float arr2[] = { 1.0f, 3.0f };
//	//int ret = memcmp(arr1, arr2, 8);
//	//printf("%d\n", ret);
//	//ret = memcmp(arr1, arr2, 4);
//	//printf("%d\n", ret);
//	//int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//int arr2[10] = { 0 };
//	//MyMemcpy(arr2, arr1, 20);
//	//int arr1[10] = { 1 ,2 ,3, 4, 5, 6, 7, 8, 9, 10 };
//	//memset(arr1, 1, 4);
//	//memmove(arr1 + 2, arr1, 20);
//	//memmove(arr1, arr1 + 2, 20);
//	//memcpy(arr1 + 2, arr1, 20);
//	//system("pause");
//	//int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//int arr2[20] = { 0 };
//	//strcpy();		char* strcpy(char* dst, const char* src);
//	//char arr[20] = { 0 };
//	//scanf("%s", arr);
//	//int i = 0;
//	//while (arr[i] != '\0')
//	//{
//	//	if (isupper(arr[i]))
//	//	{
//	//		arr[i] = tolower(arr[i]);
//	//	}
//	//	printf("%c ", arr[i]);
//	//	i++;
//	//}
//	//char ch = 'a';
//	//if (ch >= 'A' && ch <= 'Z') {}
//	//int ret = isdigit(ch);
//	//printf("%d\n", ret);
//	//ret = islower(ch);
//	//printf("%d\n", ret);
//	//FILE* pf = fopen("test.txt", "r");
//	//if (NULL == pf)
//	//{
//	//	//printf("%s\n", strerror(errno));
//	//	perror("fopen fail");
//	//	return errno;
//	//}
//	//fclose(pf);
//	//pf = NULL;
//	return 0;
//}
//struct S
//{
//	char c1;
//	int i;
//	char c2;
//};
//struct S2
//{
//	char c1;
//	int i;
//	double d;
//};
//struct S3
//{
//	char c1;
//	char c2;
//	int i;
//};
//struct S4
//{
//	double d;
//	char c;
//	int i;
//};
//struct S5
//{
//	char c1;
//	struct S4 s4;
//	double d;
//};
//#pragma pack(2)
//struct S5
//{
//	char c1;
//	int i;
//	char c2;
//};
//#pragma pack()
//#pragma pack(1)
//struct S
//{
//	char c1;
//	int i;
//	char c2;
//};
//#pragma pack()
//struct S
//{
//	char c1;
//	int i;
//	char c2;
//};
//#define OFFSETOF(s, m) (size_t)(&(((s*)0x0)->m) - 0x0)
//#define RED 5
//#define BLUE 9
//#define GREEN 8
//enum Color
//{
//	_RED = 5,
//	_GREEN = 8,
//	_BLUE
//};
//void menu()
//{
//	printf("**************************\n");
//	printf("***   1. add  2. sub   ***\n");
//	printf("***   3. mul  4. div   ***\n");
//	printf("***   0. exit          ***\n");
//	printf("**************************\n");
//}
//enum Option
//{
//	_EXIT,
//	_ADD,
//	_SUB,
//	_MUL,
//	_DIV
//};
//struct A
//{
//	int _a : 2;
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//};
//struct S
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//int main()
//{
//	//printf("%d\n", sizeof(struct A));
//	//struct S s = { 0 };
//	//s.a = 10;
//	//s.b = 12;
//	//s.c = 3;
//	//s.d = 4;
//	//cout << sizeof(s) << endl;
//	//int input = 0;
//	//do
//	//{
//	//	menu();
//	//	printf("请输入您的选择:>");
//	//	scanf("%d", &input);
//	//	switch (input)
//	//	{
//	//	case _EXIT:
//	//		break;
//	//	case _ADD:
//	//		break;
//	//	case _SUB:
//	//		break;
//	//	case _MUL:
//	//		break;
//	//	case _DIV:
//	//		break;
//	//	default:
//	//		break;
//	//	}
//	//} while (input);
//	//enum Color c = _BLUE;
//	////Color co = 0;//err,cpp语法检查严格,右边是int左边是Color
//	//printf("%d\n", _RED);
//	//printf("%d\n", _GREEN);
//	//printf("%d\n", _BLUE);
//	//printf("%d\n", Color::_GREEN);
//	//printf("%d\n", sizeof(c));
//	//printf("%d\n", sizeof(_BLUE));
//	//printf("%d\n", sizeof(enum Color));
//	//printf("%d\n", OFFSETOF(struct S, c1));
//	//printf("%d\n", OFFSETOF(struct S, i));
//	//printf("%d\n", OFFSETOF(struct S, c2));
//	//printf("%d\n", offsetof(struct S, c1));
//	//printf("%d\n", offsetof(struct S, i));
//	//printf("%d\n", offsetof(struct S, c2));
//	//printf("%d\n", sizeof(struct S));
//	//printf("%d\n", sizeof(struct S5));
//	//struct S s = { 0 };
//	//struct S2 s2 = { 0 };
//	//struct S3 s3 = { 0 };
//	//struct S4 s4 = { 0 };
//	//struct S5 s5 = { 0 };
//	//printf("%d\n", sizeof(s));
//	//printf("%d\n", sizeof(s2));
//	//printf("%d\n", sizeof(s3));
//	//printf("%d\n", sizeof(s4));
//	//printf("%d\n", sizeof(s5));
//	return 0;
//}
//union Un
//{
//	char c;
//	int i;
//};
//bool CheckEndian()
//{
//	int a = 0x01;
//	return *(char*)(&a);
//}
//bool CheckEndian1()
//{
//	union
//	{
//		int _in;
//		char _c;
//	} u;
//	u._in = 0x01;
//	return u._c;
//}
//void test()
//{
//	int* p = (int*)malloc(100);
//	if (NULL == p)
//	{
//		perror("malloc fail");
//		exit(errno);
//	}
//	free(p);
//	p = NULL;
//}
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}
//void GetMemory(char** pp)
//{
//	*pp = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = nullptr;
//}
//char* GetMemory()
//{
//	char* r = (char*)malloc(100);
//	return r;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = nullptr;
//}
//char GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;//err
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//void GetMemory(char** pp, int num)
//{
//	*pp = (char*)malloc(num);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//	free(str);
//	str = nullptr;
//}
//void Test()
//{
//	char* str = (char*)malloc(100);
//	assert(str);
//	strcpy(str, "hello");
//	free(str);
//	str = nullptr;
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}
//struct S1
//{
//	int n;
//	int arr[];
//};
//struct S2
//{
//	int n;
//	int arr[0];
//};
//struct S
//{
//	int n;
//	int* arr;
//};
//int main()
//{
//	//for (int i = 0; i < 5; i++)
//	//{
//	//	for (int j = 0; j < 5; j++)
//	//	{
//	//		if (i + j == 4)
//	//		{
//	//			printf("*");
//	//		}
//	//		else if (i == j)
//	//		{
//	//			printf("*");
//	//		}
//	//		else
//	//		{
//	//			printf(" ");
//	//		}
//	//	}
//	//	printf("\n");
//	//}
//	//struct S* ps = (struct S*)malloc(sizeof(struct S));
//	//if (NULL == ps)
//	//{
//	//	perror("malloc fail");
//	//	exit(errno);
//	//}
//	//ps->n = 10;
//	//ps->arr = (int*)malloc(10 * sizeof(int));
//	//if (NULL == ps->arr)
//	//{
//	//	perror("malloc fail");
//	//	free(ps);
//	//	ps = NULL;
//	//	exit(errno);
//	//}
//	//int i = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	ps->arr[i] = i;
//	//}
//	//int* ptr = (int*)realloc(ps->arr, 20 * sizeof(int));
//	//if (NULL == ptr)
//	//{
//	//	perror("realloc fail");
//	//	free(ps->arr);
//	//	ps->arr = nullptr;
//	//	free(ps);
//	//	ps = nullptr;
//	//	exit(errno);
//	//}
//	//ps->arr = ptr;
//	//free(ps->arr);
//	//ps->arr = NULL;
//	//free(ps);
//	//ps = NULL;
//	//struct S1* ps = (struct S1*)malloc(sizeof(struct S1) + sizeof(int) * 10);
//	//assert(ps);
//	//ps->n = 10;
//	//int i = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	ps->arr[i] = i;
//	//}
//	//struct S1* ptr = (struct S1*)realloc(ps, sizeof(struct S1) + 20 * sizeof(int));
//	//if (ptr != NULL)
//	//{
//	//	ps = ptr;
//	//}
//	//else
//	//{
//	//	perror("realloc fail");
//	//	free(ps);
//	//	ps = NULL;
//	//	exit(errno);
//	//}
//	//free(ps);
//	//ps = NULL;
//	//Test();
//	//int* p = (int*)malloc(10 * sizeof(int));
//	//if (NULL == p)
//	//{
//	//	perror("malloc fail");
//	//	exit(errno);
//	//}
//	//int i = 0;
//	//for (i = 0; i < 40; i++)
//	//{
//	//	*(p + i) = i;//err,越界
//	//}
//	//free(p);
//	//p = NULL;
//	//int* p = (int*)malloc(10000000000);
//	//int i = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	*(p + i) = i;
//	//}
//	//int arr[10] = { 0 };
//	//int* p = arr;
//	//free(p);//err
//	//p = NULL;
//	//int* p = (int*)malloc(10 * sizeof(int));
//	//if (NULL == p)
//	//{
//	//	perror("malloc fail");
//	//	exit(errno);
//	//}
//	//int i = 0;
//	//for (i = 0; i < 5; i++)
//	//{
//	//	*p++ = i;
//	//	cout << *p << ' ';
//	//}
//	//free(p);
//	//p = NULL;
//	//int* p = (int*)malloc(100);
//	//free(p);
//	//p = NULL;
//	//test();
//	//int* p = (int*)realloc(NULL, 10 * sizeof(int));
//	//if (NULL == p)
//	//{
//	//	perror("realloc fail");
//	//	exit(errno);
//	//}
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	printf("%d ", *(p + i) = i);
//	//}
//	//printf("\n");
//	//free(p);
//	//p = NULL;
//	//int* p = (int*)calloc(10, sizeof(int));
//	//if (NULL == p)
//	//{
//	//	perror("malloc fail");
//	//	exit(errno);
//	//}
//	//int i = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	*(p + i) = 5;
//	//}
//	//int* tmp = (int*)realloc(p, 20 * sizeof(int));
//	//if (NULL == tmp)
//	//{
//	//	perror("realloc fail");
//	//	free(p);
//	//	p = NULL;
//	//	exit(errno);
//	//}
//	//p = tmp;
//	//free(p);
//	//p = NULL;
//	//int* p = (int*)malloc(40);
//	//int* pi = (int*)calloc(10, sizeof(int));
//	//if (NULL == p)
//	//{
//	//	perror("malloc fail");
//	//	exit(errno);
//	//}
//	//if (NULL == pi)
//	//{
//	//	perror("calloc fail");
//	//	free(p);
//	//	p = NULL;
//	//	exit(errno);
//	//}
//	//int i = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	printf("%d ", *(p + i));
//	//	printf("%d ", *(pi + i));
//	//}
//	//free(p);
//	//free(pi);
//	//p = pi = NULL;
//	//int a = 10;
//	//int* p = &a;
//	//free(p);//err
//	//int arr[10];
//	//int* p = (int*)malloc(10 * sizeof(int));
//	//if (NULL == p)
//	//{
//	//	perror("malloc fail");
//	//	exit(-1);
//	//}
//	//int i = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	*(p + i) = i;
//	//}
//	//for (i = 0; i < 10; i++)
//	//{
//	//	std::cout << *(p + i) << std::endl;
//	//}
//	//free(p);
//	//p = NULL;
//	//union Un
//	//{
//	//	short s[5];
//	//	int a;
//	//} u;
//	//cout << sizeof(u) << endl;
//	//union Un
//	//{
//	//	char a[5];
//	//	int i;
//	//	char c;
//	//} u;
//	//cout << sizeof(u) << endl;
//	//if (CheckEndian())
//	//{
//	//	cout << "small endian" << endl;
//	//}
//	//else
//	//{
//	//	cout << "big endian" << endl;
//	//}
//	//union Un u = { 10 };
//	//u.i = 1000;
//	//u.c = 100;
//	//printf("%p\n", &u);
//	//printf("%p\n", &u.c);
//	//printf("%p\n", &u.i);
//	//printf("%d\n", sizeof(u));
//	return 0;
//}
//int main()
//{
//	//struct S
//	//{
//	//	char arr[10];
//	//	int num;
//	//	float sc;
//	//} s = { 0 };
//	//FILE* fp = fopen("test.dat", "r");
//	//if (NULL == fp)
//	//{
//	//	perror("fopen fail");
//	//	return errno;
//	//}
//	//fread(&s, sizeof(struct S), 1, fp);
//	//fprintf(stdout, "%s %d %.2f\n", s.arr, s.num, s.sc);
//	//fclose(fp);
//	//fp = NULL;
//	//struct S
//	//{
//	//	char arr[10];
//	//	int num;
//	//	float sc;
//	//} s = { "abcde", 10, 5.5f };
//	//FILE* fp = fopen("test.dat", "w");
//	//if (NULL == fp)
//	//{
//	//	perror("fopen fail");
//	//	return errno;
//	//}
//	//fwrite(&s, sizeof(struct S), 1, fp);
//	//fclose(fp);
//	//fp = NULL;
//	//struct S
//	//{
//	//	char arr[10];
//	//	int num;
//	//	float sc;
//	//} s = { "abcdef", 10, 5.5f };
//	//FILE* fp = fopen("test.dat", "w");
//	//if (NULL == fp)
//	//{
//	//	perror("fopen fail");
//	//	return errno;
//	//}
//	//fprintf(fp, "%s %d %.2f\n", s.arr, s.num, s.sc);
//	//fclose(fp);
//	//fp = NULL;
//	//struct S
//	//{
//	//	char arr[10];
//	//	int num;
//	//	float sc;
//	//} s = { 0 };
//	//FILE* pf = fopen("test.dat", "r");
//	//if (NULL == pf)
//	//{
//	//	perror("fopen fail");
//	//	return errno;
//	//}
//	//fscanf(pf, "%s %d %f", s.arr, &s.num, &s.sc);
//	//fprintf(stdout, "%s %d %.2f\n", s.arr, s.num, s.sc);
//	////cout << s.arr << endl;
//	////cout << s.num << endl;
//	////cout << s.sc << endl;
//	//fclose(pf);
//	//pf = NULL;
//	//char buff[20] = "";
//	//puts(fgets(buff, 20, stdin));
//	//char arr[10] = "xxxxxxxx";
//	//FILE* pf = fopen("test.dat", "r");
//	//if (NULL == pf)
//	//{
//	//	perror("fopen fail");
//	//	return errno;
//	//}
//	//char buff[1024] = "";
//	//fgets(buff, 1024, pf);
//	//puts(buff);
//	//fgets(buff, 1024, pf);
//	//puts(buff);
//	//fclose(pf);
//	//pf = NULL;
//	//FILE* pf = fopen("test.dat", "w");
//	//if (NULL == pf)
//	//{
//	//	perror("fopen fail");
//	//	return errno;
//	//}
//	//fputs("jlkakjljkljklfd\n", pf);
//	//fputs("jklkj;jlj;jjl\n", pf);
//	//fclose(pf);
//	//pf = NULL;
//	//int val = 0;
//	//while (~(val = fgetc(stdin)))
//	//{
//	//	putchar(val);
//	//}
//	//FILE* pf = fopen("test.dat", "r");
//	//if (NULL == pf)
//	//{
//	//	perror("fopen fail");
//	//	return errno;
//	//}
//	//char ch = 0;
//	//while (~(ch = fgetc(pf)))
//	//{
//	//	putchar(ch);
//	//}
//	//fclose(pf);
//	//pf = NULL;
//	//fputc('a', stdout);
//	//fputc('b', stdout);
//	//fputc('c', stdout);
//	//fputc('d', stderr);
//	//fputc('e', stderr);//stderr标准错误流,对应的设备是屏幕,打印e字符
//	//fputc('f', stderr);
////	FILE* pf = fopen("test.dat", "w");
////	if (NULL == pf)
////	{
////		perror("fopen fail");
////		return errno;
////	}
////	fputc('a', pf);
////	fputc('b', pf);
////	fputc('c', pf);
////	fclose(pf);
////	pf = NULL;
////	pf = fopen("test.dat", "w");
////	if (NULL == pf)
////	{
////		perror("fopen fail");
////		return errno;
////	}
////	fclose(pf);
////	pf = NULL;
//	//FILE* pf = fopen("C:/Users/Tim/Desktop/mycode/code1/code1/test.dat", "r");
//	//if (NULL == pf)
//	//{
//	//	perror("fopen fail");
//	//	return errno;
//	//}
//	//fclose(pf);
//	//pf = NULL;
//	//FILE* pf = fopen("C:/Users/Tim/Desktop/mycode/code1/code1/test.txt", "r");
//	//if (NULL == pf)
//	//{
//	//	perror("fopen fail");
//	//	return errno;
//	//}
//	//fclose(pf);
//	//pf = NULL;
//	//FILE* pf = fopen("test.txt", "r");
//	//if (NULL == pf)
//	//{
//	//	perror("fopen fail");
//	//	return errno;
//	//}
//	//fclose(pf);
//	//pf = NULL;
//	return 0;
//}
//extern int Add(int x, int y);
//int main()
//{
////	FILE* pf = fopen("test.txt", "w");
////	if (pf == NULL)
////	{
////		perror("fopen fail");
////		return errno;
////	}
////	fputs("abcdefg", pf);
////	Sleep(10000);
////	printf("刷新缓冲区");
////	fflush(pf);
////	Sleep(10000);
////	fclose(pf);
////	pf = NULL;
//	//int a = 10;
//	//int b = 20;
//	//int ret = Add(a, b);
//	//cout << ret << endl;
//	//FILE* pf = fopen("test.txt", "r");
//	//if (NULL == pf)
//	//{
//	//	perror("fopen fail");
//	//	return errno;
//	//}
//	//FILE* pfcpy = fopen("test2.txt", "w");
//	//if (NULL == pfcpy)
//	//{
//	//	fclose(pf);
//	//	pf = NULL;
//	//	perror("fopen fail");
//	//	return errno;
//	//}
//	//int ch = 0;
//	//while (~(ch = fgetc(pf)))
//	//{
//	//	fputc(ch, pfcpy);
//	//}
//	//if (feof(pf))
//	//{
//	//	printf("遇到文件结束标志,文件正常结束!\n");
//	//}
//	//else if (ferror(pf))
//	//{
//	//	printf("文件读取错误导致失败结束\n");
//	//}
//	//fclose(pf);
//	//fclose(pfcpy);
//	//pf = pfcpy = NULL;
//	//int a = 10000;
//	//FILE* pf = fopen("test.txt", "wb");
//	//if (NULL == pf)
//	//{
//	//	perror("fopen fail");
//	//	return errno;
//	//}
//	//fwrite(&a, sizeof(int), 1, pf);
//	//fclose(pf);
//	//pf = NULL;
//	//pf = fopen("test.txt", "rb");
//	//if (NULL == pf)
//	//{
//	//	perror("fopen fail");
//	//	return errno;
//	//}
//	//int r = 0;
//	//fread(&r, sizeof(int), 1, pf);
//	//cout << r << endl;
//	//fclose(pf);
//	//pf = NULL;
//	//FILE* fp = fopen("test.txt", "r");
//	//if (NULL == fp)
//	//{
//	//	perror("fopen fail");
//	//	return errno;
//	//}
//	//int ch = fgetc(fp);
//	//putchar(ch);
//	//fseek(fp, -2, SEEK_END);
//	//ch = fgetc(fp);
//	//putchar(ch);
//	//ch = fgetc(fp);
//	//putchar(ch);
//	//int ret = ftell(fp);
//	//printf("%d\n", ret);
//	//rewind(fp);
//	//ch = fgetc(fp);
//	//putchar(ch);
//	//fclose(fp);
//	//fp = NULL;
//	//struct S
//	//{
//	//	char arr[10];
//	//	int age;
//	//	float f;
//	//} s = { "hello", 20, 5.5f };
//	//struct S tmp = { 0 };
//	//char buf[100] = "";
//	//sprintf(buf, "%s %d %.1f", s.arr, s.age, s.f);
//	//printf("%s\n", buf);
//	//sscanf(buf, "%s %d %f", tmp.arr, &tmp.age, &tmp.f);
//	//cout << tmp.arr << endl;
//	//cout << tmp.age << endl;
//	//cout << tmp.f << endl;
//	return 0;
//}
//#define M 1000
//#define reg register
//#define do_forever for(;;)
//void print(int x)
//{
//	printf("the value of c is %d\n", x);
//}
//#define PRINT(X, FORMAT) printf("the value of "#X" is "FORMAT"\n", X);
//#define PRINT(X, FORMAT) printf("the value of "#X" is "FORMAT"\n", X);
//int main()
//{
//	//printf("hello world\n");
//	//printf("hello ""world\n");
//	//int a = 10;
//	//PRINT(a, "%d");
//	//printf("the value of ""a"" is %d\n", a);
//	//int b = 20;
//	//PRINT(b, "%d");
//	//printf("the value of ""b"" is %d\n", b);
//	//int c = 30;
//	//PRINT(c, "%x");
//	//printf("the value of ""c"" is %d\n", c);
//	//float f = 5.5f;
//	//PRINT(f, "%.2f");
//	//printf("the value of ""f"" is %.2f\n", f);
//	//printf("the value of ""f"" is ""%.2f""\n", f);
//	//int a = 10;
//	//print(a);
//	//int b = 20;
//	//print(b);
//	//int c = 30;
//	//print(c);
//	//printf("hello world\n");
//	//printf("hello" " world\n");
////#define M 100
////#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
////	int max = MAX(101, M);
////	cout << max << endl;
////	cout << M << endl;
////#define SQUARE(X) ((X) * (X))
////#define DOUBLE(X) ((X) + (X))
////	printf("%d\n", SQUARE(3 + 1));
////	printf("%d\n", 10 * DOUBLE(4));
////#define M 1000
////	int m = 1000;
////	int a = 10;
////	int b = 0;
////	if (a > 10)
////		b = M;
////	else
////		b = -M;
////	cout << b << endl;
////#define CASE break;case
////	int n = 0;
////	switch (n)
////	{
////	case 1:
////		CASE 2 :
////			CASE 3 :
////			break;
////	}
//	//reg int num = 0;
//	////do_forever;
//	//int m = M;
//	//printf("%d\n", m);
//	//printf("%d\n", __STDC__);
//	//FILE* pf = fopen("log.txt", "a+");
//	//if (NULL == pf)
//	//{
//	//	perror("fopen fail");
//	//	return errno;
//	//}
//	//int i = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	fprintf(pf, "%s %d %s %s %s\n", __FILE__, __LINE__, __DATE__, __TIME__, __FUNCTION__);
//	//}
//	//fclose(pf);
//	//pf = NULL;
//	//printf("%s\n", __FILE__);
//	//printf("%d\n", __LINE__);
//	//printf("%s\n", __DATE__);
//	//printf("%s\n", __TIME__);
//	//printf("%s\n", __FUNCTION__);
//	//cout << __FILE__ << endl;
//	//cout << __LINE__ << endl;
//	//cout << __DATE__ << endl;
//	//cout << __TIME__ << endl;
//	//cout << __FUNCTION__ << endl;
//	return 0;
//}
//#define CAT(X, Y, Z) X##Y##Z
//int main()
//{
//	int class101101 = 100;
//	printf("%d\n", CAT(class, 101, 101));//等价于class##101##101
//	//printf("%d\n", class##101##101);//but err
//	printf("%d\n", class101101);
//	return 0;
//}
//#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
//int Max(int x, int y)
//{
//	return x > y ? x : y;
//}
//#define MALLOC(num, type) (type*)malloc(num * sizeof(type))
//int main()
//{
////#if 1==2
////	printf("eh\n");
////#elif 2==3
////	printf("jjj\n");
////#else
////	printf("hhhhhh\n");
////#endif
////#define PRINT 0
////#if PRINT
////	printf("hhh");
////#endif
////#define PRINT 1
////#ifdef PRINT
////	printf("hehe\n");
////#endif
////#define M 10
////	int arr[M] = { 0 };
////	for (int i = 0; i < M; i++)
////	{
////		arr[i] = i;
////	}
////	for (int i = 0; i < M; i++)
////	{
////		printf("%d %d\n", i, arr[i]);
////	}
////#define M 100
////	int a = M;
////	printf("%d\n", M);
////#undef M
//	//printf("%d\n", M);
//	//int* pi = (int*)malloc(10 * sizeof(int));
//	//int* p = MALLOC(10, int);
//	//int a = 5;
//	//int b = 8;
//	////int m = Max(a++, b++);
//	//int m = MAX(a++, b++);
//	//printf("a = %d, b = %d\n", a, b);
//	//cout << m << endl;
//	//int m = MAX(a, b);
//	//cout << m << endl;
//	//m = Max(a, b);
//	//cout << m << endl;
//	return 0;
//}
//int main()
//{
//	//EOF;
//	//int a = 10;
//	//int b = 20;
//	//int ret = (a > b) ? a : b;
//	//cout << ret << endl;
//	//int n = 10;
//	//int arr[n];
////#define TEST 0
////#define HEHE 1
////#ifdef TEST
////	printf("hhhh\n");
////#endif
////#if defined(TEST)
////	printf("test2\n");
////#endif
////#ifndef HEHE
////	cout << "hhh" << endl;
////#endif
////#if !defined(HEHE)
////	cout << "ggg" << endl;
////#endif
////	EOF;
////#if 1==2
////	cout << "hhh" << endl;
////#elif 2==3
////	cout << "ggg" << endl;
////#else
////	cout << "mmm" << endl;
////#endif
//	return 0;
//}
//#pragma pack(4)
//struct A
//{
//	int a;
//	short b;
//	int c;
//	char d;
//};
//struct B
//{
//	int a;
//	short b;
//	char c;
//	int d;
//};
//#pragma pack()
//int main()
//{
//	//struct A sa = { 0 };
//	//struct B sb = { 0 };
//	//cout << sizeof(sa) << endl;
//	//cout << sizeof(sb) << endl;
////#pragma pack(4)
////	struct tagTest1
////	{
////		short a;
////		char d;
////		long b;
////		long c;
////	};//12
////	struct tagTest2
////	{
////		long b;
////		short c;
////		char d;
////		long a;
////	};//12
////	struct tagTest3
////	{
////		short c;
////		long b;
////		char d;
////		long a;
////	};//16
////	struct tagTest1 stT1;
////	struct tagTest2 stT2;
////	struct tagTest3 stT3;
////	printf("%d %d %d\n", sizeof(stT1), sizeof(stT2), sizeof(stT3));
////#pragma pack()
////#define A 2
////#define B 3
////#define MAX_SIZE A + B
////	struct _Record_Struct
////	{
////		unsigned char Env_Alarm_ID : 4;
////		unsigned char Paral : 2;
////		unsigned char state;
////		unsigned char avail : 1;
////	}*Env_Alarm_Record;
////	struct _Record_Struct* pointer = (struct _Record_Struct*)malloc(sizeof(struct _Record_Struct) * MAX_SIZE);
////	int sz = sizeof(struct _Record_Struct) * MAX_SIZE;
////	cout << sz << endl;
////	free(pointer);
////	pointer = NULL;
//	return 0;
//}
//int main()
//{
//	//unsigned char puc[4];
//	//struct tagPIM
//	//{
//	//	unsigned char ucPim1;
//	//	unsigned char ucData0 : 1;
//	//	unsigned char ucData1 : 2;
//	//	unsigned char ucData2 : 3;
//	//}*pstPimData;
//	////cout << sizeof(struct tagPIM);
//	//pstPimData = (struct tagPIM*)puc;
//	//memset(puc, 0, 4);
//	//pstPimData->ucPim1 = 2;
//	//pstPimData->ucData0 = 3;
//	//pstPimData->ucData1 = 4;
//	//pstPimData->ucData2 = 5;
//	//printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);//02 29 00 00
//	//union Un
//	//{
//	//	short s[7];
//	//	int n;
//	//} u;
//	//cout << sizeof(u) << endl;
//	//union
//	//{
//	//	short k;
//	//	char i[2];
//	//} *s, a;
//	//s = &a;
//	//s->i[0] = 0x39;
//	//s->i[1] = 0x38;
//	//printf("%x\n", a.k);
//	//enum ENUM_A
//	//{
//	//	X1,
//	//	Y1,
//	//	Z1 = 255,
//	//	A1,
//	//	B1
//	//};
//	//enum ENUM_A enumA = Y1;
//	//enum ENUM_A enumB = B1;
//	//cout << enumA << endl;
//	//cout << enumB << endl;
//	//typedef struct
//	//{
//	//	int a;
//	//	char b;
//	//	short c;
//	//	short d;
//	//} AA_t;
//	//cout << sizeof(AA_t) << endl;
//	//long num = 0;
//	//FILE* fp = NULL;
//	//if ((fp = fopen("fname.dat", "r")) == NULL)
//	//{
//	//	perror("fopen fail");
//	//	return errno;
//	//}
//	////while (~fgetc(fp))
//	//	//num++;
//	//fseek(fp, 0, SEEK_END);
//	//num = ftell(fp);
//	//cout << num << endl;
//	//fclose(fp);
//	//fp = NULL;
////#define CHAR_PTR char*
////	typedef char* char_ptr;
////	CHAR_PTR a, b;
////	char_ptr c, d;
////	cout << sizeof(a) << " " << sizeof(b) << endl;
////	cout << sizeof(c) << " " << sizeof(d) << endl;
////#define N 4
////#define Y(n) ((N + 2) * n)
////	int z = 2 * (4 + 6 * 5 + 1);
////	cout << z << endl;
////#define A 2+2
////#define B 3+3
////#define C A*B
////	cout << C << endl;
////#define OFFSETOF(s, m) (size_t)(&(((s*)0)->m))
////	struct S
////	{
////		int a;
////		short b;
////		int c;
////		char d;
////	};
////	cout << OFFSETOF(struct S, a) << endl;
////	cout << OFFSETOF(struct S, b) << endl;
////	cout << OFFSETOF(struct S, c) << endl;
////	cout << OFFSETOF(struct S, d) << endl;
////	cout << offsetof(struct S, a) << endl;
////	cout << offsetof(struct S, b) << endl;
////	cout << offsetof(struct S, c) << endl;
////	cout << offsetof(struct S, d) << endl;
////#define SWAP(X) (((0x55555555 & X) << 1) + ((0xaaaaaaaa & X) >> 1))
////	int b = 20;
////	cout << SWAP(b);
//	return 0;
//}
//#include "contact.h"
//void menu()
//{
//	printf("**********************\n");
//	printf("** 1.add    2.del   **\n");
//	printf("** 3.search 4.modiry**\n");
//	printf("** 5.sort   6.print **\n");
//	printf("**     0.exit       **\n");
//	printf("**********************\n");
//}
//enum Option
//{
//	_EXIT,
//	_ADD,
//	_DEL,
//	_SEARCH,
//	_MODIFY,
//	_SORT,
//	_PRINT
//};
//void test()
//{
//	int input = 0;
//	Contact con;
//	InitContact(&con);
//	do
//	{
//		menu();
//		printf("请输入您的选择:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case _EXIT:
//			SaveContact(&con);
//			DestroyContact(&con);
//			printf("退出通讯录");
//			break;
//		case _ADD:
//			AddContact(&con);
//			break;
//		case _DEL:
//			DelContact(&con);
//			break;
//		case _SEARCH:
//			SearchContact(&con);
//			break;
//		case _MODIFY:
//			ModifyContact(&con);
//			break;
//		case _SORT:
//			SortContact(&con);
//			break;
//		case _PRINT:
//			PrintContact(&con);
//			break;
//		default:
//			printf("选择错误,请重新选择\n");
//			break;
//		}
//	} while (input);
//}
//int main()
//{
//	test();
//	return 0;
//}
//int a = 100;//这里的变量a是全局变量,他是{}外部定义的变量
//int global = 2019;
//void test()
//{
//	int local = 2018;
//	int global = 2020;
//	printf("global = %d\n", global);//2020
//}
//int g_val = 2022;//全局变量
//g_val = 2020;//err:多次初始化,变量赋值必须放到{}内部
//printf("g_val = %d\n", g_val);//err:这是一个函数调用,但是没有函数调用代码得写到函数里面去
//int main()
//{
//	//printf("g_var = %d\n", g_var);//err:add.c中全局变量在code1.cpp中使用前没有进行声明外部符号导致出错
//	//extern int g_var;//extern只能修饰全局变量或者函数声明,且可以写多个也可以省略,并且声明全局变量时不能同时初始化
//	//printf("g_var = %d\n", g_var);//2020
//	//printf("g_variable = %d\n", g_variable);//err
//	//extern int g_variable;
//	//printf("g_variable = %d\n", g_variable);//2
//	//printf("1.g_val = %d\n", g_val);//2022
//	////printf("a = %d\n", a);//err
//	//{
//	//	printf("2.g_val = %d\n", g_val);//2022;
//	//	int a = 10;
//	//	printf("a = %d\n", a);//10
//	//}
//	////printf("a = %d\n", a);//err
//	//printf("3.g_val = %d\n", g_val);//2022
//	//变量分为局部变量和全局变量
//	//int a = 10;//这里的变量a是局部变量,他是{}内部定义的变量
//	//printf("%d\n", a);//10,当局部变量和全局变量名字冲突的情况下局部优先
//	//当然我们写代码的时候不建议吧局部变量和全局变量名字写成一样的
//	//test();
//	//IDE中的代码大都是依托于项目工程的,一个解决方案包含多个项目工程,一个项目工程包含多个.c,.h文件,但是一个项目工程有且只有一个main函数
//	//写代码	1.写出主函数main函数 1~xxxx行代码,如何执行呢?C语言是从主函数的第一行开始执行的,所以C语言代码中得有main函数(入口函数),C语言中的一个工程中main函数有且只有一个,写个代码在屏幕上打印:C语言	printf是一个库函数可以在屏幕上打印信息	printf使用前得打个招呼(引用名为头文件的stdio.h)
//	//printf("C language!\n");
//	//编译链接运行程序	VS这个IDE用快捷键ctrl+f5/ctrl+f5+fun/[调试窗口]->开始执行不调试	 即可搞定
//	//vs2013程序执行太快了,要设置一下vs2013的属性,vs2019不用设置就可以看到结果
//	//printf("hello world!\n");//ctrl+f5运行程序
//	//printf("hehe\n");
//	//printf("hello c!\n");
//	//数据类型	计算机语言--->写程序--->解决生活中的问题--->必须有能力描述生活中的问题
//	//购物商场--->上架商品,价格--->15.6元--->小数 1.56*10^1 
//	//年龄-50
//	//C语言 - 浮点型	- 整形
//	//a 'a' --->字符a
//	//char ch = 'a';//字符数据类型
//	//int age = 20;//整形
//	//short num = 20;//短整型
//	//long l = 10l;//长整型
//	//long long ll = 10ll;//长长整形
//	//float weight = 55.5f;//单精度浮点型
//	//double d = 0.0;//双精度浮点型
//	//printf("hehn\n");
//	//printf("C/C++\n");
//	//printf("%d\n", 100);
//	//sizeof是一个关键字/运算符,而不是函数,用来计算一个类型或者变量所占空间大小,单位是字节,返回值类型是size_t型
//	//printf("%d\n", sizeof(char));//1
//	//printf("%d\n", sizeof(short));//2
//	//printf("%d\n", sizeof(int));//4
//	//printf("%d\n", sizeof(long));//4/8 c标准规定sizeof(long)>=sizeof(int)
//	//printf("%d\n", sizeof(long long));//8
//	//printf("%d\n", sizeof(float));//4
//	//printf("%d\n", sizeof(double));//8
//	//printf("%d\n", sizeof(long double));//8/10/12
//	//计算机中的单位:bit--->比特位,计算机识别二进制,存储0和1,八进制组成是0~7,十进制组成是0~9,二进制组成是0和1
//	//1byte = 8bit
//	//1kbyte = 1024byte
//	//1mbyte = 1024kbyte
//	//1gbyte = 1024mbyte
//	//1tbyte = 1024gbyte
//	//1pbyte = 1024tbyte
//	//char ch = 'w';
//	//int weight = 120;
//	//int salary = 20000;
//	//生活中的一些数据:有些数据不能改变:血型,性别,圆周率
//	//有些数据可以改变:年龄,工资,体重
//	//C语言怎么描述?常量不可以改变的量,变量:能被改变的量
//	//创建一个变量:类型 变量名 = 0;//推荐
//	//类型 变量名;//语法允许,但是不推荐
//	//int age = 20;
//	//double weight = 75.3;
//	//age = age + 1;
//	//weight = weight - 10;
//	//printf("%d\n", age);
//	//printf("%.2lf\n", weight);//%.lf是打印double类型的格式控制字符,%f是打印float类型的格式控制字符
//	////%d-整形	%lf-double	%f-float
//	////写代码求两个整数的和,scanf函数是标准输入函数
//	//int a = 0;
//	//int b = 0;
//	//int sum = 0;
//	//scanf("%d%d", &a, &b);
//	//sum = a + b;
//	//printf("sum = %d\n", sum);
//	//变量的作用域和生命周期
//	//作用域	局部变量的作用域就是局部变量所在的局部范围
//	//全局变量的作用域就是整个项目工程
//	//printf("heh\n");
//	//int a = 10;
//	//printf("a = %d\n", a);
//	//生命周期:Duration 变量的生命周期:变量创建到销毁这一时间段
//	//局部变量生命周期:进入局部范围生命周期开始,出局部范围生命周期结束
//	//全局变量生命周期:就是整个main函数生命周期,也就是程序生命周期
//	//定义两个名字相同的全局变量是不可能出现的
//	//{
//	//	int a = 10;
//	//	printf("a = %d\n", a);//10
//	//}
//	//printf("a = %d\n", a);//err
//	//常量
//	//enum _Sex
//	//{
//	//	_MALE,//枚举常量
//	//	_FEMALE,//枚举常量
//	//	_SECRET//枚举常量
//	//};
//	//3.14;//字面常量
//	//1000;//字面常量
//	//const float pai = 3.14f;//C中是const修饰常变量
//	//pai = 3.1f;//err
////#define MAX 100//#define定义的标识符常量
////	printf("MAX = %d\n", MAX);
////#undef MAX
//	//printf("MAX = %d\n", MAX);//err
//	//enum _Sex sex = _MALE;
//	//printf("%d\n", sex);//0
//	return 0;
//}
//int g_variable = 2;
//#define MAX 10000
//size_t MyStrlen(const char* str)
//{
//	assert(str);
//	size_t r = 0;
//	while (*str++)	r++;
//	return r;
//}
//size_t _my_strlen(const char* str)
//{
//	assert(str);
//	if (!*str)	return 0;
//	else
//		return (1 + _my_strlen(1 + str));
//}
//size_t my_strlen(const char* str)
//{
//	assert(str);
//	const char* eos = str;
//	while (*eos++)
//	{
//		;
//	}
//	return (eos - str - 1);
//}
//void test()
//{
//	printf("%d\n", (int)strlen("abcdef"));//6
//	printf("%d\n", (int)strlen("c:\test\328\test.c"));//14
//}
//int main()
//{
//	//1.字面常量
//	//3.14;//浮点字面常量
//	//10;//整形字面常量
//	//'a';//字符字面常量
//	//"abcdef";//字符串字面常量
//	//..
//	//2.const修饰的常变量
//	//int num = 10;//变量
//	//num = 20;
//	//printf("num = %d\n", num);
//	//const int n = 10;//n就是const修饰的常变量---具有常量属性(不能被改变的属性),但是本质还是变量
//	////n = 20;//err
//	//int arr1[10] = { 0 };//ok
//	//int arr2[n];//C中err,说明这里n是变量,但是有的编译器(GCC)可以通过(C99变长数组),CPP中也能通过
//	//int arr3[n] = { 1, 2 };//C中err,并且C99变长数组(不能初始化)也编译不过,CPP可以编译通过
//	//3.#define定义的标识符常量
//	//int n = MAX;
//	//printf("n = %d\n", n);
//	//MAX = 1;//err:MAX是常量不能修改
//	//enum _Sex
//	//{
//	//	//这种枚举类型变量的未来可能取值
//	//	//枚举常量
//	//	_MALE = 3,//第一个常量默认是0这里赋初值为3,后面的每个常量根据前一个值递增1
//	//	_FEMALE,//4
//	//	_SECRET//5
//	//} s;//枚举常量保存在代码段中,枚举变量保存在栈/数据段/堆
//	//4.枚举常量可以一一列举的常量
//	//enum _Sex s = _MALE;
//	//printf("s = %d\n", _MALE);//3
//	//s = _FEMALE;
//	//printf("s = %d\n", _FEMALE);//4
//	//s = _SECRET;
//	//printf("s = %d\n", _SECRET);//5
//	//_MALE = 2;//err:不能对常量赋值
//	//cout << sizeof(enum _Sex) << endl;//4
//	//cout << sizeof(s) << endl;//4
//	//cout << sizeof(_MALE) << endl;//4
//	//cout << sizeof(_FEMALE) << endl;//4
//	//cout << sizeof(_SECRET) << endl;//4
//	//字符串
//	//printf("%d\n", (int)strlen("hello world.\n"));//13
//	//printf("%d\n", (int)MyStrlen("hello world.\n"));//13
//	//printf("%d\n", (int)_my_strlen("hello world.\n"));//13
//	//printf("%d\n", (int)my_strlen("hello world.\n"));//13
//	//char arr1[] = "bit";
//	//char arr2[] = { 'b', 'i', 't' };
//	//char arr3[] = { 'b', 'i', 't', '\0' };
//	//printf("%s\n", arr1);//bit
//	//printf("%s\n", arr2);//bit乱码
//	//printf("%s\n", arr3);//bit
//	//"abcdef";//字符串就是用双引号引起来的一串字符
//	//"hello world";
//	//字符数组---数组是一组相同类型的元素的集合
//	//其实字符串在结尾的位置隐藏了一个\0的转义字符,\0是字符串结束标志
//	//char arr[] = "hello\0";//['h' 'e' 'l' 'l' 'o' '\0' '\0']
//	//cout << sizeof(arr) << endl;//7
//	//char arr1[] = "abc";
//	//char arr2[] = { 'a', 'b', 'c' };
//	//char arr3[] = { 'a', 'b', 'c', '\0' };
//	//cout << sizeof(arr1) << endl;//4
//	//cout << sizeof(arr2) << endl;//3
//	//cout << sizeof(arr3) << endl;//4
//	//cout << arr1 << endl;//abc
//	//cout << arr2 << endl;//abc乱码
//	//cout << arr3 << endl;//abc
//	//求一下字符串长度---strlen();	string-length
//	//int len = (int)strlen("ab");//2
//	//printf("%d\n", len);//2
//	//printf("%d\n", sizeof("ab"));//3
//	//cout << strlen(arr1) << endl;//3
//	//cout << strlen(arr2) << endl;//3+
//	//cout << strlen(arr3) << endl;//3
//	//char arr[] = "abc\0d";
//	//cout << sizeof(arr) << endl;//6
//	//cout << int(strlen(arr)) << endl;//3
//	//cout << strlen("afc\0d") << endl;//3
//	//转义字符--->转义字符转变了他原来的意思		特殊到一般	一般到特殊
//	//printf("c:\\code\\test.c\n");
//	//printf("c:\code\test.c\n");
//	//printf("%c\n", '\'');
//	//printf("%s\n", "'");
//	//printf("'\n");
//	//printf("\'\n");
//	//printf("%s\n", "\"");
//	//printf("\"\n");
//	//test();
//	//printf("c:\test\test.c");
//	//printf("ab\ncd");
//	//printf("(are you ok??)\n");//vc6.0中会打印(are you ok],三字母词转义,"??)"--->"]"
//	//printf("(are you ok\?\?\)\n");
//	//printf("%c\n", 'a');
//	//printf("%c\n", ''');//err
//	//printf("%c\n", '\'');
//	//printf("%s\n", "abc");
//	//printf("%s\n", "a");
//	//printf("%s\n", "\"");
//	//printf("%c\n", '"');
//	//printf("%s\n", "'");
//	return 0;
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
/*
int Sub(int x, int y)
{
	return x - y;
}
*/
//int main()
//{
//	//注释:代码中有不需要的代码可以直接删除,也可以注释掉,代码中有些语句比较难懂可以加注释文字,即注释是用来解释复杂代码的,eg.
////注释有两种风格:1.C语言注释风格/*xxxxxxxxxxxxxxxxx*/	缺陷:不能嵌套注释	可以用条件编译代替之
////2.C++注释风格 //XXXXXXX		可以注释一行,也可以一行一行注释
//	//C++注释风格
//	//调用函数Add完成加法并打印到屏幕
//	//printf("%d\n", Add(1, 2));
//	//int a = 10;//C++注释风格
//	/*
//	int b = 0;//C语言注释风格,缺陷是不支持嵌套注释
//	*/
//	//printf函数在打印数据的时候可以指定打印的格式
//	//printf("%d\n", 100);//100
//	//printf("%c\n", 'a');//a
//	//printf("%s\n", "abc");//abc
//	//printf("c:\\test\\test.c");
//	//printf("\a\a\a\a");//\a蜂鸣
//	//printf("abc");
//	//printf("\b");//退格
//	//printf("%c\n", '\130');//X--->88 ASSCII码表对应的字符
//	//printf("%d\n", '\130');//88
//	//ASSCII码表:每个字符都有一个值,ASSCII码值,计算机存储落实在底层全是二进制数字,@!ER1... A-65 B-66 a-97 b-98
//	//printf("%c--->%d\n", '\101', '\101');//A--65--101
//	//printf("%c--->%d\n", '\x30', '\x30');//0---48
//	//cout << strlen("abc") << endl;//3
//	//cout << strlen("c:\test\328\test.c") << endl;//14
//	return 0;
//}
//int Add(int x, int y)
//{
//	int z = x + y;
//	return z;
//}
//int main()
//{
//	//int coding = 0;//选择语句
//	//printf("你会好好学习吗?(选择1 or 0):>");
//	//scanf("%d", &coding);
//	//if (coding == 1)
//	//{
//	//	printf("坚持,你会有好offer.\n");
//	//}
//	//else
//	//{
//	//	printf("卖红薯.\n");
//	//}
//	//int input = 0;
//	//printf("学习CS:>\n");
//	//printf("好好写代码?(1/0):>");
//	//scanf("%d", &input);
//	//if (1 == input)
//	//{
//	//	printf("好offer.\n");
//	//}
//	//else
//	//{
//	//	printf("卖红薯.\n");
//	//}
//	//循环语句	for while do...while
//	//int line = 0;
//	//printf("学习CS:>");
//	//while (line < 100000)
//	//{
//	//	printf("第%d行代码\n", line);
//	//	line++;
//	//}
//	//if (line == 100000)
//	//{
//	//	printf("前途无量.\n");
//	//}
//	//int line = 0;
//	//while (line < 100000)
//	//{
//	//	printf("写代码:%d行\n", line);
//	//	line++;
//	//}
//	//if (100000 == line)
//	//{
//	//	printf("好offer.\n");
//	//}
//	//函数-->特点就是简化代码,代码复用
//	//int num1 = 0;
//	//int num2 = 0;
//	//int sum = 0;
//	//printf("输入两个操作数:>");
//	//scanf("%d%d", &num1, & num2);
//	//sum = num1 + num2;
//	//cout << sum << endl;
//	//extern int Add(int, int);
//	//int num1 = 0;
//	//int num2 = 0;
//	//int sum = 0;
//	//printf("请输入两个操作数:>");
//	//scanf("%d%d", &num1, &num2);
//	//sum = Add(num1, num2);
//	//printf("sum = %d\n", sum);
//	//int num1 = 0;
//	//int num2 = 0;
//	//int sum = 0;
//	//printf("请输入两个操作数:>");
//	//scanf("%d%d", &num1, &num2);
//	////sum = num1 + num2;
//	//sum = Add(num1, num2);//函数的方式解决
//	//cout << sum << endl;
//	//数组--->一组相同数据类型元素的集合
//	//int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//定义一个整形数组,最多放10个元素
//	//int arr2[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//int i = 0;
//	//for (i = 0; i < 10; i++)
//	//{
//	//	printf("%d ", arr2[i]);
//	//}
//	//printf("\n");
//	//int a = 1;
//	//int b = 2;
//	//int c = 3;
//	//int d = 4;
//	//...
//	//数组是一组相同数据类型的元素的集合
//	//10个整形1~10存储起来,数组使用下标来访问,从下标0开始
//	//int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//int i = 0;
//	//while (i < 10)
//	//{
//	//	printf("%d ", arr[i++]);
//	//}
//	//printf("\n");
//	//char ch[5] = { 'a', 'b', 'c' };//不完全初始化,剩余部分默认初始化为0
//	//操作符		算术操作符+ - * /
//	//int a = 0;
//	//a = 9 / 2;
//	//printf("a = %d\n", a);//4
//	//float f = 0.0f;
//	//f = 9 / 2;
//	//printf("f = %.2f\n", f);//4.00
//	//cout << f << endl;//4
//	//double d = 0.0;
//	//d = 9 / 2.0;
//	//printf("d = %lf\n", d);//4.500000
//	//a = 9 % 2;//% -> 取余(取模)
//	//printf("a = %d\n", a);//1
//	//移位操作符: >> <<
//	//int a = 2;
//	//int b = a << 1;//左移操作符移动的是二进制位
//	//cout << b << endl;//4
//	//cout << a << endl;//2
//	//int c = b >> 2;//右移操作符移动的是二进制位
//	//cout << c << " " << b << endl;//1 4
//	//位操作符:&按位与 |按位或	^按位异或
//	//cout << (3 & 5) << endl;//1
//	//cout << (3 | 5) << endl;//7
//	//cout << (3 ^ 5) << endl;//6
////赋值操作符: =  += -= /= %= >>= <<= &= |= ^=
//	//int a = 2;
//	//a = a + 5;
//	//cout << a << endl;//7
//	//a = 6;
//	//cout << a << endl;//6
//	//a += 5;
//	//cout << a << endl;//11
//	//a = a - 3;
//	//cout << a << endl;//8
//	//a -= 3;
//	//cout << a << endl;//5
//	//a = a % 3;
//	//cout << a << endl;//2
//	//a %= 3;
//	//cout << a << endl;//2
//	return 0;
//}
//int main()
//{
//	//cout << sizeof(char*) << endl;
//	//cout << sizeof(short*) << endl;
//	//cout << sizeof(int*) << endl;
//	//cout << sizeof(long*) << endl;
//	//cout << sizeof(long long*) << endl;
//	//cout << sizeof(float*) << endl;
//	//cout << sizeof(double*) << endl;
//	//cout << sizeof(long double*) << endl;
//	//内存是电脑上特别重要的存储器,计算机中所有程序的运行都在内存中进行的,所以为了有效的使用内存,就把内存划分为一个一个的小的内存单元,每个内存单元大小都是一个字节，为了能够有效的访问到内存的每个单元,就给内存单元进行了编号,这些编号被称为内存单元的地址
//	//int a = 10;
//	//printf("0X%p\n", &a);//%p专门用来打印地址的格式输出字符
//	//int* pa = &a;//pa是用来存放地址的,C语言中pa叫指针变量
//	////*说明pa是指针变量,前面的int说明pa指向的对象是int类型的
//	//char ch = 'w';
//	//char* pc = &ch;
//	//printf("0X%p, 0X%p\n", pc, &ch);
//	//int* p = NULL;
//	//p = (int*)(&p);//ok,但不推荐这样写
//	//int* pp = (int*)&pp;//ok,但是不推荐这样写
//	//int b = 10;
//	//int* pb = &b;
//	//*pb = 20;//这里的*是解引用操作,*pb就是通过pb存的b的地址找到b
//	//printf("%d\n", b);//20 指针就是地址
//	//printf("%d\n", *pb);//20
//	//struct Stu
//	//{
//	//	char _name[20];//名字
//	//	int _age;//年龄
//	//	char _sex[5];//性别
//	//	char _id[15];//学号
//	//};
//	//struct Stu s = { "张三", 24, "男", "20202020" };
//	//printf("name = %s, age = %d, sex = %s, id = %s\n", s._name, s._age, s._sex, s._id);
//	//struct Stu* ps = &s;
//	//printf("name = %s, age = %d, sex = %s, id = %s\n", (*ps)._name, (*ps)._age, (*ps)._sex, (*ps)._id);
//	//printf("name = %s, age = %d, sex = %s, id = %s\n", ps->_name, ps->_age, ps->_sex, ps->_id);
//	//#define是预处理指令		1.define定义的符号	2.define定义的宏函数
//#define MAX 1000
//	cout << MAX << endl;//1000
//#undef MAX
//	//cout << MAX << endl;//err
//#define ADD(X, Y) ((X) + (Y))
//	cout << 4 * ADD(2, 3) << endl;//20
//#undef ADD
//	//cout << 4 * ADD(2, 3) << endl;//err
//	return 0;
//}
//int main()
//{
//	//int num = 10;//变量都有地址
//	////&num;取出num的地址
//	//printf("%p\n", &num);//打印地址, %p---以地址的形式打印
//	//int num = 10;
//	//int* p = NULL;//p是一个指针变量
//	//p = &num;
//	//*p = 20;
//	//printf("num = %d, *p = %d\n", num, *p);//20 20
//	//char ch = 't';
//	//char* pc = &ch;
//	//*pc = 'q';
//	//printf("%c\n", ch);//q
//	//printf("%c\n", *pc);//q
//	//cout << sizeof(char*) << endl;
//	//cout << sizeof(short*) << endl;
//	//cout << sizeof(int*) << endl;
//	//cout << sizeof(long*) << endl;
//	//cout << sizeof(long long*) << endl;
//	//cout << sizeof(float*) << endl;
//	//cout << sizeof(double*) << endl;
//	//cout << sizeof(long double*) << endl;
//	//结论:指针在32位平台所占空间大小是4字节,64位平台所占空间大小是8字节
//	//1 + 2;//+有两个操作数,+是双目操作符
//	//单目操作符:只有一个操作数的操作符
//	//!--->逻辑取反	C语言中0表示假,非0表示真
//	//int a = 10;
//	//printf("%d\n", !a);//0
//	//printf("%d\n", !!a);//1	逻辑归一操作
//	//printf("%d\n", !!!a);//0
//	//a = 0;
//	//printf("%d\n", !a);//1
//	//printf("%d\n", !!a);//0
//	////!应用场景
//	//if (a)
//	//{
//	//	//如果a为真,做事
//	//}
//	//if (!a)
//	//{
//	//	//如果a为假,做事
//	//}
//	return 0;
//}
//int main()
//{
//	//正值,负值操作符都是单目操作符,只有一个操作数
//	//int a = -5;
//	//cout << a << endl;
//	//a = -a;
//	//cout << a << endl;
//	//a = +a;
//	//cout << a << endl;
//	//sizeof操作符/关键字,是单目操作符,计算类型/变量所占内存空间大小,单位是字节
//	//int a = 10;
//	//cout << sizeof(int) << endl;//4	sizeof(int)编译通过里面的参数是类型说明sizeof不是函数,因为函数传参不可能传类型
//	//cout << sizeof(a) << endl;//4
//	//cout << sizeof a << endl;//ok,4,sizeof a编译通过说明这不是函数,因为函数调用不能省略()[函数调用操作符]
//	////cout << sizeof int << endl;//err
//	//int arr[10] = { 0 };//10 * 4 = 40
//	//printf("%d\n", sizeof(arr));//40,计算的是数组的总大小,单位是字节
//	//printf("%d\n", sizeof(arr[0]));//4
//	//int n = (int)(sizeof(arr) / sizeof(arr[0]));
//	//cout << "n = " << n << endl;//10
//	//cout << sizeof(int[10]) << endl;//40
//	//int a = 0;
//	//printf("%d\n", ~a);//~按二进制位取反:把所有二进制位中的数字0变1,1变0
//	////因为整数数据在内存中存储的是补码,一个整数的二进制表示有三种,原码,反码,补码,正整数原反补码相同,负整数要取反+1得到补码
//	//int a = 10;
//	//int b = ++a;//前置++,先++后使用
//	//cout << a << " " << b << endl;//11 11
//	//int a = 10;
//	//int b = a++;//后置++,先使用后++
//	//cout << a << " " << b << endl;//11 10
//	//int a = 1;
//	//int b = (++a) + (++a) + (++a);//不建议写这样的代码,这种代码写出来是浪费时间没有意义的
//	//cout << b << endl;//12 但是不唯一,不同的编译器运行结果不同,这是错误的代码,一定不能这样写
//	//typedef意思是类型定义--->不准确,应该是类型重命名
//	//typedef unsigned int u_int;
//	//u_int a = 100;
//	//unsigned int num = 100;//num和a这两个变量类型是一样的
//	//int a = 3.14;//warning:初始化从double到int可能丢失精度
//	//int aa = (int)3.14;//(类型)--->强制类型转换操作符
//	//printf("%d, %d\n", a, aa);//3 3
//	//关系运算符 > < >= <= != ==
//	//逻辑运算符&& || !
//	//int a = 3;
//	//int b = 5;
//	//int c = a && b;
//	//printf("c = %d\n", c);//1
//	//if (a && b)
//	//{
//	//	printf("hhh\n");
//	//}
//	//int a = 3;
//	//int b = 0;
//	//int c = a && b;
//	//cout << c << endl;//0
//	//int a = 1;
//	//int b = 0;
//	//int c = a || b;
//	//cout << c << endl;//1
//	//条件操作符---三目操作符	exp1 ? exp2 : exp3;
//	//int a = 0;
//	//int b = 3;
//	//int max = 0;
//	//if (a > b)	max = a;
//	//else max = b;
//	//cout << max << endl;
//	//max = (a > b) ? a : b;
//	//cout << max << endl;
//	//逗号操作符---双目操作符,逗号表达式--->逗号隔开的一串表达式,逗号表达式也称为顺序求值表达式,整个表达式的结果是最后一个表达式的结果
//	//int a = (2, 4 + 5, 6);
//	//cout << a << endl;//6
//	//int a = 0;
//	//int b = 3;
//	//int c = 5;
//	//int d = (a = b + 2, c = a - 4, b = c + 2);
//	//cout << d << endl;//3
//	//[]--->下标引用操作符
//	//int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	//cout << arr[5] << endl;//6
//	//函数调用操作符
//	//printf("heh\n");//调用函数的时候,函数名后面的()就是函数调用操作符
//	//printf("%d\n", 100);//100
//	//C语言提供的关键字 是C语言提供的而不能自己创造关键字,不能把C语言关键字用做变量名函数名
//	//int char;//err
//	//auto break case char const continue default do double else enum extern float for goto if int long register return short signed sizeof static struct switch typedef union unsigned void volatile while
//	//auto自动的 每个非静态且非寄存器的局部变量都是auto修饰的
//	//{
//	//	//auto int a = 10;//这里的变量a是自动创建,自动销毁的变量,也称为自动变量,临时变量,局部变量,栈变量
//	//	//这里的auto可以省略,auto在C++11中可以进行自动类型推导
//	//}
//	//extern是用来声明外部符号的,只能修饰全局变量全局函数
//	//register寄存器关键字,只能修饰局部变量,编译器建议将register修饰的变量放在寄存器中
//	//register int a = 10;
//	//printf("%p\n", &a);//err:寄存器变量不存储在内存中,&寄存器变量地址打印出错
//	//register int num = 100;//编译器建议将变量num存放在寄存器中
//	//我们建议将大量频繁被使用的变量用register修饰,放在寄存器中提高效率
//	//signed有符号的	unsigned int无符号的	static静态的	uion共用体	void空/无 volatile define不是关键字而是预处理指令	include也不是关键字而是预处理指令
//	return 0;
//}
//void test1()
//{
//	int a = 1;//a是局部变量
//	a++;
//	printf("%d ", a);
//}
//void test2()
//{
//	static int a = 1;//static修饰局部变量初始化语句只执行一次
//	a++;//static修饰局部变量改变了局部变量的生命周期(本质上改变了变量的存储类型)
//	printf("%d ", a);
//}
//extern int g_val;//extern声明外部符号
//extern int g_variable;
//extern int Add(int x, int y);//函数声明
//extern int Sub(int x, int y);
//int main()
//{
//	//static静态的	1.static修饰局部变量	2.static修饰全局变量	3.static修饰函数
//	//int i = 0;
//	//while (i < 10)
//	//{
//	//	//test1();//10个2
//	//	test2();//2 3 4 5 6 7 8 9 10 11
//	//	i++;
//	//}
//	//printf("g_val = %d\n", g_val);//全局变量在整个工程中都可以使用
//	//printf("g_variable = %d\n", g_variable);//err:因为add.c文件中g_variable全局变量被static修饰了,其全局作用域变为了所谓的文件作域(说法不准确)
//	//static修饰全局变量使得这个全局变量只能在自己所在的源文件中使用,其他源文件不能使用
//	//全局变量在其他源文件内部能够使用是因为全局变量具有外部链接属性,被static修饰以后就失去了外部链接属性,此时其他源文件就不能链接到这个静态的全局变量了
//	//int a = 10;
//	//int b = 20;
//	//int sum = Add(a, b);//30
//	//printf("sum = %d\n", sum);//30
//	//printf("%d\n", Sub(a, b));//err:因为Sub函数被static修饰了,只能在他所在的源文件中使用,不能在其他源文件中使用
//	//static修饰函数使得函数只能在自己所在的源文件内部使用,不能再其它源文件内部使用,本质上static修饰函数是失去了函数的外部链接属性(和static修饰全局变量类似)
//	return 0;
//}
#endif
