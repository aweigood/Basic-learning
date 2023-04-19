#pragma once
typedef int DataType;
typedef struct SListNode
{
	DataType data;
	struct SListNode* next;
}SListNode;


//创造节点和自定义
SListNode* BuySListNode( SListNode x);


//单链表的尾插
void SListPushBack(SListNode** pplist, DataType x);

// 单链表的尾删
void SListPopBack(SListNode** pplist);

// 单链表的头插
void SListPushFront(SListNode** pplist, DataType x);

// 单链表头删
void SListPopFront(SListNode** pplist);

// 单链表查找
SListNode* SListFind(SListNode* plist, DataType x);

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, DataType x);

// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos);


//链表的销毁
void SListDestroy(SListNode** plist);

//链表中有效元素的个数计算
int SListSize(SListNode* plist);

//单链表的打印
void SListPrint(SListNode* plist);
///////////////////////////////////////////////
// 测试链表
void TestSList();
