#pragma once
#include <stdio.h>
#include <assert.h>
#include<malloc.h>

typedef int DataTtpe;

typedef struct ListNode {
	DataTtpe data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

//创建返回链表的头节点
ListNode* ListCreat();



//链表的初始化
void ListInit(ListNode** head);




//双向链表的打印

void ListPrintf(ListNode *plist);



//双向链表的尾删

void ListpopBack(ListNode* plist);




//双向链表的尾插

void ListPushBack(ListNode* plist,DataTtpe x );


//双链表的头删


void ListPopFront(ListNode* plist);




//双向链表的头插

void ListPushFront(ListNode* plist,DataTtpe x);




//双链表的查找

ListNode* ListFind(ListNode* plist, ListNode x);

//双链表的pos位置前插入元素x
void ListInsert(ListNode* pos, ListNode x);



//双链表删除pos位置的结点 

void ListErase(ListNode* pos);



//清除双链表的有效节点


void ListClear(ListNode* head);

/*
1.清除有效节点就是要遍历使得所有节点都释放
2.首先要让cur指向head的下一个，也就是第一个节点
3采用头删的方法，将头节点的下一个节点保存起来，每次都删除第一个节点
4.要记得释放节点
5.循环停止条件就是头节点的下一个节点为空
这时候要让head的下一个指向head，上一个也指向head
*/











