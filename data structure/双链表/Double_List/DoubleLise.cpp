#include "Mylist.h"
#include<stdlib.h>


//�ڵ�Ĵ���
ListNode* BuyListNode(DataTtpe data)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (NULL == newnode) {
		assert(0);//���Ǳ��������������
		printf("�ڵ㴴��ʧ�ܣ�������");
		return NULL;
	}


	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;

}


//����ĳ�ʼ��
//ֻ��Ҫ��ͷ�ڵ㴴���ã�Ȼ���βδ���ȥ��ע�⣬�βα���Ҫ�ö���ָ��

void ListInit(ListNode** head) {
	assert(head);

	*head = BuyListNode(0);
	(*head)->next = *head;
	(*head)->prev = *head;

}


//˫������Ĵ�ӡ
//ѭ��һ�飬��cur->data��ֵ��ӡ����

void ListPrintf(ListNode* plist) {
	ListNode* cur = plist->next;
	while (cur) {
		printf("%d", cur->data);
		cur = cur->next;
	}
	printf("\n");
}



//˫�������βɾ
//ѭ��˫�������βɾ�൱�ھ���ɾ��ͷ�ڵ��ǰһ��Ԫ��

void ListpopBack(ListNode* plist)
{
	ListErase(plist);

}




//˫�������β��
//������ͷ����ǰ�����Ԫ��
void ListPushBack(ListNode* plist, DataTtpe x) {
	ListInsert(plist, x);
}


//˫�����ͷɾ


void ListPopFront(ListNode* plist) {
	ListErase(plist->next);
}




//˫�������ͷ��

void ListPushFront(ListNode* plist, DataTtpe x) {
	ListInsert(plist->next, x);
}




//˫����Ĳ���

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

//˫�����posλ��ǰ����Ԫ��x
void ListInsert(ListNode* pos, DataTtpe x) {
	ListNode* newnode = BuyListNode(x);
	if (pos == NULL)
		return;
	//�����½ڵ�
	/*
	* 1.����Ӧ����Ҫ�����½ڵ㣬�ٽ����߶Ͽ�
	*/
	newnode->next = pos;
	newnode->prev = pos->prev;

	newnode->prev->next = newnode;
	pos->prev = newnode;


}






//˫����ɾ��posλ�õĽ�� 

void ListErase(ListNode* pos) {
	if (pos == NULL)
		return;
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

//�����Ч�ڵ�
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