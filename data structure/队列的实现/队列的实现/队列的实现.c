#include<stdio.h>

#include "mylist.h"
#include<assert.h>

#include<stdlib.h>
//ʹ�ö��в��ò���ͷ�ĵ�������һ�Σ�




//���еĳ�ʼ��
void QueueInit(Queue* q) {
	assert(q);

	q->back = NULL;
	q->front = NULL;
}



//�ڵ�Ĵ���
//������һ���ռ䣬Ȼ�����ݺ���һ��Ԫ�صĵ�ַ��ʼ��
QNode* Buynode(DataType data) {
	QNode* newnode = (QNode*)malloc(sizeof(DataType));
	if (newnode == NULL) {
		assert(0);
		printf("�����ռ�ʧ��\n");
	}
	newnode->data = data;
	newnode->next = NULL;

	return newnode;
}


//���е�ɾ��
/*
����Ҫ����һ���жϣ�������ֻ��һ���ڵ��
û�нڵ��
�ж���ڵ��������
*/
void QueuePop(Queue* q) {
	assert(q);
	if (QueueEmpty(q)) {
		return;
	}
	//ֻ��һ���ڵ��ʱ��
	else if (q->back == q->front) {
		free(q->front);
		//��ʱ��ͷ��β��һ���ڵ㣬�ͷž�û�нڵ���
		//֮��Ҫ�����е�ͷ��β�ڵ㶼��Ϊ��
		q->back = NULL;
		q->front = NULL;
	}

	//�ж���ڵ�
	else {
		QNode* temp = q->front;
		q->front =temp->next;
		free(temp);
	}
}

//Ҳ���Խ���һ���ڵ�Ͷ���ڵ����һ��,���Ǽ���һ���жϣ�
//���ɾ��֮��ͷ�ڵ��Ѿ�ΪNULL֮��˵��ֻ��һ���ڵ㣬Ҫ��backҲ��Ϊ��
/*
	if (QueueEmpty) {
		return;
	}
	else{
	    Queue* temp = q->front;
		q->front = q->front->next;
		free(temp);
		if(q->front==NULL��{
		q->back=BULL;
		}
	    
	}
*/



//���еĲ���
/*
* ���еĲ���Ҫ�������һ����һ��Ԫ�ض�û�У���ô�����Ԫ�ؾ���front��back��
* ��������Ԫ�أ���back��nextָ����Ԫ�أ�Ȼ��back=newnode
*/

void QueuePush(Queue* q, DataType data) {
	assert(q);

	QNode* newnode = Buynode(data);
	if (QueueEmpty(q)) {
		q->back = newnode;
		q->front = newnode;
	}
	else {
		q->back->next = newnode;
		q->back = newnode;
	}
}



//���еĴ�С
//ʵ�ַ����򵥣�����ÿ�������һ����
int QueueSize(Queue* q) {
	assert(q);
	int size = 0;
	QNode* cur = q->front;
	while (cur) {
		size++;
		cur = cur->next;
	}
	return size;
}

//�����Ƿ�Ϊ��
//��NULL����һ���Ƚϣ���Ϊ�վͷ���һ����ֵ
//���ͷ����һ��NULL��˵�����ǿ�����


int QueueEmpty(Queue* q) {
	assert(q);
	return NULL == q->front;
}



//���е�����
/*
��ʱһ��ѭ����ÿһ���ڵ��ͷŵ�
������е�Ԫ�ض�ɾ���ˣ���ͷ��β����Ϊ��
������ʦ��ÿ�ν�cur->next �����q->front���ͷ�cur��Ȼ��cur�ٵ���q-��front��
*/


void QueueDestroy(Queue* q) {
	QNode* cur = q->front;
	while (cur) {
		q->front = cur->next;
		free(cur);
		cur = q->front;
	}
	q->front = NULL;
	q->back = NULL;
}




//����ͷ�ڵ�Ԫ�صĻ�ȡ


DataType QueueFront(Queue* q) {
	assert(q);
	return q->front->data;
}

// ����β�ڵ�Ļ�ȡ
DataType QueueBack(Queue* q) {
	assert(q);
	return q->back->data;
}

//���еĲ���




///////////////////////////////////
// ���Զ���
void TestQueue() {
	Queue q;

	QueueInit(&q);

	QueuePush(&q,1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePush(&q, 6);



	printf("%d\n", QueueSize(&q));
	printf("%d\n",QueueFront(&q));
	printf("%d\n", QueueBack(&q));



	QueuePop(&q);

	printf("%d\n", QueueSize(&q));
	printf("%d\n", QueueFront(&q));



	QueuePop(&q);
	printf("%d\n", QueueSize(&q));
	printf("%d\n", QueueFront(&q));



}



int main() {
	TestQueue();
	return 0;
}