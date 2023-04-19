

//c语言中函数传参
/*  1.传值
    2.传地址
    注意：不论是传值还是传地址，形参永远都是实参的一份拷贝
    能否在函数中通过对形参的修改影响实参，取决于形参和实参是够具有关联
*/


/*
#include "MYlist2.h"
#include <stdio.h>
#include<stdlib.h>
#include <assert.h>



SListNode* BuySListNode(DataType x) {
    SListNode*  newnode = (SListNode*)malloc(sizeof(SListNode));//这里是给这个新的节点在堆上申请了一处空间
    if (newnode == NULL)                   //这个就是申请空间失败了，即节点创建失败
    {
        printf("创建节点失败！！");
        exit(0);                         
    }
    newnode->data = x;                 //将参数x保存到值域
    newnode->next = NULL;              //在没有串起来的时候，将下一个地址保存为NULL
    return newnode;                    //将新创建的节点保存起来
}

//单链表的尾插
void SListPushBack(SListNode** pplist, DataType x)
{
    assert(pplist);              //保证品牌pplist这个链表存在
    if (*pplist == NULL)         //如果链表首地址为空，说明这块插入的节点就充当这个单链表的第一个元素
        *pplist = BuySListNode(x);
    else {                       //如果链表中还有其他的元素，这时候需要找到链表的最后一个元素，将他的next地址指向我们插入的这个节点
        SListNode* cur = *pplist;       //要进行遍历，故构建了一个相同类型的变量
        while (cur->next)           //如果是最后一个元素，这个元素的下一个就会为空，跳出循环
        {
            cur = cur->next;        //相当数组中的i++
        }
        cur->next = BuySListNode(x);   //跳出循环说明他是最后一个元素了。将它指向我们要插入的元素就行啦
    }

}


// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
    assert(pplist);
    if (*pplist == NULL)
        return;
    else if((*pplist)->next==NULL) {    //若链表只有一个元素的时候，将他释放掉，再讲链表的首地址指向NULL，否则会造成野指针的产生
        free(*pplist);
        *pplist = NULL;
    }
    else {
        SListNode* cur = *pplist;      //用来遍历数组
        SListNode* prev = NULL;       //保存上一个元素的地址
        while (cur->next)
        {
            prev = cur;
            cur = cur->next;

        }                           //当cur为最后同
        free(cur);
        prev->next = NULL;
    }
}

// 单链表的头插
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

// 单链表头删
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

// 单链表查找
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

//删除pos之后的值
void SListEraseAfter(SListNode* pos) {
    if (pos == NULL || pos->next == NULL)    //如果pos是空或者他是最后一个元素，都不能进行尾删
    {
        return;
    }
    SListNode* cur = pos->next;           //保存next的地址，以便释放
    pos->next = cur->next;
    free(cur);
}

//在某个元素之后插入X
void SListInsertAfter(SListNode* pos, DataType x) {
    if (pos == NULL)
        return;
    else {
        SListNode* cur = BuySListNode(x);
         cur->next = pos->next;
        pos->next = cur;
    }
}

//链表的销毁
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

//单链表的打印
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