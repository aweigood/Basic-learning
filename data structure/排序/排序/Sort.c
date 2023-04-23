#include"Sort.h"
#include <stdio.h>



//插入排序（单次比较）  时间复杂度是On 空间复杂度是O1
//本来就是有序的，就像扑克牌的整牌环节,假设现在要求一个从小到大的顺序
void InsertSortone(int array[], int size,int key)
{
	int end = size-1;
	while (end>=0&&key<array[end]) {
		//如果end比0大，那就让end处的元素向后搬移一个位置
		array[end+1] = array[end];
		end--;
	}
	//当end处于0时就是最小值，退出循环，或者是找打这个元素的位置
	array[end + 1] = key;
}



//时间复杂度是On^2             空间复杂度O1      应用场景：排序元素接近有序，待排序元素个数较少
void InsertSort(int array[], int size) {
	//注意这里的i=1,就是第一个元素他是一直有序的
	for (int i = 1;i < size ;i++) {
		int key = array[i];
		int end = i - 1;//为啥end是i-1，因为这里i是要插入的元素，i-1个元素之前是有序的，然后只要插入的元素比end的小就插入，比i-1都大就直接退出
		while (end >= 0 && key < array[end]) {
			//如果end比0大，那就让end处的元素向后搬移一个位置
			array[end + 1] = array[end];
			end--;
		}
		array[end + 1] = key;
	}
}

//希尔排序

void ShellSort(int array[], int size) {

	int gap = size;
	while (gap > 1) {	
		//当gap==1时候就为最后一次，因为这里加1了，所以要求gap》1就行
		gap = gap / 3 + 1;
		for (int i = gap;i < size-gap;i++) {
			int end = i ;
			int key = array[end+gap];
			
			while (end >= 0 && key < array[end]) {
				//如果end比0大，那就让end处的元素向后搬移一个位置
				array[end + gap] = array[end];
				end--;
			}
			array[end + gap] = key;
		}
	}
}


//排序的打印
void PrintfSort(int array[], int size) {
	for (int i=0;i < size;i++) {
		printf("%d", array[i]);
	}
	printf("\n");
}


//测试

void TextSort() {
	

	//int array[]={9,1,3,2,4,5,7,6,8};
	int array[] = { 1,2,4,5,6,7};

    PrintfSort(array, sizeof(array) / sizeof(array[0]));
	//单个插入排序测试
	//InsertSortone(array, sizeof(array) / sizeof(array[0])-1,3);//要不最后一个直接为0退出循环
	//多个元素插入排序测试
	InsertSort(array, sizeof(array) / sizeof(array[0]));
	PrintfSort(array, sizeof(array) / sizeof(array[0]));
	
}

int main() {
	TextSort();
	return 0;
}