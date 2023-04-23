#include"Sort.h"
#include<stdio.h>
//����ʵ�ֵĶ��Ǵ�С���������ʽ

//��������
void InsertSort(int array[], int size) {

	//�ӵڶ���Ԫ�ؿ�ʼ��
	//�����ʾ���ǻ�δ�����Ԫ��
	for (int i = 1;i < size;i++) {
		int temp = array[i];
		//��ʼ��ǰi-1�������Ԫ�ؽ��бȽ�
		int end = i - 1;
		while (end >= 0 && array[end] > temp) {
			array[end + 1] = array[end];
			end--;
		}
		//�ҵ�λ�ã����н���
		//�Ƚ���һȦҲû�ҵ�����С�ģ��Ǿ��Լ����Լ�����������û��
		array[end+1] = temp;
	}


}

//ʱ�临�Ӷ���On^2,�ռ临�Ӷ���O1���ȶ��ԣ��ȶ����м�û�м��


//�������������۰��������
void InsertSort2(int array[], int size)
//˼·�������ö��ֲ����ҵ���Ӧ�ô��ڵĵط���Ȼ�������ϱߵ�һ������֮ǰ��Ԫ�������ƶ�һ��λ�ã��ٲ������
{
	for (int i = 1;i < size;i++) {
		int temp = array[i];
		//ÿһ�αȽ϶����±��0��ʼ��i-1��Щ����Ԫ��֮����бȽ�
		int begin = 0, end = i - 1;

		//���ֲ����ҵ���Ӧ�ò����λ��
		while (begin<=end)
		{
			int mid = begin + (end - begin) / 2;
			if (temp > array[mid]) {
				begin = mid + 1;
			}
			else end = mid - 1;
		}


		//�ҵ�Ӧ�ò����λ���ˣ�ѭ���˳���

		//��ʼ�ƶ�begin/end֮���Ԫ��
		//ע�����ﲻ��������end�ˣ���Ϊ�ϱ�end�����仯��
		for (int j = i-1;j >= begin;j--) {
			array[j + 1] = array[j];
		}
		//����
		array[begin] = temp;
	}
}



//ϣ������
//���Ƿ��鷽ʽ�Ĳ�������ķ�ʽ����֮ǰ��ÿ�μ��һ�����ÿ�μ��grep����ֱ��grep=1��ʱ��ʹ��ѭ���������٣�ʱ�临�ӶȽ���
//�������ÿ�γ���2�ķ�ʽ���з���
void ShellSort(int* a, int size) {
	//grep��size/2��ʼ
	for (int grep = size / 2;grep >= 1;grep = grep / 2) {
		//�����������һ������ʼѰ��λ�ã���ʼ�Ƚ�
		//����i��Ԫ��֮ǰ������֮ǰ��i��1��ʼ�����ڵ�i��grep��ʼ��0��λ�õ�Ԫ�ض��Լ�������������
		for (int i = grep;i < size;i++) {
			int temp = a[i];
			//��������Ҫ����֮ǰ������Ԫ�ؽ��бȽ�
			int end = i - grep;
			while (end >= 0 && a[end] > temp) {
				//���н���
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




