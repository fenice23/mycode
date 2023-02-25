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
	//递归改非递归---1.改循环(斐波那契数列求解)简单的才能改循环	2.站模拟存储数据非递归
	//非递归:1.提高效率(递归建立栈帧还是有消耗的,但是对于现代计算机而言这个优化微乎其微)
	//		2.递归最大缺陷是:如果栈帧的深度太深,可能会导致栈溢出,因为系统栈空间一般不大在M级别
	//		数据结构栈模拟非递归数据存储在堆上,堆空间是G级别的空间
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
//yxc快速排序算法模板
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