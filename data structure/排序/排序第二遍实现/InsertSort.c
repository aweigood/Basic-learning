#include"Sort.h"
#include<stdio.h>
//这里实现的都是从小到大的排序方式

//插入排序
void InsertSort(int array[], int size) {

	//从第二个元素开始排
	//这里表示的是还未排序的元素
	for (int i = 1;i < size;i++) {
		int temp = array[i];
		//开始和前i-1个有序的元素进行比较
		int end = i - 1;
		while (end >= 0 && array[end] > temp) {
			array[end + 1] = array[end];
			end--;
		}
		//找到位置，进行交换
		//比较了一圈也没找到比他小的，那就自己和自己交换，等于没变
		array[end+1] = temp;
	}


}

//时间复杂度是On^2,空间复杂度是O1，稳定性：稳定，中间没有间隔


//改良插入排序，折半插入排序
void InsertSort2(int array[], int size)
//思路就是利用二分查找找到他应该存在的地方，然后再与上边的一样，他之前的元素往后移动一个位置，再插入就行
{
	for (int i = 1;i < size;i++) {
		int temp = array[i];
		//每一次比较都是下标从0开始到i-1这些有序元素之间进行比较
		int begin = 0, end = i - 1;

		//二分查找找到他应该插入的位置
		while (begin<=end)
		{
			int mid = begin + (end - begin) / 2;
			if (temp > array[mid]) {
				begin = mid + 1;
			}
			else end = mid - 1;
		}


		//找到应该插入的位置了，循环退出了

		//开始移动begin/end之后的元素
		//注意这里不可以载用end了，因为上边end发生变化了
		for (int j = i-1;j >= begin;j--) {
			array[j + 1] = array[j];
		}
		//插入
		array[begin] = temp;
	}
}



//希尔排序
//就是分组方式的插入排序的方式，将之前的每次间隔一个变成每次间隔grep个，直到grep=1的时候，使得循环次数变少，时间复杂度降低
//这里采用每次除以2的方式进行分组
void ShellSort(int* a, int size) {
	//grep从size/2开始
	for (int grep = size / 2;grep >= 1;grep = grep / 2) {
		//就像插入排序一样，开始寻找位置，开始比较
		//假设i个元素之前都有序，之前的i从1开始，现在的i从grep开始。0号位置的元素对自己本身就是有序的
		for (int i = grep;i < size;i++) {
			int temp = a[i];
			//接下来就要和他之前的有序元素进行比较
			int end = i - grep;
			while (end >= 0 && a[end] > temp) {
				//进行交换
				a[end + grep] = a[end];
				end -= grep;
			}
			a[end + grep] = temp;
		}
	}
}

void SortPrinf(int a[], int size) {
	for (int i = 0;i < size;i++) {
		printf("%d\t", a[i]);
	}
	printf("\n");
}




