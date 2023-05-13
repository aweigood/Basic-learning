#pragma once


typedef int DataType;


//定义一个函数指针
typedef int(*PFUNC)(DataType left, DataType right);//函数指针要求把重命名写到前边，这样PFUNC就成为一个类型了


typedef struct Heap {
	DataType* array;//传入数组的地址
	int CapaCity;
	int size;
}Heap;


//为了实现大堆和小堆的不同实现，我们可以使用一个函数来代替比较的那一快

//这里只是将数据的值传入进行比较了
DataType Less(DataType left, DataType right) {
	return left > right;
}


DataType Greater(DataType left, DataType right) {
	return right > left;
}

//如果需要的改变的话只需要将这个函数指针变量加入到结构体变量中进行调整就可以了

////////////////////////////堆的两种调整/////////////////////////////////



//堆的向下调整
void AdjustDown(Heap* hp, int parent);


//堆的向上调整
void AdjustUp(Heap* hp, int child);





/////////////////////////堆的各种实现////////////////////////////////////////


//堆的构建


void HeapCreat(Heap* hp, DataType* a, int n);
//堆的构建需要先将数组传进来，然后再调整成堆的格式。传入数组的指针，







//堆的销毁


void HeapDestory(Heap* hp);
//堆的销毁就是将堆中申请的空间释放掉


//堆的插入

void HeapPush(Heap* hp, DataType x);
//堆的插入就是将元素插入后再次调整，保证堆的结构完整



//堆的删除

void HeapPop(Heap* hp);
//将堆顶元素删除之后再进行调整，再将个数减一



//获取堆顶元素

DataType HeapTop(Heap* hp);
//比较简单，就是将数组的第一个元素a[0]输出就行


//堆中数据的个数

int HeapSize(Heap* hp);
//就是将堆中的个数输出就行



//堆的判空

int HeapEmpty(Heap* hp);
//直接就是判断堆元素个数是否为0


////////测试////////
void TestHeap();