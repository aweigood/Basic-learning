#pragma once 

//ջ��ʵ���ǰ���˳�����ʵ�ֵ�
//����˳���ͬ�ĵط������䲻����˳���Ĳ���������

typedef int Datapyte;


typedef struct stack {
	Datapyte* array;   //ָ�򴢴�Ԫ�صĿռ�
	int capacity;  // �����С,�����������Ա���Ĵ�С
	int size;     //������ЧԪ�ظ�����ͬʱҲ�Ǳ�ʾջ��Ԫ��
}stack;







//////////////ջ�е���ز���//////////////////
//ջֻ�ܴ�ջ��������ջ����ȥ





//ջ�ĳ�ʼ��
void StackInit(stack* ps);



//���ռ��Ƿ��㹻����������ھͽ��ռ��Ϊ֮ǰ������
void StackCapaCity(stack* ps);


//��ջ����
void StackPush(stack* ps, Datapyte data);



//��ջ����
void StackPop(stack* ps);


//��ȡջ��Ԫ��
Datapyte Stacktop(stack* ps);



//��ȡջ����ЧԪ��
int StackSize(stack* ps);



//���ջ�Ƿ�Ϊ��
int StackEmpty(stack* ps);



//ջ������
void StcakDestory(stack* ps);



//ջ�Ĳ���
void TestStack();