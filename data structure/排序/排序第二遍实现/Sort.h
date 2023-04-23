#pragma once




//插入排序

void InsertSort(int array[], int size);


//改良版的插入排序
//折半插入排序

void InsertSort2(int array[], int size);
//思路就是利用二分查找找到他应该存在的地方，然后再与上边的一样，他之前的元素往后移动一个位置，再插入就行



//希尔排序

void ShellSort(int* a, int size);



//冒泡排序
void BubbleSort(int* a, int size);


//选择排序

void SelectSort(int* a, int size);



//堆排序

void HeapSort(int* a, int size);

//打印函数
void SortPrinf(int a[], int size);


//测试
void TextSort();