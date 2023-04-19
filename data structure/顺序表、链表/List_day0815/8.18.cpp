

//c�����к�������
/*  1.��ֵ
    2.����ַ
    ע�⣺�����Ǵ�ֵ���Ǵ���ַ���β���Զ����ʵ�ε�һ�ݿ���
    �ܷ��ں�����ͨ�����βε��޸�Ӱ��ʵ�Σ�ȡ�����βκ�ʵ���ǹ����й���
*/


/*
#include "MYlist2.h"
#include <stdio.h>
#include<stdlib.h>
#include <assert.h>



SListNode* BuySListNode(DataType x) {
    SListNode*  newnode = (SListNode*)malloc(sizeof(SListNode));//�����Ǹ�����µĽڵ��ڶ���������һ���ռ�
    if (newnode == NULL)                   //�����������ռ�ʧ���ˣ����ڵ㴴��ʧ��
    {
        printf("�����ڵ�ʧ�ܣ���");
        exit(0);                         
    }
    newnode->data = x;                 //������x���浽ֵ��
    newnode->next = NULL;              //��û�д�������ʱ�򣬽���һ����ַ����ΪNULL
    return newnode;                    //���´����Ľڵ㱣������
}

//�������β��
void SListPushBack(SListNode** pplist, DataType x)
{
    assert(pplist);              //��֤Ʒ��pplist����������
    if (*pplist == NULL)         //��������׵�ַΪ�գ�˵��������Ľڵ�ͳ䵱���������ĵ�һ��Ԫ��
        *pplist = BuySListNode(x);
    else {                       //��������л���������Ԫ�أ���ʱ����Ҫ�ҵ���������һ��Ԫ�أ�������next��ַָ�����ǲ��������ڵ�
        SListNode* cur = *pplist;       //Ҫ���б������ʹ�����һ����ͬ���͵ı���
        while (cur->next)           //��������һ��Ԫ�أ����Ԫ�ص���һ���ͻ�Ϊ�գ�����ѭ��
        {
            cur = cur->next;        //�൱�����е�i++
        }
        cur->next = BuySListNode(x);   //����ѭ��˵���������һ��Ԫ���ˡ�����ָ������Ҫ�����Ԫ�ؾ�����
    }

}


// �������βɾ
void SListPopBack(SListNode** pplist)
{
    assert(pplist);
    if (*pplist == NULL)
        return;
    else if((*pplist)->next==NULL) {    //������ֻ��һ��Ԫ�ص�ʱ�򣬽����ͷŵ����ٽ�������׵�ַָ��NULL����������Ұָ��Ĳ���
        free(*pplist);
        *pplist = NULL;
    }
    else {
        SListNode* cur = *pplist;      //������������
        SListNode* prev = NULL;       //������һ��Ԫ�صĵ�ַ
        while (cur->next)
        {
            prev = cur;
            cur = cur->next;

        }                           //��curΪ���ͬ
        free(cur);
        prev->next = NULL;
    }
}

// �������ͷ��
void SListPushFront(SListNode** pplist, DataType x)
{
    assert(pplist);
    if ((*pplist) == NULL)
    {
        *pplist = BuySListNode(x);
    }
    SListNode* newnode = BuySListNode(x);
    newnode->next = *pplist;
    *pplist = newnode;
}

// ������ͷɾ
void SListPopFront(SListNode** pplist)
{
    assert(pplist);
    if ((*pplist) == NULL)
    {
        return;
    }
    SListNode* cor = *pplist;
    *pplist = cor->next;
    free(cor);
}

// ���������
SListNode* SListFind(SListNode* plist, DataType x)
{
    assert(plist);
    if (plist == NULL)
    {
        return NULL;
    }
    SListNode* cur = plist;
    while (cur)
    {
        if (cur->data == x)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

//ɾ��pos֮���ֵ
void SListEraseAfter(SListNode* pos) {
    if (pos == NULL || pos->next == NULL)    //���pos�ǿջ����������һ��Ԫ�أ������ܽ���βɾ
    {
        return;
    }
    SListNode* cur = pos->next;           //����next�ĵ�ַ���Ա��ͷ�
    pos->next = cur->next;
    free(cur);
}

//��ĳ��Ԫ��֮�����X
void SListInsertAfter(SListNode* pos, DataType x) {
    if (pos == NULL)
        return;
    else {
        SListNode* cur = BuySListNode(x);
         cur->next = pos->next;
        pos->next = cur;
    }
}

//���������
void SListDestroy(SListNode** plist)
{
    assert(plist);
    SListNode* cur = *plist;
    while (cur)
    {
        *plist = cur->next;
        free(cur);
        cur = *plist;
    }
    plist = NULL;
}

int SListSize(SListNode* plist) {
    int count = 0;
    SListNode* cur = plist;
    while (cur)
    {
        count++;
        cur = cur->next;
    }
    return count;
}

//������Ĵ�ӡ
void SListPrint(SListNode* plist) {
    assert(plist);
    SListNode* cur = plist;
    while (cur)
    {
        printf("%d", cur->data);
        cur = cur->next;
    }
    printf("\tNULL\n");
}

void TestSList2()
{
    SListNode* plist = NULL;

    SListPushFront(&plist, 1);
    SListPushFront(&plist, 2);
    SListPushFront(&plist, 3);
    SListPushFront(&plist, 4);
    SListPushFront(&plist, 5);
    printf("size = %d\n", SListSize(plist));
    SListPrint(plist);

    SListPopFront(&plist);
    printf("size = %d\n", SListSize(plist));
    SListPrint(plist);

    SListPopFront(&plist);
    SListPopFront(&plist);
    SListPopFront(&plist);

    printf("size = %d\n", SListSize(plist));
    SListPrint(plist);

    SListPopFront(&plist);
    SListPopFront(&plist);
    SListDestroy(&plist);
}
void TestSList3()
{
    SListNode* plist = NULL;

    SListPushBack(&plist, 1);
    SListPushBack(&plist, 2);
    SListPushBack(&plist, 3);
    SListPushBack(&plist, 4);
    SListPushBack(&plist, 5);
    SListPrint(plist);

    SListInsertAfter(SListFind(plist, 3), 6);
    SListPrint(plist);

    SListInsertAfter(SListFind(plist, 5), 7);
    SListPrint(plist);

    SListEraseAfter(SListFind(plist, 3));
    SListPrint(plist);

    SListEraseAfter(SListFind(plist, 5));
    SListPrint(plist);

    SListDestroy(&plist);
}

int main()
{
   // TestSList2();
    TestSList3();
    return 0;
}
*/