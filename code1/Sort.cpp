#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"
//����������������
static void MySwap(int* p1, int* p2) {
	assert(p1 && p2);
	int t = *p1;
	*p1 = *p2;
	*p2 = t;
}
void InsertSort(int* pa, int n) {//ֱ�Ӳ�������,���ڲ��������һ�� �ȶ�
	//ʱ�临�Ӷ�O(N^2)	�ռ临�Ӷ�O(1)
	//ʲô��������?���������Ѿ�˳���������˳��ӽ��������	O(N)
	//ʲô������?���������Ѿ���������߽ӽ������	O(N^2)
	assert(pa);
	for (int i = 0; i < n - 1; i++) {
		int end = i;
		int tmp = pa[end + 1];
		while (end >= 0) {
			if (tmp < pa[end]) {
				pa[end + 1] = pa[end];
				end--;
			}
			else {
				break;
			}
		}
		pa[end + 1] = tmp;
	}
}
void ShellSort(int* pa, int n) {//ϣ���������ڲ��������һ��	,�Ƕ�ֱ�Ӳ���������Ż�	���ȶ�
	//ʱ�临�Ӷ�O(n^1.3)~O(n^2)
	//ϣ�����������:	1.Ԥ����(ʹ�������ݽӽ�����),�Ѽ��Ϊgap��ֵ��Ϊһ��,���в�������,ʹ�������ݽӽ�����,��ʱgap>1	ϣ������ʵ��ʱҪ���ж��鲢�Ŷ����Ƿ�������
	//2.ֱ�Ӳ�������,��ʱgap==1
		//����gapԽ��ǰ�������ݾͿ���Խ�쵽����,����С�����ݾͿ���Խ�쵽ǰ��,������Ե�gapԽ��Խ���ӽ�����;gapԽСǰ�������ݿ���Խ��������,��������ݿ���Խ����ǰ��,������Ե�gapԽСԽ�ӽ�����,���gap==1��ʵ�����൱��ֱ�Ӳ�������������
	//ϣ������ʵ�ֵ�ʱ��Ҫ���鲢��,�����Ƿ�������
	//ϣ�������ֳ���С��������
	//gap = gap / 3 + 1��������gap����ֵ,gap����ѡ������ֵ,�����gapֵ�Ǿ������Ժ������,��Ը��ֳ���������Ը��ŵ�
	assert(pa);
	int gap = n;
	while (gap > 1) {//gap>1����Ԥ����,������ӽ�����
		gap = gap / 3 + 1;//+1��֤�����һ��gapһ����1
		//gap==1���һ�ξ��൱��ֱ�Ӳ�������,��֤����
		for (int i = 0; i < n - gap; i++) {
			int end = i;
			int tmp = pa[end + gap];
			while (end >= 0) {
				if (tmp < pa[end]) {
					pa[end + gap] = pa[end];
					end -= gap;
				}
				else {
					break;
				}
			}
			pa[end + gap] = tmp;
		}
	}
	//��gap>1ʱ����Ԥ����,Ŀ�����ô������ݸ��ӽӽ�����,��gap==1ʱ�����Ѿ��ӽ�������,�ٰ���ֱ�Ӳ������������ͻ�ܿ�,����������Կ��Դﵽ�Ż���Ч��
	//ϣ������ʱ�临�ӶȲ��ü���,��Ҫ�����Ƶ�,�Ƶ�������ƽ��ʱ�临�Ӷ�O(n^1.3)~O(n^2)  ˵��һ�������ϣ������������ֱ�Ӳ��������,ֻ�������������鱾���Ѿ�������߽ӽ����������±�ֱ�Ӳ�������Ҫ��,��Ϊ�Ѿ�������߽ӽ�����ʱֱ�Ӳ��������ʱ�临�Ӷ�O(N),����ʱ��ϣ�������е�Ԥ�����൱�ڰ�����,Ч�ʵ���ֱ�Ӳ�������
}
static void AdjustDown(int* pa, int n, int root) {
	assert(pa);//���µ����㷨ʱ�临�Ӷ�O(logn)
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n) {
		if (child + 1 < n && pa[child + 1] > pa[child])	child++;
		if (pa[child] > pa[parent]) {
			MySwap(pa + child, pa + parent);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}
void HeapSort(int* pa, int n) {
	assert(pa);
	//�����򽨴��	����ʱ�临�Ӷ�O(n)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)	AdjustDown(pa, n, i);
	int end = n - 1;
	while (end > 0) {//��������ʱ�临�Ӷ�O((n - 1)logn)->O(nlogn)
		MySwap(pa, pa + end);
		AdjustDown(pa, end, 0);
		end--;
	}
	//��ʱ�临�Ӷ�O(nlogn)	���ȶ�
}
//void SelectSort(int* pa, int n) {
//	assert(pa);
//	int idx = 0;
//	for (int i = 0; i < n - 1; i++) {
//		int j = 0;
//		idx = i;
//		for (j = i + 1; j < n; j++) {
//			if (pa[idx] > pa[j]) {
//				idx = j;
//			}
//		}
//		if (idx != i) {
//			MySwap(pa + idx, pa + i);
//		}
//	}
//}
void SelectSort(int* pa, int n) {//ʱ�临�Ӷ�O(N^2) ���ȶ�
	assert(pa);
	int l = 0, r = n - 1;
	while (l < r) {//���±�
		int minIdx = l, maxIdx = l;
		for (int i = l + 1; i <= r; i++) {
			if (pa[i] > pa[maxIdx])	maxIdx = i;
			if (pa[i] < pa[minIdx])	minIdx = i;
		}
		MySwap(pa + maxIdx, pa + r);
		if (minIdx == r)	minIdx = maxIdx;
		MySwap(pa + minIdx, pa + l);
		l++, r--;
	}
}
void BubbleSort(int* pa, int n) {//ʱ�临�Ӷ�O(N^2)
	//������߽ӽ�����ʱ���O(N)	������߽ӽ������O(N^2)
	//�ռ临�Ӷ�O(1)
	assert(pa);//�ȶ�
	bool flag = false;
	for (int i = 0; i < n - 1; i++) {
		flag = false;
		for (int j = 0; j < n - 1 - i; j++) {
			if (pa[j] > pa[j + 1]) {
				flag = true;
				MySwap(pa + j, pa + j + 1);
			}
		}
		if (!flag)	break;
	}
}
//�����㷨���඼�Ǳ�����
//�ݹ���������
//��������ʱ�临�Ӷ���������O(n*logn)~O(n^2),�ռ临�Ӷ���������O(logn)~O(n)
//����������õ�����Ǹպ���ȫ����,ÿһ��������O(n)�����logn������ʱ�临�Ӷ�O(n*logn),����logn��ջ�ռ����Կռ临�Ӷ�O(logn)
//�������������Ǵ�������ǡ��������߽ӽ�����,����ÿ��ѡ�Ķ�����������С,������Ҫ��n��,ÿ��ʱ�临�Ӷ�O(n),����ʱ�临�Ӷ�O(n^2),����n��ջ�ռ����Կռ临�Ӷ�O(n)
//����������������ȡ�з�ʹ���������������,�ô������ݴ�֮ǰ��������߽ӽ�����ʱ��������ã������ۺ�������������ʱ�临�Ӷ�O(n*logn),�ռ临�Ӷ�O(logn)
//���������ȶ�
int GetMidIdx(int* pa, int l, int r) {
	assert(pa);
	int mid = (l & r) + ((l ^ r) >> 1);
	if (pa[l] < pa[mid]) {
		if (pa[mid] < pa[r])	return mid;
		else if (pa[l] > pa[r])	return l;
		else return r;
	}
	else {
		if (pa[mid] > pa[r])	return mid;
		else if (pa[l] < pa[r])	return l;
		else return r;
	}
}
int PartSort1(int* pa, int l, int r) {//����ָ�뷨,�����Ǳ�����
	assert(pa);
	int midIdx = GetMidIdx(pa, l, r);
	MySwap(pa + midIdx, pa + r);
	int keyIdx = r;
	while (l < r) {
		while (l < r && pa[l] <= pa[keyIdx])	l++;
		while (l < r && pa[r] >= pa[keyIdx])	r--;
		if (l < r)	MySwap(pa + l, pa + r);
	}
	MySwap(pa + l, pa + keyIdx);
	return l;
}
int PartSort2(int* pa, int l, int r) {//�ڿӷ�  ���Ҷ��Ǳ�����
	assert(pa);
	int midIdx = GetMidIdx(pa, l, r);
	MySwap(pa + midIdx, pa + r);
	//�ӵ���˼�����λ�õ�ֵ��������,���Ը��������µ�ֵ
	int key = pa[r];
	while (l < r) {
		while (l < r && pa[l] <= key)	l++;
		pa[r] = pa[l];//����ҵ���key������뵽�ұߵĿ�,rλ�þ����µĿ�
		while (l < r && pa[r] >= key)	r--;
		pa[l] = pa[r];//�ұ��ҵ���keyС�����뵽��ߵĿ�,rλ�þ����µĿ�
	}
	pa[l] = key;
	return l;
}//ǰ��ָ�뷨 ���Ҷ��Ǳ�����
//int PartSort3(int* pa, int l, int r) {//����
//	assert(pa);
//	int midIdx = GetMidIdx(pa, l, r);
//	MySwap(pa + midIdx, pa + r);
//	int keyIdx = r;
//	int prev = l - 1;
//	int cur = l;
//	while (cur < r) {
//		if (pa[cur] < pa[keyIdx] && ++prev != cur)
//			MySwap(pa + prev, pa + cur);
//		++cur;
//	}
//	MySwap(pa + (++prev), pa + keyIdx);
//	return prev;
//}
int PartSort3(int* pa, int l, int r) {//����
	assert(pa);
	int midIdx = GetMidIdx(pa, l, r);
	MySwap(pa + midIdx, pa + l);
	int keyIdx = l;
	int prev = r + 1;
	int cur = r;
	while (cur > l) {
		if (pa[cur] < pa[keyIdx] && --prev != cur)
			MySwap(pa + prev, pa + cur);
		cur--;
	}
	MySwap(pa + (--prev), pa + keyIdx);
	return prev;
}
void QuickSort(int* pa, int l, int r) {//���඼�Ǳ�����
	//�ݹ鷨:����ջ���,д������	ע��������ȡ�з��Ż��Ѿ�������߽ӽ���������
	//����ʹ��ֱ�Ӳ������������󼸲���ŵݹ����Ż�����
	assert(pa);
	if (l >= r)	return;
	if (r - l + 1 <= 10) {
		InsertSort(pa + l, r - l + 1);
	}
	else {
		int div = PartSort3(pa, l, r);
		QuickSort(pa, l, div - 1);
		QuickSort(pa, div + 1, r);
	}
}
void QuickSortNonR(int* a, int l, int r) {
	//�ݹ�ķǵݹ�---1.��ѭ��(쳲������������)�򵥵Ĳ��ܸ�ѭ��	2.վģ��洢���ݷǵݹ�
	//�ǵݹ�:1.���Ч��(�ݹ齨��ջ֡���������ĵ�,���Ƕ����ִ��������������Ż�΢����΢)
	//		2.�ݹ����ȱ����:���ջ֡�����̫��,���ܻᵼ��ջ���,��Ϊϵͳջ�ռ�һ�㲻����M����
	//		���ݽṹջģ��ǵݹ����ݴ洢�ڶ���,�ѿռ���G����Ŀռ�
	assert(a);
	stack<int> st;
	st.push(r);
	st.push(l);
	while (!st.empty()) {
		int start = st.top();
		st.pop();
		int end = st.top();
		st.pop();
		int div = PartSort3(a, start, end);
		if (div + 1 < end) {
			st.push(end);
			st.push(div + 1);
		}
		if (start < div - 1) {
			st.push(div - 1);
			st.push(start);
		}
	}
}
void MergeSort(int* pa, int n) {
	assert(pa);
}
void CountSort(int* pa, int n) {
	assert(pa);
}
//yxc���������㷨ģ��
void quick_sort(int* a, int l, int r) {
	assert(a);
	if (l >= r)	return;
	int i = l - 1, j = r + 1, x = a[l + r >> 1];
	while (i < j) {
		do i++;while (a[i] < x);
		do j--;while (a[j] > x);
		if (i < j)	swap(a[i], a[j]);
	}
	quick_sort(a, l, j), quick_sort(a, j + 1, r);
}