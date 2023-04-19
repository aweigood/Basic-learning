#pragma once
#include<stddef.h>

typedef int DataType;
typedef struct seqlist
{
	DataType* arry;//指向储存元素的空间
	int size;//有效元素的个数
	int capacity;//表中最多可以储存的元素个数
}seqlist;

//要对顺序表进行初始化
void SeqlistInit(seqlist* ps);


//使用完成之后要对顺序表中的数据进行一个释放，即顺序表的销毁

void SeqlistDenstory(seqlist *ps);


//要对顺序表进行一个空间检查，如果满了，要进行一个增容
void CheckCapctiy(seqlist* ps);


//顺序表尾插
void SeqlistPushback(seqlist* ps,DataType x);


//顺序表尾删
void  SeqlistPopBack(seqlist* ps);


//顺序表查找
int SeqslistFind(seqlist* ps,DataType x);


//在顺序表pos处插入元素
void SeqlistInstet(seqlist* ps,int pos,DataType x );


//获取任意位置的元素
DataType SeqlistAt(seqlist* ps,size_t pos);


//获取起始位置的元素
DataType SeqlistFront(seqlist* ps);



//获取最后一个位置的元素
DataType SeqlistBack(seqlist* ps);



//获取有效元素的个数
size_t Seqlistcapacity(seqlist* ps);


//获取容量的大小
size_t SeqlistSize(seqlist* ps);


//检测是否为空，为空泽返回真，否则返回假
size_t SeqlistEmpty(seqlist* ps);

//测试
void Textseqlist();


//顺序表打印
void seqlistPrintf(seqlist* ps);

