#pragma once
#include<stddef.h>

typedef int DataType;
typedef struct seqlist
{
	DataType* arry;//ָ�򴢴�Ԫ�صĿռ�
	int size;//��ЧԪ�صĸ���
	int capacity;//���������Դ����Ԫ�ظ���
}seqlist;

//Ҫ��˳�����г�ʼ��
void SeqlistInit(seqlist* ps);


//ʹ�����֮��Ҫ��˳����е����ݽ���һ���ͷţ���˳��������

void SeqlistDenstory(seqlist *ps);


//Ҫ��˳������һ���ռ��飬������ˣ�Ҫ����һ������
void CheckCapctiy(seqlist* ps);


//˳���β��
void SeqlistPushback(seqlist* ps,DataType x);


//˳���βɾ
void  SeqlistPopBack(seqlist* ps);


//˳������
int SeqslistFind(seqlist* ps,DataType x);


//��˳���pos������Ԫ��
void SeqlistInstet(seqlist* ps,int pos,DataType x );


//��ȡ����λ�õ�Ԫ��
DataType SeqlistAt(seqlist* ps,size_t pos);


//��ȡ��ʼλ�õ�Ԫ��
DataType SeqlistFront(seqlist* ps);



//��ȡ���һ��λ�õ�Ԫ��
DataType SeqlistBack(seqlist* ps);



//��ȡ��ЧԪ�صĸ���
size_t Seqlistcapacity(seqlist* ps);


//��ȡ�����Ĵ�С
size_t SeqlistSize(seqlist* ps);


//����Ƿ�Ϊ�գ�Ϊ���󷵻��棬���򷵻ؼ�
size_t SeqlistEmpty(seqlist* ps);

//����
void Textseqlist();


//˳����ӡ
void seqlistPrintf(seqlist* ps);

