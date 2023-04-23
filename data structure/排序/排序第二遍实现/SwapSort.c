#include"Sort.h"
#include<stdio.h>

void Swap(int* left, int* right) {
	int temp = *left;
	*left = *right;
	*right = temp;
}


//冒泡排序
void BubbleSort(int* a, int size) {
	//思路就是每次循环找到最大或者最小的那个数字，将他排好
	for (int i = 0;i < size - 1;i++) {
		for (int j = 0;j < size - i-1;j++) {
			if (a[j] > a[j + 1]) {
				Swap(&a[j + 1], &a[j]);
			}
		}
	}
}



//选择排序

void SelectSort(int* a, int size) {
	for (int i = 0;i < size-1;i++) {
		int min = i;

		for (int j = i;j < size;j++) {
			if (a[j] < a[min]) {
				min = j;//标记最小的那个
			}
		}
		Swap(&a[i], &a[min]);
	}
}

//堆排序
//堆的向下调整算法
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1;//假设左孩子较大
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])//右孩子存在，并且比左孩子大
		{
			child++;//左右孩子的较大值
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else//已成堆
		{
			break;
		}
	}
}




void HeapSort(int* a, int size)
//之前都写过，就是先建堆，如果是想排升序就建大堆。然后采用堆删除的思想，将堆顶元素换到最后一个，size--，之后再进行调整
{
	//使用向下调整的方式进行建堆
	//找到倒数第一个非叶子节点
	for (int root = (size - 2) / 2;root >= 0;root--) {
		AdjustDown(a, size, root);
	}
	int end = size - 1;
	while (end)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}

}

//快速排序
//hoare版本，与二叉树的前序遍历结构类似



/*
思路：先找一个基准，这里采用最右边进行排序，然后给一个begin和一个end，一个从最左边开始便利，一个从最右边开始便利，
使得最后排序的时候，基准值左边的都比基准值小，右边的都比基准值大
然后将这个位置返回回来，进行递归
*/

//9,6,5,8,7,4,50,30,6
//快速排序（Hoare版本）
void QuickSort1(int* a, int begin, int end)
{
	if (begin >= end)//当只有一个数据或是序列不存在时，不需要进行操作
		return;

	int left = begin;//L
	int right = end;//R
	int keyi = left;//key的下标
	while (left < right)
	{
		//right先走，找小
		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}
		//left后走，找大
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}
		if (left < right)//交换left和right的值
		{
			Swap(&a[left], &a[right]);
		}
	}
	int meeti = left;//L和R的相遇点
	Swap(&a[keyi], &a[meeti]);//交换key和相遇点的值

	QuickSort1(a, begin, meeti - 1);//key的左序列进行此操作
	QuickSort1(a, meeti + 1, end);//key的右序列进行此操作
}
