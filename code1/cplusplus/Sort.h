#pragma once
#include "common.h"
void InsertSort(int* pa, int n);//直接插入排序,属于插入排序的一种 稳定
void ShellSort(int* pa, int n);//希尔排序,属于插入排序的一种,是对直接插入排序的优化	   不稳定
void HeapSort(int* pa, int n);//堆排序,属于选择排序的一种,时间复杂度O(nlogn)	O(1)的空间 不稳定
void SelectSort(int* pa, int n);//直接选择排序,属于选择排序的一种,时间复杂度O(N^2) O(1)的空间 不稳定
void BubbleSort(int* pa, int n);//冒泡排序,属于交换排序的一种,时间复杂度O(N^2)	   稳定
void QuickSort(int* pa, int left, int right);//快速排序,属于交换排序的一种,时间复杂度O(nlogn) 空间复杂度O(logn)	   不稳定
void QuickSortNonR(int* pa, int left, int right);
void MergeSort(int* pa, int n);//归并排序,常用于外排序,时间复杂度O(nlogn)	 空间复杂度O(n)	稳定
void MergeSortNonR(int* a, int n);//直接改循环非递归,时间复杂度0(nlogn)	空间复杂度O(n)
const char* MergeSortFileStart(const char* file_name);//排序文件中的数据
void CountSort(int* pa, int n);//计数排序,稳定