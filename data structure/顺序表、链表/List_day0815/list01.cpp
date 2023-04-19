/*typedef int SLDataType;
// 顺序表的动态存储
typedef struct SeqList
{
	SLDataType* array; ?// 指向动态开辟的数组
	size_t size; ? ? ? // 有效数据个数
	size_t capicity; ? // 容量空间的大小
}SeqList;
// 顺序表初始化
void SeqListInit(SeqList* ps1);
//检查空间，如果满了，进行增容
void CheckCapacity(SeqList* ps1);
//顺序表尾插，检查空间，考虑是否需要扩容
void SeqListPushBack(SeqList* ps1，SLDataType x)
{
	/*
	 前提：顺序表空间足够
	 1.只需要将x插入size的位置
	 2.需要给size加1，因为多了一个新元素
	 3.如果顺序表位子不够的话，要先扩容
*/
/*
	psl ->
}















//顺序表尾删
void SeqListPopBack(SeqList* ps1);
//顺序表头插
void SeqListpushFront(SeqList* ps1， SLDataType x);
|// 顺序表头删
void SeqListPopFront(SeqList * ps1);
//顺序表查找
int SeqListFind(SeqList* ps1，SLDataType x);
//顺序表在pos位置插入x
void SeqListInsert(SeqList* ps1，size_ _t pos， SLDataType x);
//顺序表删除pos位置的值
void SeqListErase(SeqList* ps1，size_ _t pos);
//顺序表销毁
void SeqListDestory(SeqList* ps1);
//顺序表打印
void SeqListPrint(SeqList* ps1);
