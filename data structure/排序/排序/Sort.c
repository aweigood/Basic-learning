#include"Sort.h"
#include <stdio.h>



//�������򣨵��αȽϣ�  ʱ�临�Ӷ���On �ռ临�Ӷ���O1
//������������ģ������˿��Ƶ����ƻ���,��������Ҫ��һ����С�����˳��
void InsertSortone(int array[], int size,int key)
{
	int end = size-1;
	while (end>=0&&key<array[end]) {
		//���end��0���Ǿ���end����Ԫ��������һ��λ��
		array[end+1] = array[end];
		end--;
	}
	//��end����0ʱ������Сֵ���˳�ѭ�����������Ҵ����Ԫ�ص�λ��
	array[end + 1] = key;
}



//ʱ�临�Ӷ���On^2             �ռ临�Ӷ�O1      Ӧ�ó���������Ԫ�ؽӽ����򣬴�����Ԫ�ظ�������
void InsertSort(int array[], int size) {
	//ע�������i=1,���ǵ�һ��Ԫ������һֱ�����
	for (int i = 1;i < size ;i++) {
		int key = array[i];
		int end = i - 1;//Ϊɶend��i-1����Ϊ����i��Ҫ�����Ԫ�أ�i-1��Ԫ��֮ǰ������ģ�Ȼ��ֻҪ�����Ԫ�ر�end��С�Ͳ��룬��i-1�����ֱ���˳�
		while (end >= 0 && key < array[end]) {
			//���end��0���Ǿ���end����Ԫ��������һ��λ��
			array[end + 1] = array[end];
			end--;
		}
		array[end + 1] = key;
	}
}

//ϣ������

void ShellSort(int array[], int size) {

	int gap = size;
	while (gap > 1) {	
		//��gap==1ʱ���Ϊ���һ�Σ���Ϊ�����1�ˣ�����Ҫ��gap��1����
		gap = gap / 3 + 1;
		for (int i = gap;i < size-gap;i++) {
			int end = i ;
			int key = array[end+gap];
			
			while (end >= 0 && key < array[end]) {
				//���end��0���Ǿ���end����Ԫ��������һ��λ��
				array[end + gap] = array[end];
				end--;
			}
			array[end + gap] = key;
		}
	}
}


//����Ĵ�ӡ
void PrintfSort(int array[], int size) {
	for (int i=0;i < size;i++) {
		printf("%d", array[i]);
	}
	printf("\n");
}


//����

void TextSort() {
	

	//int array[]={9,1,3,2,4,5,7,6,8};
	int array[] = { 1,2,4,5,6,7};

    PrintfSort(array, sizeof(array) / sizeof(array[0]));
	//���������������
	//InsertSortone(array, sizeof(array) / sizeof(array[0])-1,3);//Ҫ�����һ��ֱ��Ϊ0�˳�ѭ��
	//���Ԫ�ز����������
	InsertSort(array, sizeof(array) / sizeof(array[0]));
	PrintfSort(array, sizeof(array) / sizeof(array[0]));
	
}

int main() {
	TextSort();
	return 0;
}