/*typedef int SLDataType;
// ˳���Ķ�̬�洢
typedef struct SeqList
{
	SLDataType* array; ?// ָ��̬���ٵ�����
	size_t size; ? ? ? // ��Ч���ݸ���
	size_t capicity; ? // �����ռ�Ĵ�С
}SeqList;
// ˳����ʼ��
void SeqListInit(SeqList* ps1);
//���ռ䣬������ˣ���������
void CheckCapacity(SeqList* ps1);
//˳���β�壬���ռ䣬�����Ƿ���Ҫ����
void SeqListPushBack(SeqList* ps1��SLDataType x)
{
	/*
	 ǰ�᣺˳���ռ��㹻
	 1.ֻ��Ҫ��x����size��λ��
	 2.��Ҫ��size��1����Ϊ����һ����Ԫ��
	 3.���˳���λ�Ӳ����Ļ���Ҫ������
*/
/*
	psl ->
}















//˳���βɾ
void SeqListPopBack(SeqList* ps1);
//˳���ͷ��
void SeqListpushFront(SeqList* ps1�� SLDataType x);
|// ˳���ͷɾ
void SeqListPopFront(SeqList * ps1);
//˳������
int SeqListFind(SeqList* ps1��SLDataType x);
//˳�����posλ�ò���x
void SeqListInsert(SeqList* ps1��size_ _t pos�� SLDataType x);
//˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps1��size_ _t pos);
//˳�������
void SeqListDestory(SeqList* ps1);
//˳����ӡ
void SeqListPrint(SeqList* ps1);
