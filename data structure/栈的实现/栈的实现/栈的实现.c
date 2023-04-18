
#include"MyListcpp.h"
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

//栈的初始化
void StackInit(stack* ps) {
	assert(ps);
	ps->array = (Datapyte*)malloc(sizeof(Datapyte) * 3);//申请空间,一开始给三个，这个看自己
	if (ps->array == NULL) {
		assert(0);
		printf("申请空间失败！！！");
	}
	ps->capacity = 3;
	ps->size = 0;
}



//检测空间是否足够，如果不存在就将空间变为之前的两倍
void StackCapaCity(stack* ps) {
	//这里代表着目前空间已经储存满了，需要扩容
	if (ps->size == ps->capacity) {
		int newcapacity = ps->capacity * 2;
		Datapyte* temp = (Datapyte*)malloc(sizeof(Datapyte) * newcapacity);
		if (temp == NULL) {
			assert(0);
			printf("空间开辟失败");
			return;
		}
		else {
			//将旧空间的元素拷贝到最新空间当中
			memcpy(temp, ps->array, sizeof(Datapyte)*ps->size);


			//释放旧空间
			free(ps->array);

			//使用新空间
			ps->array = temp;
			ps->capacity = newcapacity;


		}
	}
}


//入栈操作
void StackPush(stack* ps,Datapyte data) {
	 StackCapaCity(ps);
	 ps->array[ps->size] = data;
	 ps->size++;
}



//出栈操作
void StackPop(stack* ps) {
	if(StackEmpty(ps))
		return;

	ps->size--;

}


//获取栈顶元素
Datapyte Stacktop(stack* ps) {
	assert(ps);
	return ps->array[ps->size-1];
}



//获取栈中有效元素个数
int StackSize(stack* ps) {
	assert(ps);
	return ps->size;
}



//检测栈是否为空
//如果为空就返回真，没有就返回假
int StackEmpty(stack* ps) {
	assert(ps);
	return 0 == ps->size;
}



//栈的销毁
void StcakDestory(stack* ps) {
	assert(ps);
	free(ps->array);
	ps->array = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

void TestStack()
{
	stack s;
	StackInit(&s);

	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPush(&s, 6);
	printf("size = %d\n", StackSize(&s));
	printf("top = %d\n", Stacktop(&s));

	StackPop(&s);
	StackPop(&s);
	StackPop(&s);
	printf("size = %d\n", StackSize(&s));
	printf("top = %d\n", Stacktop(&s));

	StackPop(&s);
	StackPop(&s);
	printf("size = %d\n", StackSize(&s));
	printf("top = %d\n", Stacktop(&s));

	StackPop(&s);
	printf("size = %d\n", StackSize(&s));
	if (!StackEmpty(&s))
	{
		printf("top = %d\n", Stacktop(&s));
	}
	else
	{
		printf("栈已经为空，无法获取栈顶元素!!!\n");
	}

	StcakDestory(&s);
}

int main() {
	TestStack();
	return 0;
}
