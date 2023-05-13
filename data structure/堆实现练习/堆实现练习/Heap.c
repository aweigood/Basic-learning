#include"Heap.h"
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<malloc.h>




void Swap(DataType* left, DataType* right) {
	int temp = *left;
	*left = *right;
	*right = *left;
}


//�������൱�����һ�����飬����ַԪ�ش�����֮�����ǲ�֪�����ж��ٸ��ڵ㣬���Խ�Ԫ�صĸ���Ҳ�������������Ķ������parent
void AdjustDown(DataType array[], int size, int parent) {
	int child = parent * 2 + 1;//child���parent�����ӣ�������ȫ�������������������Һ���



	while (child < size) {
		//�ڱ�֤���Һ��ӵ�ʱ������������֮�н�С�ĺ��ӣ�Ҫ����ʹ������Խ��
		//��Ϊ����ȫ�����������Կ���ʹ��child+1<size���б�ʾ
		if (child + 1 < size && array[child + 1] < array[child]) {
			child += 1;//������Ǳ�ǽ�С�ĺ���
		}

		//���parent�Ƿ�����ѵ�����,������ͽ��н���
		if (array[child] < array[parent]) {
			//����˫�׺ͺ��ӵĴ�С����֤��С�����ϱ�
			//Ҫ��������Ԫ�صĴ�С��Ҫ������ǵ�ַ
			Swap(&array[parent], &array[child]);
			//��˫�������ƶ�
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}


}



//���ϵ���
void AdjustUp(DataType array[], int size, int child) {
	int parent = (child - 1) / 2;

	while (child) {
		if (array[child] < array[parent]) {
			Swap(array[child], array[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
	}

}

/////////////////////////�ѵĸ���ʵ��////////////////////////////////////////


//�ѵĹ���

//�Ƚ��������ЩԪ�ؿ��������е�����֮��
void HeapCreat(Heap* hp, DataType* a, int n) {
	hp->array = (DataType*)malloc(sizeof(DataType) * n);
	if (hp->array == NULL) {
		assert(0);
		return;
	}
	hp->CapaCity = n;

	memcpy(hp->array, a, sizeof(DataType) * n);//ע���������������ʱ��������������ǿ��������ֽڵĴ�С

	hp->size = n;

	//�Զѽ��е���
	// ����ĵ�����ʽ������Ҫ��֤����Ҷ�ӽڵ������Ķ�����ѵ����ԣ�����Ҫ��Ҫ����Ϊ��
	//��Ϊ���ܱ�֤ÿ�ε�����ʱ������ȫ��������������Ҫ���±ߵĵ�����һ����Ҷ�ӽڵ㿪ʼ���ϵ���
	//���һ��Ҷ�ӽڵ���±���n-1��������˫�׾���(n-1-1��/2

	for (int root = (n - 2) / 2;root >= 0;root--) {
		//ÿ�μ�ȥ1�������Ͻ��е���ÿһ���������0���ǵ���n
		AdjustDown(hp->array, hp->size, root);
	}

}

//�ѵ�����


void HeapDestory(Heap* hp) {
	assert(hp);
	free(hp->array);
	hp->array = NULL;
	hp->CapaCity = 0;
	hp->size = 0;
}
//�ѵ����پ��ǽ���������Ŀռ��ͷŵ�


//���ѵĿռ��Ƿ��㹻
//��˳����е����ƣ�������ʹ�ö������٣�Ȼ��Ԫ�ؿ�����ȥ
void CheckHeap(Heap *hp) {
	assert(hp);

	if (hp->CapaCity == hp->size) {
		int newCapaCity = hp->CapaCity * 2;


		DataType* temp = (DataType*)malloc(sizeof(DataType) * newCapaCity);


		if (temp == NULL) {
			assert(0);
			printf("�ռ�����ʧ�ܣ�����");
			return;
		}

		memcpy(temp, hp->array, sizeof(DataType) * hp->size);

		free(hp->array);

		hp->array = temp;
		hp->CapaCity = newCapaCity;

	}
}



//�ѵĲ���

void HeapPush(Heap* hp, DataType x) {
	assert(hp);
	CheckHeap(hp);
	hp->array[hp->size] = x;
	hp->size++;

	AdjustUp(hp->array, hp->size, hp->array[hp->size]);

}
//�ѵĲ�����ǽ�Ԫ�ز�����ٴε�������֤�ѵĽṹ����
//���뵽���һ��Ԫ�أ�Ȼ�������ϵ�


//�ѵ�ɾ��

void HeapPop(Heap* hp) {
	if (HeapEmpty(hp)) {
		return;
	}
	//������Ԫ��
	//���н���
	Swap(&hp->array[0], &hp->array[hp->size - 1]);

	//���е�Ԫ�ظ�����һ
	hp->size--;


	//���Ѷ���Ԫ�����µ�
	AdjustDown(hp->array, hp->size, 0);

}
//���Ѷ�Ԫ��ɾ�����ٽ��е������ٽ�������һ
//ɾ���ķ����ǽ����һ��Ԫ�غͶѶ���Ԫ�ؽ��н�����Ȼ��size--�����һ��Ԫ�ؾͷ��ʲ����ˣ�֮���ٽ��е���



//��ȡ�Ѷ�Ԫ��

DataType HeapTop(Heap* hp) {
	assert(hp);
	return hp->array[0];
}
//�Ƚϼ򵥣����ǽ�����ĵ�һ��Ԫ��a[0]�������


//�������ݵĸ���

int HeapSize(Heap* hp) {
	assert(hp);
	return hp->size;
}
//���ǽ����еĸ����������



//�ѵ��п�

int HeapEmpty(Heap* hp) {
	assert(hp);
	return 0 == hp->size;//�����Ԫ�صĸ���Ϊ0�Ļ��ͻ᷵����
}
//ֱ�Ӿ����ж϶�Ԫ�ظ����Ƿ�Ϊ0

void TestHeap() {

	DataType array[] = { 27,10,32,15.16 };
	Heap hp;
	HeapCreat(&hp, array, sizeof(array) / sizeof(array[0]));


	printf("size = %d\n", HeapSize(&hp));
	printf("size = %d\n", HeapTop(&hp));


	HeapPop(&hp);

	printf("size = %d\n", HeapSize(&hp));
	printf("size = %d\n", HeapTop(&hp));

	//.......
	HeapDestory(&hp);

}


//�ѵ��������
/*
1.���� ������ǽ���ѣ������ڵ����Ķѽ������ѻ����ѣ����ڵ���С�Ķѽ�����С�ѻ�С���ѡ�
��Ϊ���ö������˼����ǽ�����֮��1���ö�ɾ����˼�룬���Ѷ����Ļ�����С��Ԫ�������һ��
Ҷ�ӽڵ㽻��λ�ã��磺������ѵĻ����ǽ�����Ԫ�طŵ������ߣ�ʵ��������Ĺ���
������֮�󽫶Ѷ�Ԫ�������һ��Ԫ�ؽ��н���λ�ã�Ȼ����size-1��
*/

Heap* LessSort(int array[], int size) {

	//ʵ�����ö�˼���С�������򣬾���Ҫ�Ѵ��Ԫ�طŵ���ߣ����Խ����
	int lastNodeLeaf = (size - 2) / 2;
	for (int root = lastNodeLeaf;root >= 0;root--) {
		AdjustDown(array, size, root);
	}

	//���ö�ɾ����˼���������
	int end = size - 1;
	while (end) {
		swap(&array[0], &array[end]);
		AdjustDown(array, end, 0);
		end--;
	}
}








/*
* Top-k����
* ��Ϊ����������̫�����޷����л�����Ҫʱ��̫������ʱ�����Ҫ��ǰk�����Ļ�����С��Ԫ��
* �Ȱ�ǰk��Ԫ�ؽ��мӽ��ѣ������Ҫ������ǰk������Ԫ�أ���iҪ��С�ѣ��ѽ�С��Ԫ�طŵ���λȻ��
* ��n-k�нϴ��Ԫ�ؽ����滻��Ȼ���ٽ��е�������֤ÿһ���滻��ȥ�Ķ�����С����һ��
* ǰk����С��Ҳ��һ���ģ�ֻ����Ҫ��һ����ѣ���֤ÿ�λ���ȥ�Ķ��ǽϴ����һ��Ԫ��
*/



int main() {
	TestHeap();
	return 0;
}