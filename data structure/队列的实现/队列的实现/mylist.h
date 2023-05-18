#pragma once


/*队列（queue）是只允许在一端进行插入操作，而在另一端进行删除操作的线性表。
队列是一种先进先出（First In First Out）的线性表，简称FIFO。允许插入的一端称
为队尾，允许删除的一端称为队头。
*/

//头删和尾插


typedef int DataType;


//节点的结构体
typedef struct QNode {
	struct QNode* next;
	DataType data;
}QNode;



//队列的结构体
typedef struct Queue {
	QNode* front;//指向头节点
	QNode* back;//指向尾节点

}Queue;





//节点的创建
QNode* Buynode(DataType data);


//队列的初始化
void QueueInit(Queue* q);





//队列的插入
void QueuePush(Queue* q, DataType data);





//队列的删除

void QueuePop(Queue* q);




//队列的大小
int QueueSize(Queue* q);

//队列是否为空


int QueueEmpty(Queue* q);

//队列的销毁



void QueueDestroy(Queue* q);




//队列头节点元素的获取


DataType QueueFront(Queue* q);

// 队列尾节点的获取
DataType QueueBack(Queue* q);

//队列的测试




///////////////////////////////////
// 测试队列
void TestQueue();