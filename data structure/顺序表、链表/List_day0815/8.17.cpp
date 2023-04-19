#include "Mylist.h"
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


void SeqlistInit(seqlist* ps)
{
	assert(ps);
	ps->arry = (DataType*)malloc(3 * sizeof(DataType));
	if (NULL == ps->arry)
	{
		printf("空间申请失败！！");
		exit(0);
	}
	ps->size = 0;
	ps->capacity = 3;
}

void SeqlistDenstory(seqlist* ps)
{
	assert(ps);
	if (ps->arry)
	{
		free(ps->arry);
		ps->arry = NULL;
		ps->capacity = 0;
		ps->size = 0;
	}
}


void CheckCapctiy(seqlist* ps)
{
	if (ps->capacity == ps->size)
	{
		int newcapacity = ps->capacity * 2;
		DataType* temp = (DataType*)malloc(newcapacity * sizeof(DataType));
		if (temp == NULL)
		{
			printf("申请空间失败！！！");
		}
		else
		{
			free(ps->arry);
			ps->arry = temp;
			ps->capacity = newcapacity;
		}
	}
}

void SeqlistPushback(seqlist* ps,DataType x)
{
	assert(ps);
	ps->arry[ps->size] = x;
	ps->size++;
}


void  SeqlistPopBack(seqlist* ps)
{
	assert(ps);
	if (SeqlistEmpty(ps))
	{
		return;
	}
	ps->size--;
}

int SeqslistFind(seqlist* ps,DataType x)
{
	assert(ps);
	for (int i = 0;i < ps->size;i++)
	{
		if (ps->arry[i] == x)
			return i;
	}
	return -1;
}

//这个是从最后一个往后转，如果从pos处往后的话会导致元素丢失
void SeqlistInstet(seqlist* ps, int pos, DataType x)
{
	assert(ps);
	if (pos > ps->size)
	{
		printf("数组越界");
	}
	else
	{
		for(int i = ps->size-1;i>= pos;i--)
		{
			ps->arry[i + 1] = ps->arry[i];
		}
		ps->arry[pos ] = x;
		ps->size++;
	}
}

DataType SeqlistAt(seqlist* ps, size_t pos)
{
	assert(ps);
	assert(pos < ps->size);
	return ps->arry[pos];
}


DataType SeqlistFront(seqlist* ps)
{
	assert(ps);
	return ps->arry[0];
}


DataType SeqlistBack(seqlist* ps)
{
	assert(ps);
	return ps->arry[ps->size-1];
}


size_t Seqlistcapacity(seqlist* ps)
{
	assert(ps);
	return ps->capacity;
}


size_t SeqlistSize(seqlist* ps)
{
	assert(ps);
	return ps->size;
}

size_t SeqlistEmpty(seqlist* ps)
{
	assert(ps);
	if (ps->size == 0)
		return 0;
	else
		return -1;
}

void seqlistPrintf(seqlist* ps)
{
	for (int i = 0;i < ps->size;i++)
	{
		printf("%d", ps->arry[i]);
	}
	printf("\n");
}

void Textseqlist()
{
	seqlist s;
	SeqlistInit(&s);
	SeqlistPushback(&s, 1);
	SeqlistPushback(&s, 2);
	SeqlistPushback(&s, 3);
	SeqlistPushback(&s, 4);
	SeqlistPushback(&s, 5);

	

	printf("seqList size = %zd\n", SeqlistSize(&s));  // 5
	printf("seqList capacity = %zd\n", Seqlistcapacity(&s));  // 10
	printf("seqList front = %d\n", SeqlistFront(&s));  // 1
	printf("seqList back = %d\n", SeqlistBack(&s));   // 5
	printf("seqList at = %d\n", SeqlistAt(&s, 3));    // 4
	seqlistPrintf(&s);
	SeqlistDenstory(&s);
}



int main()
{
	Textseqlist();
	return 0;
}
