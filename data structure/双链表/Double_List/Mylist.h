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

//�������������ͷ�ڵ�
ListNode* ListCreat();



//����ĳ�ʼ��
void ListInit(ListNode** head);




//˫������Ĵ�ӡ

void ListPrintf(ListNode *plist);



//˫�������βɾ

void ListpopBack(ListNode* plist);




//˫�������β��

void ListPushBack(ListNode* plist,DataTtpe x );


//˫�����ͷɾ


void ListPopFront(ListNode* plist);




//˫�������ͷ��

void ListPushFront(ListNode* plist,DataTtpe x);




//˫����Ĳ���

ListNode* ListFind(ListNode* plist, ListNode x);

//˫�����posλ��ǰ����Ԫ��x
void ListInsert(ListNode* pos, ListNode x);



//˫����ɾ��posλ�õĽ�� 

void ListErase(ListNode* pos);



//���˫�������Ч�ڵ�


void ListClear(ListNode* head);

/*
1.�����Ч�ڵ����Ҫ����ʹ�����нڵ㶼�ͷ�
2.����Ҫ��curָ��head����һ����Ҳ���ǵ�һ���ڵ�
3����ͷɾ�ķ�������ͷ�ڵ����һ���ڵ㱣��������ÿ�ζ�ɾ����һ���ڵ�
4.Ҫ�ǵ��ͷŽڵ�
5.ѭ��ֹͣ��������ͷ�ڵ����һ���ڵ�Ϊ��
��ʱ��Ҫ��head����һ��ָ��head����һ��Ҳָ��head
*/











