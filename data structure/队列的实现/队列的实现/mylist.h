#pragma once


/*���У�queue����ֻ������һ�˽��в��������������һ�˽���ɾ�����������Ա�
������һ���Ƚ��ȳ���First In First Out�������Ա����FIFO����������һ�˳�
Ϊ��β������ɾ����һ�˳�Ϊ��ͷ��
*/

//ͷɾ��β��


typedef int DataType;


//�ڵ�Ľṹ��
typedef struct QNode {
	struct QNode* next;
	DataType data;
}QNode;



//���еĽṹ��
typedef struct Queue {
	QNode* front;//ָ��ͷ�ڵ�
	QNode* back;//ָ��β�ڵ�

}Queue;





//�ڵ�Ĵ���
QNode* Buynode(DataType data);


//���еĳ�ʼ��
void QueueInit(Queue* q);





//���еĲ���
void QueuePush(Queue* q, DataType data);





//���е�ɾ��

void QueuePop(Queue* q);




//���еĴ�С
int QueueSize(Queue* q);

//�����Ƿ�Ϊ��


int QueueEmpty(Queue* q);

//���е�����



void QueueDestroy(Queue* q);




//����ͷ�ڵ�Ԫ�صĻ�ȡ


DataType QueueFront(Queue* q);

// ����β�ڵ�Ļ�ȡ
DataType QueueBack(Queue* q);

//���еĲ���




///////////////////////////////////
// ���Զ���
void TestQueue();