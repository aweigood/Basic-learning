#pragma once 

//栈的实现是按照顺序表来实现的
//他与顺序表不同的地方就是其不进行顺序表的查找与排序

typedef int Datapyte;


typedef struct stack {
	Datapyte* array;   //指向储存元素的空间
	int capacity;  // 定义大小,就是你最多可以保存的大小
	int size;     //定义有效元素个数，同时也是表示栈顶元素
}stack;







//////////////栈中的相关操作//////////////////
//栈只能从栈顶插入与栈顶出去





//栈的初始化
void StackInit(stack* ps);



//检测空间是否足够，如果不存在就将空间变为之前的两倍
void StackCapaCity(stack* ps);


//入栈操作
void StackPush(stack* ps, Datapyte data);



//出栈操作
void StackPop(stack* ps);


//获取栈顶元素
Datapyte Stacktop(stack* ps);



//获取栈中有效元素
int StackSize(stack* ps);



//检测栈是否为空
int StackEmpty(stack* ps);



//栈的销毁
void StcakDestory(stack* ps);



//栈的测试
void TestStack();