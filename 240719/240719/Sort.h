#pragma once

#include"Heap.h"
#include<string.h>
//������
void HeapSort(int* a, int n);

// ��������
void InsertSort(int* a, int n);

// ϣ������
void ShellSort(int* a, int n);

// ѡ������
void SelectSort(int* a, int n);

// ð������
void BubbleSort(int* a, int n);

// ��������ݹ�ʵ��
// ��������hoare�汾
int PartSort1(int* a, int left, int right);
// ���������ڿӷ�
int PartSort2(int* a, int left, int right);
// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right);
// ��������hoare�汾+����ȡ���Ż�+С�����Ż�
void QuickSort(int* a, int left, int right);

// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right);

// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n);
// �鲢����ǵݹ�ʵ��  �鷳��Ҫ���⿪O(n)�Ŀռ䣬��д�ˣ�
//void MergeSortNonR(int* a, int n);

// ��������
void CountSort(int* a, int n);