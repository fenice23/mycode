#pragma once
#include "common.h"
void InsertSort(int* pa, int n);//ֱ�Ӳ�������,���ڲ��������һ�� �ȶ�
void ShellSort(int* pa, int n);//ϣ������,���ڲ��������һ��,�Ƕ�ֱ�Ӳ���������Ż�	   ���ȶ�
void HeapSort(int* pa, int n);//������,����ѡ�������һ��,ʱ�临�Ӷ�O(nlogn)	O(1)�Ŀռ� ���ȶ�
void SelectSort(int* pa, int n);//ֱ��ѡ������,����ѡ�������һ��,ʱ�临�Ӷ�O(N^2) O(1)�Ŀռ� ���ȶ�
void BubbleSort(int* pa, int n);//ð������,���ڽ��������һ��,ʱ�临�Ӷ�O(N^2)	   �ȶ�
void QuickSort(int* pa, int left, int right);//��������,���ڽ��������һ��,ʱ�临�Ӷ�O(nlogn) �ռ临�Ӷ�O(logn)	   ���ȶ�
void QuickSortNonR(int* pa, int left, int right);
void MergeSort(int* pa, int n);//�鲢����,������������,ʱ�临�Ӷ�O(nlogn)	 �ռ临�Ӷ�O(n)	�ȶ�
void MergeSortNonR(int* a, int n);//ֱ�Ӹ�ѭ���ǵݹ�,ʱ�临�Ӷ�0(nlogn)	�ռ临�Ӷ�O(n)
const char* MergeSortFileStart(const char* file_name);//�����ļ��е�����
void CountSort(int* pa, int n);//��������,�ȶ�