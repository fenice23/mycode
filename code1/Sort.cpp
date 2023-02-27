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
			if (tmp > pa[end]) {
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
				if (tmp > pa[end]) {
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
	//��������:����ÿ��ʱ�临�Ӷ�0(N),��ʱ�临�Ӷ�O(NlogN)~O(N^2),�ռ临�Ӷ�O(logN)~O(N),���ȶ�,������߽ӽ�����ʱ������ͨ������ȡ�б���������Ż�Ϊ������,����һ����Ϊ��������ʱ�临�Ӷ�O(NlogN),�ռ临�Ӷ�O(logN)

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
//void QuickSortNonR(int* a, int l, int r) {//���ſ�����ջģ��ǵݹ�Ҳ�����ö���ģ��ǵݹ�
//	//�ݹ�ķǵݹ�---1.��ѭ��(쳲������������)�򵥵Ĳ��ܸ�ѭ��	2.ջ/����ģ��洢���ݷǵݹ�
//	//�ǵݹ�:1.���Ч��(�ݹ齨��ջ֡���������ĵ�,���Ƕ����ִ��������������Ż�΢����΢)
//	//		2.�ݹ����ȱ����:���ջ֡�����̫��,���ܻᵼ��ջ���,��Ϊϵͳջ�ռ�һ�㲻����M����
//	//		���ݽṹջ/����ģ��ǵݹ����ݴ洢�ڶ���,�ѿռ���G����Ŀռ�
//	//���ǵݹ�汾�Ŀ�������ʱ�临�ӶȻ���O(n*logn)�����	�ռ临�Ӷȱ�O(logn)��,��Ϊ����stack/queue���ݽṹ�����˿ռ�����
//	assert(a);
//	stack<int> st;
//	st.push(r);
//	st.push(l);
//	while (!st.empty()) {
//		int start = st.top();
//		st.pop();
//		int end = st.top();
//		st.pop();
//		int div = PartSort3(a, start, end);
//		if (div + 1 < end) {
//			st.push(end);
//			st.push(div + 1);
//		}
//		if (start < div - 1) {
//			st.push(div - 1);
//			st.push(start);
//		}
//	}
//}
void QuickSortNonR(int* a, int l, int r) {//���ſ�����ջģ��ǵݹ�Ҳ�����ö���ģ��ǵݹ�
	//�ݹ�ķǵݹ�---1.��ѭ��(쳲������������)�򵥵Ĳ��ܸ�ѭ��	2.ջ/����ģ��洢���ݷǵݹ�
	//�ǵݹ�:1.���Ч��(�ݹ齨��ջ֡���������ĵ�,���Ƕ����ִ��������������Ż�΢����΢)
	//		2.�ݹ����ȱ����:���ջ֡�����̫��,���ܻᵼ��ջ���,��Ϊϵͳջ�ռ�һ�㲻����M����
	//		���ݽṹջ/����ģ��ǵݹ����ݴ洢�ڶ���,�ѿռ���G����Ŀռ�
	//���ǵݹ�汾�Ŀ�������ʱ�临�ӶȻ���O(n*logn)�����	�ռ临�Ӷȱ�O(logn)��,��Ϊ����stack/queue���ݽṹ�����˿ռ�����
	assert(a);
	if (l >= r)	return;
	queue<int>	q;
	q.push(l);
	q.push(r);
	while (!q.empty()) {
		int start = q.front();
		q.pop();
		int end = q.front();
		q.pop();
		int div = PartSort3(a, start, end);
		if (start < div - 1) {
			q.push(start);
			q.push(div - 1);
		}
		if (div + 1 < end) {
			q.push(div + 1);
			q.push(end);
		}
	}
}
void _MergeSort(int* a, int l, int r, int* tmp) {
	assert(a && tmp);
	if (l >= r)	return;
	int mid = (l & r) + ((l ^ r) >> 1);
	_MergeSort(a, l, mid, tmp);
	_MergeSort(a, mid + 1, r, tmp);
	int start = l;
	int end = r;
	int start1 = l, end1 = mid;
	int start2 = mid + 1, end2 = r;
	int k = l;
	while (start1 <= end1 && start2 <= end2) {
		if (a[start1] < a[start2])	tmp[k++] = a[start1++];
		else tmp[k++] = a[start2++];
	}
	while (start1 <= end1) tmp[k++] = a[start1++];
	while (start2 <= end2) tmp[k++] = a[start2++];
	while (start <= end) {//�鲢�õ����ݿ�������
		a[start] = tmp[start];
		start++;
	}
}
void MergeSort(int* a, int n) {//�鲢�����ȶ�	ʱ�临�Ӷ�O(NlogN)	�ռ临�Ӷ�O(N)	�������ⲿ����(���������Ӳ�����ļ��е�����)���ڲ�����
	assert(a);
	int* tmp = (int*)malloc(n * sizeof(int));
	if (!tmp) {
		perror("malloc fail");
		exit(errno);
	}
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
	tmp = NULL;
}
void MergeSortNonR(int* a, int n) {//�鲢����ǵݹ�Ҳ������ջģ�����ģ�⻹����ֱ�Ӹ�ѭ��
	//�鲢����ǵݹ��ȶ�	ʱ�临�Ӷ�O(NlogN)	�ռ临�Ӷ�O(N)	�������ⲿ����(���������Ӳ�����ļ��е�����)���ڲ�����
	assert(a);
	if (!n)	return;
	int* tmp = (int*)malloc(n * sizeof(int));
	if (!tmp) {
		perror("malloc fail");
		exit(errno);
	}
	//����ȫ�Ǳ�����
	int gap = 1;
	while (gap < n) {//���ѭ��O(logN)
		for (int i = 0; i < n; i += 2 * gap) {//�ڲ�ѭ��ÿ��ֻ�Ǳ���һ������Ȼ�������O(N)
			int start1 = i, end1 = start1 + gap - 1;
			int start2 = end1 + 1, end2 = start2 + gap - 1;
			if (start2 >= n) break;//ֻ�е�һ��ʱ,�ڶ��鲻���ڲ���Ҫ�ϲ�
			if (end2 >= n)	end2 = n - 1;//�ڶ���ֻ�в�������,�����ڶ�����ұ߽�
			int start = start1, end = end2;
			int k = i;
			while (start1 <= end1 && start2 <= end2) {
				if (a[start1] < a[start2]) tmp[k++] = a[start1++];
				else tmp[k++] = a[start2++];
			}
			while (start1 <= end1) tmp[k++] = a[start1++];
			while (start2 <= end2) tmp[k++] = a[start2++];
			while (start <= end)	{
				a[start] = tmp[start];
				start++;
			}
		}
		gap *= 2;
	}
	free(tmp);
	tmp = NULL;
}
const char* MergeSortFileStart(const char* file_name) {
	assert(file_name);
	FILE* fpread = fopen(file_name, "r+");
	if (!fpread) {
		perror("fopen fail");
		exit(errno);
	}
	//�ļ�������10000������,ÿ�����ֶ���ռһ��,�ֳ�100��С�ļ������ļ��ڲ�������(����),�ļ����ļ����й鲢
	int tmp[100] = { 0 };
	int num = 0;
	int i = 0;
	char res_name[1024] = "";
	int fileIdx = 0;
	while (~fscanf(fpread, "%d\n", &num)) {
		tmp[i++] = num;
		if (i == 100) {
			QuickSort(tmp, 0, i - 1);
			sprintf(res_name, "subStart/obj_%d.txt", fileIdx++);
			FILE* fpwrite = fopen(res_name, "w+");
			if (!fpwrite) {
				perror("fopen fail");
				fclose(fpread);
				fpread = NULL;
				exit(errno);
			}
			i = 0;
			int t = 100;
			while (t--) {
				fprintf(fpwrite, "%d\n", tmp[100 - t - 1]);
			}
			fclose(fpwrite);
			fpwrite = NULL;
		}
	}
	if (i) {
		QuickSort(tmp, 0, i - 1);
		sprintf(res_name, "subStart/obj_%d.txt", fileIdx++);
		FILE* fpwrite = fopen(res_name, "w+");
		if (!fpwrite) {
			perror("fopen fail");
			fclose(fpread);
			fpread = NULL;
			exit(errno);
		}
		for (int k = 0; k < i; k++) {
			fprintf(fpwrite, "%d\n", tmp[k]);
		}
		fclose(fpwrite);
		fpwrite = NULL;
	}
	fclose(fpread);
	fpread = NULL;
	char file1[1024] = "";
	char file2[200] = "";
	char tmp_name[1024] = "";
	strcpy(tmp_name, "/obj_0");
	for (int i = 0; i < fileIdx - 1; i++) {//�Ȱ��ļ���ƴ�ӳ���,Ȼ������ļ���Ĺ鲢����
		sprintf(file1, "subStart%s.txt", tmp_name);
		sprintf(tmp_name, "%s%d", tmp_name, i + 1);
		sprintf(file2, "subStart/obj_%d.txt", i + 1);
		sprintf(res_name, "subStart%s.txt", tmp_name);
		FILE* pfread1 = fopen(file1, "r+");
		FILE* pfread2 = fopen(file2, "r+");
		FILE* pfwrite = fopen(res_name, "w+");
		if (!pfread1) {
			perror("fopen fail");
			exit(errno);
		}
		if (!pfread2) {
			perror("fopen fail");
			fclose(pfread1);
			pfread1 = NULL;
			exit(errno);
		}
		if (!pfwrite) {
			perror("fopen fail");
			fclose(pfread1);
			fclose(pfread2);
			pfread1 = pfread2 = NULL;
			exit(errno);
		}
		int n1 = 0;
		int n2 = 0;
		int r1 = fscanf(pfread1, "%d\n", &n1);
		int r2 = fscanf(pfread2, "%d\n", &n2);
		while (r1 != EOF && r2 != EOF) {
			if (n1 > n2)	fprintf(pfwrite, "%d\n", n1), r1 = fscanf(pfread1, "%d\n", &n1);
			else fprintf(pfwrite, "%d\n", n2), r2 = fscanf(pfread2, "%d\n", &n2);
		}
		while (EOF != r1) {
			fprintf(pfwrite, "%d\n", n1);
			r1 = fscanf(pfread1, "%d\n", &n1);
		}
		while (EOF != r2) {
			fprintf(pfwrite, "%d\n", n2);
			r2 = fscanf(pfread2, "%d\n", &n2);
		}
		fclose(pfread1);
		fclose(pfread2);
		fclose(pfwrite);
		pfread1 = pfread2 = pfwrite = NULL;
	}
	return res_name;
}
void CountSort(int* a, int n) {//ʱ�临�Ӷ�O(MAX(N,tmpSize))
	assert(a);				   //�ռ临�Ӷ�O(tmpSize)	�ȶ�
	if (n <= 1)	return;//��������Ƚ�С��,����ֻ��������/�ַ���,�����ַ���,�������ݻ���Ҫʹ�������Ƚ���������,���������ŵ��ǵ�NԶ����tmpSize����N��tmpSize����޼���ʱ��(���������ݱȽϼ���ʱ)ʱ�临�Ӷȿ�����ΪO(N)(�ǳ�����ٶ�,�ȿ�������Ҫ��)--->��Ӧ�����Ŀռ仹�պ�(��ĳ�̶ֳ��Ͻ��������ռ任ȡʱ��),��������������ݲ�����,�ܷ�ɢ�Ļ�,��NԶС��tmpSizeʱʱ��Ч��һ���,�ռ����ĺܴ�ò���ʧ��,Ӧ��ʹ�������Ƚ������������
	int min = a[0], max = a[0];
	for (int i = 1; i < n; i++) {
		if (min > a[i])	min = a[i];
		if (max < a[i]) max = a[i];
	}
	int tmpSize = max - min + 1;
	int* tmpArr = (int*)malloc(tmpSize * sizeof(int));
	if (!tmpArr) {
		perror("malloc fail");
		exit(errno);
	}
	//for (int i = 0; i < tmpSize; i++)	tmpArr[i] = 0;
	memset(tmpArr, 0, tmpSize * sizeof(int));
	for (int i = 0; i < n; i++)	tmpArr[a[i] - min]++;
	int idx = 0;
	for (int i = 0; i < tmpSize; i++) {
		while (tmpArr[i]--) {
			a[idx++] = i + min;
		}
	}
	free(tmpArr);
	tmpArr = NULL;
}