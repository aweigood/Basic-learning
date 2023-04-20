#include "Mylist.h"
#include<stdlib.h>


//节点的创建
ListNode* BuyListNode(DataTtpe data)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (NULL == newnode) {
		assert(0);//就是报告这里出现问题
		printf("节点创建失败！！！！");
		return NULL;
	}


	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;

}


//链表的初始化
//只需要将头节点创建好，然后将形参带出去，注意，形参必须要用二级指针

void ListInit(ListNode** head) {
	assert(head);

	*head = BuyListNode(0);
	(*head)->next = *head;
	(*head)->prev = *head;

}


//双向链表的打印
//循环一遍，将cur->data的值打印出来

void ListPrintf(ListNode* plist) {
	ListNode* cur = plist->next;
	while (cur) {
		printf("%d", cur->data);
		cur = cur->next;
	}
	printf("\n");
}



//双向链表的尾删
//循环双向链表的尾删相当于就是删除头节点的前一个元素

void ListpopBack(ListNode* plist)
{
	ListErase(plist);

}




//双向链表的尾插
//就是在头结点的前边添加元素
void ListPushBack(ListNode* plist, DataTtpe x) {
	ListInsert(plist, x);
}


//双链表的头删


void ListPopFront(ListNode* plist) {
	ListErase(plist->next);
}




//双向链表的头插

void ListPushFront(ListNode* plist, DataTtpe x) {
	ListInsert(plist->next, x);
}




//双链表的查找

ListNode* ListFind(ListNode* plist, DataTtpe x) {
	ListNode* cur = plist->next;
	while (cur) {
		if (cur->data == x) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//双链表的pos位置前插入元素x
void ListInsert(ListNode* pos, DataTtpe x) {
	ListNode* newnode = BuyListNode(x);
	if (pos == NULL)
		return;
	//创建新节点
	/*
	* 1.首先应该先要插入新节点，再将两边断开
	*/
	newnode->next = pos;
	newnode->prev = pos->prev;

	newnode->prev->next = newnode;
	pos->prev = newnode;


}






//双链表删除pos位置的结点 

void ListErase(ListNode* pos) {
	if (pos == NULL)
		return;
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

//清除有效节点
void ListClear(ListNode* head) {
	ListNode* cur = head->next;
	while (cur != NULL) {
		head->next = cur->next;
		free(cur);
		cur = head->next;
	}
	head->next = head;
	head->prev = head;
}