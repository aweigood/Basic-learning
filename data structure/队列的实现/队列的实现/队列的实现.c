#include<stdio.h>

#include "mylist.h"
#include<assert.h>

#include<stdlib.h>
//使用队列采用不带头的单链表（这一次）




//队列的初始化
void QueueInit(Queue* q) {
	assert(q);

	q->back = NULL;
	q->front = NULL;
}



//节点的创建
//先申请一个空间，然后将数据和下一个元素的地址初始化
QNode* Buynode(DataType data) {
	QNode* newnode = (QNode*)malloc(sizeof(DataType));
	if (newnode == NULL) {
		assert(0);
		printf("创建空间失败\n");
	}
	newnode->data = data;
	newnode->next = NULL;

	return newnode;
}


//队列的删除
/*
首先要进行一个判断，队列中只有一个节点和
没有节点和
有多个节点三种情况
*/
void QueuePop(Queue* q) {
	assert(q);
	if (QueueEmpty(q)) {
		return;
	}
	//只有一个节点的时候
	else if (q->back == q->front) {
		free(q->front);
		//这时候头和尾是一个节点，释放就没有节点了
		//之后要将队列的头和尾节点都置为空
		q->back = NULL;
		q->front = NULL;
	}

	//有多个节点
	else {
		QNode* temp = q->front;
		q->front =temp->next;
		free(temp);
	}
}

//也可以将有一个节点和多个节点放在一起,就是加上一个判断，
//如果删完之后头节点已经为NULL之后，说明只有一个节点，要将back也置为空
/*
	if (QueueEmpty) {
		return;
	}
	else{
	    Queue* temp = q->front;
		q->front = q->front->next;
		free(temp);
		if(q->front==NULL）{
		q->back=BULL;
		}
	    
	}
*/



//队列的插入
/*
* 队列的插入要分情况，一种是一个元素都没有，那么插入的元素就是front和back，
* 或者是有元素，让back的next指向新元素，然后back=newnode
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



//队列的大小
//实现方法简单，就是每次往后加一就行
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

//队列是否为空
//和NULL进行一个比较，都为空就返回一个真值
//如果头就是一个NULL，说明就是空链表


int QueueEmpty(Queue* q) {
	assert(q);
	return NULL == q->front;
}



//队列的销毁
/*
及时一个循环将每一个节点释放掉
最后所有的元素都删完了，将头和尾都置为空
这里老师是每次将cur->next 保存给q->front，释放cur，然后将cur再等于q-》front；
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




//队列头节点元素的获取


DataType QueueFront(Queue* q) {
	assert(q);
	return q->front->data;
}

// 队列尾节点的获取
DataType QueueBack(Queue* q) {
	assert(q);
	return q->back->data;
}

//队列的测试




///////////////////////////////////
// 测试队列
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