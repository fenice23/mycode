#define _CRT_SECURE_NO_WARNINGS 1
#include "Sort.h"
//以下排序都是排升序
static void MySwap(int* p1, int* p2) {
	assert(p1 && p2);
	int t = *p1;
	*p1 = *p2;
	*p2 = t;
}
void InsertSort(int* pa, int n) {//直接插入排序,属于插入排序的一种 稳定
	//时间复杂度O(N^2)	空间复杂度O(1)
	//什么情况下最好?待排数据已经顺序有序或者顺序接近有序最好	O(N)
	//什么情况下最坏?待排数据已经逆序最坏或者接近逆序最坏	O(N^2)
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
void ShellSort(int* pa, int n) {//希尔排序属于插入排序的一种	,是对直接插入排序的优化	不稳定
	//时间复杂度O(n^1.3)~O(n^2)
	//希尔排序分两步:	1.预排序(使待排数据接近有序),把间距为gap的值分为一组,进行插入排序,使待排数据接近有序,此时gap>1	希尔排序实现时要进行多组并排而不是分组排序
	//2.直接插入排序,此时gap==1
		//其中gap越大前面大的数据就可以越快到后面,后面小的数据就可以越快到前面,但是相对的gap越大越不接近有序;gap越小前面大的数据可以越慢到后面,后面的数据可以越慢到前面,但是相对的gap越小越接近有序,如果gap==1其实就是相当于直接插入排序有序了
	//希尔排序实现的时候要多组并排,而不是分组排序
	//希尔排序又称缩小增量排序
	//gap = gap / 3 + 1基本上是gap的最值,gap可以选择其他值,但这个gap值是经过测试和演算的,针对各种场景都是相对更优的
	assert(pa);
	int gap = n;
	while (gap > 1) {//gap>1就是预排序,让数组接近有序
		gap = gap / 3 + 1;//+1保证了最后一次gap一定是1
		//gap==1最后一次就相当于直接插入排序,保证有序
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
	//当gap>1时都是预排序,目的是让待排数据更加接近有序,当gap==1时数组已经接近有序了,再按照直接插入排序这样就会很快,这样整体而言可以达到优化的效果
	//希尔排序时间复杂度不好计算,需要进行推导,推导出来的平均时间复杂度O(n^1.3)~O(n^2)  说明一般情况下希尔排序是优于直接插入排序的,只有在少数如数组本身已经有序或者接近有序的情况下比直接插入排序要坏,因为已经有序或者接近有序时直接插入排序的时间复杂度O(N),而此时的希尔排序中的预排序相当于白排了,效率低于直接插入排序
}
static void AdjustDown(int* pa, int n, int root) {
	assert(pa);//向下调整算法时间复杂度O(logn)
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
	//排升序建大堆	建堆时间复杂度O(n)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)	AdjustDown(pa, n, i);
	int end = n - 1;
	while (end > 0) {//交换调整时间复杂度O((n - 1)logn)->O(nlogn)
		MySwap(pa, pa + end);
		AdjustDown(pa, end, 0);
		end--;
	}
	//总时间复杂度O(nlogn)	不稳定
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
void SelectSort(int* pa, int n) {//时间复杂度O(N^2) 不稳定
	assert(pa);
	int l = 0, r = n - 1;
	while (l < r) {//找下标
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
void BubbleSort(int* pa, int n) {//时间复杂度O(N^2)
	//有序或者接近有序时最好O(N)	逆序或者接近逆序最坏O(N^2)
	//空间复杂度O(1)
	assert(pa);//稳定
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
//以下算法两侧都是闭区间
//递归版快速排序
//快速排序时间复杂度理论上是O(n*logn)~O(n^2),空间复杂度理论上是O(logn)~O(n)
//快速排序最好的情况是刚好完全二分,每一趟排序是O(n)大概有logn趟所以时间复杂度O(n*logn),消耗logn层栈空间所以空间复杂度O(logn)
//快速排序最坏情况是待排数据恰好有序或者接近有序,导致每次选的都是最大或者最小,理论上要排n趟,每趟时间复杂度O(n),所以时间复杂度O(n^2),消耗n层栈空间所以空间复杂度O(n)
//但是由于有了三数取中法使得最坏的情况不会出现,让待排数据从之前的有序或者接近有序时的最坏变成最好，导致综合来看快速排序时间复杂度O(n*logn),空间复杂度O(logn)
//快速排序不稳定
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
int PartSort1(int* pa, int l, int r) {//左右指针法,两侧是闭区间
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
int PartSort2(int* pa, int l, int r) {//挖坑法  左右都是闭区间
	assert(pa);
	int midIdx = GetMidIdx(pa, l, r);
	MySwap(pa + midIdx, pa + r);
	//坑的意思是这个位置的值被拿走了,可以覆盖填入新的值
	int key = pa[r];
	while (l < r) {
		while (l < r && pa[l] <= key)	l++;
		pa[r] = pa[l];//左边找到比key大的填入到右边的坑,r位置就是新的坑
		while (l < r && pa[r] >= key)	r--;
		pa[l] = pa[r];//右边找到比key小的填入到左边的坑,r位置就是新的坑
	}
	pa[l] = key;
	return l;
}//前后指针法 左右都是闭区间
//int PartSort3(int* pa, int l, int r) {//升序
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
int PartSort3(int* pa, int l, int r) {//降序
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
void QuickSort(int* pa, int l, int r) {//两侧都是闭区间
	//递归法:容易栈溢出,写起来简单	注意用三数取中法优化已经有序或者接近有序的情况
	//可以使用直接插入排序代替最后几层快排递归以优化代码
	//综上所述:快排每趟时间复杂度0(N),总时间复杂度O(NlogN)~O(N^2),空间复杂度O(logN)~O(N),不稳定,有序或者接近有序时的最坏情况通过三数取中避免掉反而优化为最好情况,所以一般认为快速排序时间复杂度O(NlogN),空间复杂度O(logN)

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
//void QuickSortNonR(int* a, int l, int r) {//快排可以用栈模拟非递归也可以用队列模拟非递归
//	//递归改非递归---1.改循环(斐波那契数列求解)简单的才能改循环	2.栈/队列模拟存储数据非递归
//	//非递归:1.提高效率(递归建立栈帧还是有消耗的,但是对于现代计算机而言这个优化微乎其微)
//	//		2.递归最大缺陷是:如果栈帧的深度太深,可能会导致栈溢出,因为系统栈空间一般不大在M级别
//	//		数据结构栈/队列模拟非递归数据存储在堆上,堆空间是G级别的空间
//	//而非递归版本的快速排序时间复杂度还是O(n*logn)级别的	空间复杂度比O(logn)大,因为用了stack/queue数据结构带来了空间消耗
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
void QuickSortNonR(int* a, int l, int r) {//快排可以用栈模拟非递归也可以用队列模拟非递归
	//递归改非递归---1.改循环(斐波那契数列求解)简单的才能改循环	2.栈/队列模拟存储数据非递归
	//非递归:1.提高效率(递归建立栈帧还是有消耗的,但是对于现代计算机而言这个优化微乎其微)
	//		2.递归最大缺陷是:如果栈帧的深度太深,可能会导致栈溢出,因为系统栈空间一般不大在M级别
	//		数据结构栈/队列模拟非递归数据存储在堆上,堆空间是G级别的空间
	//而非递归版本的快速排序时间复杂度还是O(n*logn)级别的	空间复杂度比O(logn)大,因为用了stack/queue数据结构带来了空间消耗
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
	while (start <= end) {//归并好的数据拷贝回来
		a[start] = tmp[start];
		start++;
	}
}
void MergeSort(int* a, int n) {//归并排序稳定	时间复杂度O(NlogN)	空间复杂度O(N)	适用于外部排序(可以排外存硬盘上文件中的数据)和内部排序
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
void MergeSortNonR(int* a, int n) {//归并排序非递归也可以用栈模拟队列模拟还可以直接改循环
	//归并排序非递归稳定	时间复杂度O(NlogN)	空间复杂度O(N)	适用于外部排序(可以排外存硬盘上文件中的数据)和内部排序
	assert(a);
	if (!n)	return;
	int* tmp = (int*)malloc(n * sizeof(int));
	if (!tmp) {
		perror("malloc fail");
		exit(errno);
	}
	//以下全是闭区间
	int gap = 1;
	while (gap < n) {//外层循环O(logN)
		for (int i = 0; i < n; i += 2 * gap) {//内层循环每次只是遍历一遍数组然后操作是O(N)
			int start1 = i, end1 = start1 + gap - 1;
			int start2 = end1 + 1, end2 = start2 + gap - 1;
			if (start2 >= n) break;//只有第一组时,第二组不存在不需要合并
			if (end2 >= n)	end2 = n - 1;//第二组只有部分数据,修正第二组的右边界
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
	//文件中设置10000个数字,每个数字顶格占一行,分成100个小文件进行文件内部内排序(快排),文件和文件进行归并
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
	for (int i = 0; i < fileIdx - 1; i++) {//先把文件名拼接出来,然后进行文件间的归并排序
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
void CountSort(int* a, int n) {//时间复杂度O(MAX(N,tmpSize))
	assert(a);				   //空间复杂度O(tmpSize)	稳定
	if (n <= 1)	return;//计数排序比较小众,而且只能排整型/字符型,遇到字符串,浮点数据还需要使用其他比较排序来排,但是它的优点是当N远大于tmpSize或者N与tmpSize相差无几的时候(即待排数据比较集中时)时间复杂度可以视为O(N)(非常快的速度,比快速排序还要快)--->对应的消耗空间还凑合(从某种程度上讲是牺牲空间换取时间),但是如果待排数据不集中,很分散的话,即N远小于tmpSize时时间效率一般般,空间消耗很大得不偿失了,应该使用其它比较排序进行排序
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