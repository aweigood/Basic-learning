
#include"MyListcpp.h"
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

//ջ�ĳ�ʼ��
void StackInit(stack* ps) {
	assert(ps);
	ps->array = (Datapyte*)malloc(sizeof(Datapyte) * 3);//����ռ�,һ��ʼ��������������Լ�
	if (ps->array == NULL) {
		assert(0);
		printf("����ռ�ʧ�ܣ�����");
	}
	ps->capacity = 3;
	ps->size = 0;
}



//���ռ��Ƿ��㹻����������ھͽ��ռ��Ϊ֮ǰ������
void StackCapaCity(stack* ps) {
	//���������Ŀǰ�ռ��Ѿ��������ˣ���Ҫ����
	if (ps->size == ps->capacity) {
		int newcapacity = ps->capacity * 2;
		Datapyte* temp = (Datapyte*)malloc(sizeof(Datapyte) * newcapacity);
		if (temp == NULL) {
			assert(0);
			printf("�ռ俪��ʧ��");
			return;
		}
		else {
			//���ɿռ��Ԫ�ؿ��������¿ռ䵱��
			memcpy(temp, ps->array, sizeof(Datapyte)*ps->size);


			//�ͷžɿռ�
			free(ps->array);

			//ʹ���¿ռ�
			ps->array = temp;
			ps->capacity = newcapacity;


		}
	}
}


//��ջ����
void StackPush(stack* ps,Datapyte data) {
	 StackCapaCity(ps);
	 ps->array[ps->size] = data;
	 ps->size++;
}



//��ջ����
void StackPop(stack* ps) {
	if(StackEmpty(ps))
		return;

	ps->size--;

}


//��ȡջ��Ԫ��
Datapyte Stacktop(stack* ps) {
	assert(ps);
	return ps->array[ps->size-1];
}



//��ȡջ����ЧԪ�ظ���
int StackSize(stack* ps) {
	assert(ps);
	return ps->size;
}



//���ջ�Ƿ�Ϊ��
//���Ϊ�վͷ����棬û�оͷ��ؼ�
int StackEmpty(stack* ps) {
	assert(ps);
	return 0 == ps->size;
}



//ջ������
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
		printf("ջ�Ѿ�Ϊ�գ��޷���ȡջ��Ԫ��!!!\n");
	}

	StcakDestory(&s);
}

int main() {
	TestStack();
	return 0;
}
