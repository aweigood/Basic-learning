#include"Sort.h"
#include<stdio.h>

void Swap(int* left, int* right) {
	int temp = *left;
	*left = *right;
	*right = temp;
}


//ð������
void BubbleSort(int* a, int size) {
	//˼·����ÿ��ѭ���ҵ���������С���Ǹ����֣������ź�
	for (int i = 0;i < size - 1;i++) {
		for (int j = 0;j < size - i-1;j++) {
			if (a[j] > a[j + 1]) {
				Swap(&a[j + 1], &a[j]);
			}
		}
	}
}



//ѡ������

void SelectSort(int* a, int size) {
	for (int i = 0;i < size-1;i++) {
		int min = i;

		for (int j = i;j < size;j++) {
			if (a[j] < a[min]) {
				min = j;//�����С���Ǹ�
			}
		}
		Swap(&a[i], &a[min]);
	}
}

//������
//�ѵ����µ����㷨
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1;//�������ӽϴ�
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])//�Һ��Ӵ��ڣ����ұ����Ӵ�
		{
			child++;//���Һ��ӵĽϴ�ֵ
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else//�ѳɶ�
		{
			break;
		}
	}
}




void HeapSort(int* a, int size)
//֮ǰ��д���������Ƚ��ѣ��������������ͽ���ѡ�Ȼ����ö�ɾ����˼�룬���Ѷ�Ԫ�ػ������һ����size--��֮���ٽ��е���
{
	//ʹ�����µ����ķ�ʽ���н���
	//�ҵ�������һ����Ҷ�ӽڵ�
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

//��������
//hoare�汾�����������ǰ������ṹ����



/*
˼·������һ����׼������������ұ߽�������Ȼ���һ��begin��һ��end��һ��������߿�ʼ������һ�������ұ߿�ʼ������
ʹ����������ʱ�򣬻�׼ֵ��ߵĶ��Ȼ�׼ֵС���ұߵĶ��Ȼ�׼ֵ��
Ȼ�����λ�÷��ػ��������еݹ�
*/

//9,6,5,8,7,4,50,30,6
//��������Hoare�汾��
void QuickSort1(int* a, int begin, int end)
{
	if (begin >= end)//��ֻ��һ�����ݻ������в�����ʱ������Ҫ���в���
		return;

	int left = begin;//L
	int right = end;//R
	int keyi = left;//key���±�
	while (left < right)
	{
		//right���ߣ���С
		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}
		//left���ߣ��Ҵ�
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}
		if (left < right)//����left��right��ֵ
		{
			Swap(&a[left], &a[right]);
		}
	}
	int meeti = left;//L��R��������
	Swap(&a[keyi], &a[meeti]);//����key���������ֵ

	QuickSort1(a, begin, meeti - 1);//key�������н��д˲���
	QuickSort1(a, meeti + 1, end);//key�������н��д˲���
}
