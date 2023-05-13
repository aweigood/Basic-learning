#pragma once


typedef int DataType;


//����һ������ָ��
typedef int(*PFUNC)(DataType left, DataType right);//����ָ��Ҫ���������д��ǰ�ߣ�����PFUNC�ͳ�Ϊһ��������


typedef struct Heap {
	DataType* array;//��������ĵ�ַ
	int CapaCity;
	int size;
}Heap;


//Ϊ��ʵ�ִ�Ѻ�С�ѵĲ�ͬʵ�֣����ǿ���ʹ��һ������������Ƚϵ���һ��

//����ֻ�ǽ����ݵ�ֵ������бȽ���
DataType Less(DataType left, DataType right) {
	return left > right;
}


DataType Greater(DataType left, DataType right) {
	return right > left;
}

//�����Ҫ�ĸı�Ļ�ֻ��Ҫ���������ָ��������뵽�ṹ������н��е����Ϳ�����

////////////////////////////�ѵ����ֵ���/////////////////////////////////



//�ѵ����µ���
void AdjustDown(Heap* hp, int parent);


//�ѵ����ϵ���
void AdjustUp(Heap* hp, int child);





/////////////////////////�ѵĸ���ʵ��////////////////////////////////////////


//�ѵĹ���


void HeapCreat(Heap* hp, DataType* a, int n);
//�ѵĹ�����Ҫ�Ƚ����鴫������Ȼ���ٵ����ɶѵĸ�ʽ�����������ָ�룬







//�ѵ�����


void HeapDestory(Heap* hp);
//�ѵ����پ��ǽ���������Ŀռ��ͷŵ�


//�ѵĲ���

void HeapPush(Heap* hp, DataType x);
//�ѵĲ�����ǽ�Ԫ�ز�����ٴε�������֤�ѵĽṹ����



//�ѵ�ɾ��

void HeapPop(Heap* hp);
//���Ѷ�Ԫ��ɾ��֮���ٽ��е������ٽ�������һ



//��ȡ�Ѷ�Ԫ��

DataType HeapTop(Heap* hp);
//�Ƚϼ򵥣����ǽ�����ĵ�һ��Ԫ��a[0]�������


//�������ݵĸ���

int HeapSize(Heap* hp);
//���ǽ����еĸ����������



//�ѵ��п�

int HeapEmpty(Heap* hp);
//ֱ�Ӿ����ж϶�Ԫ�ظ����Ƿ�Ϊ0


////////����////////
void TestHeap();