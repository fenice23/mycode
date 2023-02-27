#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cassert>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <cerrno>
#include <cstddef>
using namespace std;
void PrintArr(int* a, int n) {
	assert(a);
	for (int i = 0; i < n; i++)	printf("%d ", a[i]);
	printf("\n");
}
void Swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}
void InsertSort(int* a, int n) {
	assert(a);
	for (int i = 0; i < n - 1; i++) {
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0) {
			if (a[end] < tmp) {
				a[end + 1] = a[end];
				end--;
			}
			else {
				break;
			}
		}
		a[end + 1] = tmp;
	}
}
void ShellSort(int* a, int n) {
	assert(a);
	int gap = n;
	while (gap > 1) {
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++) {
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0) {
				if (tmp > a[end]) {
					a[end + gap] = a[end];
					end -= gap;
				}
				else {
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
void SelectSort1(int* a, int n) {//½µÐò
	assert(a);
	for (int i = 0; i < n - 1; i++) {
		int idx = i;
		for (int j = i + 1; j < n; j++) {
			if (a[idx] < a[j])	idx = j;
		}
		if (idx != i)	Swap(a[idx], a[i]);
	}
}
void SelectSort2(int* a, int n) {//ÉýÐò
	assert(a);
	int minIdx = 0, maxIdx = 0;
	for (int l = 0, r = n - 1; l < r; l++, r--) {
		minIdx = maxIdx = l;
		for (int i = l + 1; i <= r; i++) {
			if (a[minIdx] > a[i])	minIdx = i;
			if (a[maxIdx] < a[i])	maxIdx = i;
		}
		Swap(a[minIdx], a[l]);
		if (maxIdx == l)	maxIdx = minIdx;
		Swap(a[maxIdx], a[r]);
	}
}
void AdjustDown(int* a, int n, int root) {
	assert(a);
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n) {
		if (child + 1 < n && a[child + 1] < a[child])
			child++;
		if (a[child] < a[parent]) {
			Swap(a[child], a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else {
			break;
		}
	}
}
void HeapSort(int* a, int n) {
	assert(a);
	for (int i = ((n - 1) - 1) / 2; i >= 0; i--)
		AdjustDown(a, n, i);
	int end = n - 1;
	while (end > 0) {
		Swap(a[end], a[0]);
		AdjustDown(a, end, 0);
		end--;
	}
}
void BubbleSort(int* a, int n) {
	assert(a);
	bool flag = false;
	for (int i = 0; i < n - 1; i++) {
		flag = false;
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j] < a[j + 1]) {
				Swap(a[j], a[j + 1]);
				flag = true;
			}
		}
		if (!flag)
			break;
	}
}
void _MergeSort(int* a, int l, int r, int* tmp) {
	assert(a && tmp);
	if (l >= r)	return;
	int mid = (l & r) + ((l ^ r) >> 1);
	_MergeSort(a, l, mid, tmp);
	_MergeSort(a, mid + 1, r, tmp);
	int start1 = l, end1 = mid;
	int start2 = mid + 1, end2 = r;
	int start = start1, end = end2;
	int k = l;
	while (start1 <= end1 && start2 <= end2) {
		if (a[start1] > a[start2])  tmp[k++] = a[start1++];
		else  tmp[k++] = a[start2++];
	}
	while (start1 <= end1)	tmp[k++] = a[start1++];
	while (start2 <= end2)	tmp[k++] = a[start2++];
	while (start <= end) {
		a[start] = tmp[start];
		start++;
	}
}
void MergeSort(int* a, int n) {
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
void MergeSortNonR(int* a, int n) {
	assert(a);
	int* tmp = (int*)malloc(n * sizeof(int));
	if (!tmp) {
		perror("malloc fail");
		exit(errno);
	}
	for (int gap = 1; gap < n; gap *= 2) {
		for (int i = 0; i < n; i += 2 * gap) {
			int start1 = i, end1 = start1 + gap - 1;
			int start2 = end1 + 1, end2 = start2 + gap - 1;
			if (end1 >= n)	break;
			if (end2 >= n)	end2 = n - 1;
			int start = i, end = end2;
			int k = i;
			while (start1 <= end1 && start2 <= end2) {
				if (a[start1] > a[start2]) tmp[k++] = a[start1++];
				else tmp[k++] = a[start2++];
			}
			while (start1 <= end1) tmp[k++] = a[start1++];
			while (start2 <= end2) tmp[k++] = a[start2++];
			while (start <= end) {
				a[start] = tmp[start];
				start++;
			}
		}
	}
	free(tmp);
	tmp = NULL;
}
void CountSort(int* a, int n) {
	assert(a);
	int min = a[0], max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < min)	min = a[i];
		if (a[i] > max)	max = a[i];
	}
	int range = max - min + 1;
	int* tmpArr = (int*)malloc(range * sizeof(int));
	if (!tmpArr) {
		perror("malloc fail");
		exit(errno);
	}
#pragma warning(disable:6385)
#pragma warning(disable:6386)
	for (int i = 0; i < range; i++)	tmpArr[i] = 0;
	for (int i = 0; i < n; i++)	tmpArr[a[i] - min]++;
	int idx = 0;
	for (int i = range - 1; i >= 0; i--) {
		while (tmpArr[i]--)	a[idx++] = i + min;
	}
	free(tmpArr);
	tmpArr = NULL;
}
void MergeSortFile(const char* filename) {
	assert(filename);
#define N 1000
	FILE* fpread = fopen(filename, "r");
	if (!fpread) {
		perror("fopen fail");
		exit(errno);
	}
	int a[N] = { 0 };
	int i = 0;
	int n1 = 0;
	char name[1024] = "";
	int idx = 0;
	while (~fscanf(fpread, "%d\n", &n1)) {
		a[i++] = n1;
		if (i == N) {
			MergeSort(a, N);
			sprintf(name, "sort_%d.txt", idx++);
			FILE* fpwrite = fopen(name, "w");
			if (!fpwrite) {
				perror("fopen fail");
				fclose(fpread);
				fpread = NULL;
				exit(errno);
			}
			int c = N;
			while (c--) {
				fprintf(fpwrite, "%d\n", a[N - c - 1]);
			}
			i = 0;
			fclose(fpwrite);
			fpwrite = NULL;
		}
	}
	if (i) {
		MergeSort(a, i);
		sprintf(name, "sort_%d.txt", idx++);
		FILE* fpwrite = fopen(name, "w");
		if (!fpwrite) {
			perror("fopen fail");
			fclose(fpread);
			fpread = NULL;
			exit(errno);
		}
		int c = i;
		while (c--) {
			fprintf(fpwrite, "%d\n", a[i - c - 1]);
		}
		fclose(fpwrite);
		fpwrite = NULL;
	}
	fclose(fpread);
	fpread = NULL;
	name[0] = '\0';
	char file1[1024] = "sort_";
	char file2[1024] = "";
	char tmp[1024] = "";
	for (int k = 0; k < idx - 1; k++) {
		sprintf(file1, "%s%d", file1, k);
		sprintf(file2, "sort_%d.txt", k + 1);
		sprintf(name, "%s%d.txt", file1, k + 1);
		strcpy(tmp, file1);
		strcat(tmp, ".txt");
		FILE* pfread1 = fopen(tmp, "r");
		if (!pfread1) {
			perror("fopen fail");
			exit(errno);
		}
		FILE* pfread2 = fopen(file2, "r");
		if (!pfread2) {
			perror("fopen fail");
			fclose(pfread1);
			pfread1 = NULL;
			exit(errno);
		}
		FILE* pfwrite = fopen(name, "w");
		if (!pfwrite) {
			perror("fopen fail");
			fclose(pfread1);
			pfread1 = NULL;
			fclose(pfread2);
			pfread2 = NULL;
			exit(errno);
		}
		int a = 0, b = 0;
		int r1 = fscanf(pfread1, "%d\n", &a);
		int r2 = fscanf(pfread2, "%d\n", &b);
		while (r1 != EOF && r2 != EOF) {
			if (a > b) {
				fprintf(pfwrite, "%d\n", a);
				r1 = fscanf(pfread1, "%d\n", &a);
			}
			else {
				fprintf(pfwrite, "%d\n", b);
				r2 = fscanf(pfread2, "%d\n", &b);
			}
		}
		while (r1 != EOF) {
			fprintf(pfwrite, "%d\n", a);
			r1 = fscanf(pfread1, "%d\n", &a);
		}
		while (r2 != EOF) {
			fprintf(pfwrite, "%d\n", b);
			r2 = fscanf(pfread2, "%d\n", &b);
		}
		fclose(pfread1);
		fclose(pfread2);
		fclose(pfwrite);
		pfread1 = pfread2 = pfwrite = NULL;
	}

}
int GetMidIdx(int* a, int l, int r) {
	assert(a);
	int mid = (l & r) + ((l ^ r) >> 1);
	if (a[l] < a[mid]) {
		if (a[r] < a[l]) return l;
		else if (a[mid] < a[r]) return mid;
		else return r;
	}
	else {
		if (a[r] < a[mid]) return mid;
		else if (a[l] < a[r]) return l;
		else return r;
	}
}
int PartSort1(int* a, int l, int r) {
	assert(a);
	int midIdx = GetMidIdx(a, l, r);
	Swap(a[midIdx], a[r]);
	int keyIdx = r;
	while (l < r) {
		while (l < r && a[l] >= a[keyIdx]) l++;
		while (l < r && a[r] <= a[keyIdx]) r--;
		if (l < r) Swap(a[l], a[r]);
	}
	Swap(a[keyIdx], a[l]);
	return l;
}
int PartSort2(int* a, int l, int r) {
	assert(a);
	int midIdx = GetMidIdx(a, l, r);
	Swap(a[midIdx], a[r]);
	int key = a[r];
	while (l < r) {
		while (l < r && a[l] >= key) l++;
		a[r] = a[l];
		while (l < r && a[r] <= key) r--;
		a[l] = a[r];
	}
	a[l] = key;
	return l;
}
//int PartSort3(int* a, int l, int r) {
//	assert(a);
//	int midIdx = GetMidIdx(a, l, r);
//	Swap(a[midIdx], a[r]);
//	int keyIdx = r;
//	int prev = l - 1;
//	int cur = l;
//	while (cur < r) {
//		if (a[cur] < a[keyIdx] && ++prev != cur)
//			Swap(a[cur], a[prev]);
//		cur++;
//	}
//	Swap(a[++prev], a[keyIdx]);
//	return prev;
//}
int PartSort3(int* a, int l, int r) {
	assert(a);
	int midIdx = GetMidIdx(a, l, r);
	Swap(a[midIdx], a[r]);
	int keyIdx = l;
	int prev = r + 1;
	int cur = r;
	while (cur > l) {
		if (a[cur] < a[keyIdx] && --prev != cur)
			Swap(a[cur], a[prev]);
		cur--;
	}
	Swap(a[--prev], a[keyIdx]);
	return prev;
}
void QuickSort(int* a, int l, int r) {
	assert(a);
	if (l >= r)	return;
	if (r - l + 1 <= 10) {
		InsertSort(a + l, r - l + 1);
	}
	else {
		int div = PartSort2(a, l, r);
		QuickSort(a, l, div - 1);
		QuickSort(a, div + 1, r);
	}
}
void QuickSortNonR(int* a, int l, int r) {
	assert(a);
	if (r - l + 1 <= 10) {
		InsertSort(a + l, r - l + 1);
	}
	else {
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
}
//void QuickSortNonR(int* a, int l, int r) {
//	assert(a);
//	if (r - l + 1 <= 10) {
//		InsertSort(a + l, r - l + 1);
//	}
//	else {
//		queue<int> q;
//		q.push(l);
//		q.push(r);
//		while (!q.empty()) {
//			int start = q.front();
//			q.pop();
//			int end = q.front();
//			q.pop();
//			int div = PartSort2(a, start, end);
//			if (start < div - 1) {
//				q.push(start);
//				q.push(div - 1);
//			}
//			if (div + 1 < end) {
//				q.push(div + 1);
//				q.push(end);
//			}
//		}
//	}
//}
void TestSort() {//ÅÅÐò½µÐò
	//int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	int a[] = { 111, 21, 31, 41, 51, 16, 17, 81, 92, 210, 211, 122, 131, 1114, 151, 161, 137, 418, 619, 720 };
	//int a[] = { 1, 3, 5 ,7, 9, 10, 8, 6, 4, 2, 0 };
	//int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 15, 0 };
	int n = (int)(sizeof(a) / sizeof(a[0]));
	PrintArr(a, n);
	//QuickSort(a, 0, n - 1);
	QuickSortNonR(a, 0, n - 1);
	PrintArr(a, n);
	//InsertSort(a, n);
	//ShellSort(a, n);
	//PrintArr(a, n);
	//SelectSort1(a, n);
	//PrintArr(a, n);
	//SelectSort2(a, n);
	//HeapSort(a, n);
	//BubbleSort(a, n);
	//MergeSort(a, n);
	//MergeSortNonR(a, n);
	//MergeSortFile("sort.txt");
	//CountSort(a, n);
	//PrintArr(a, n);
}
int main() {
	TestSort();
	return 0;
}