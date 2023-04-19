#pragma once
typedef int DataType;
typedef struct SListNode
{
	DataType data;
	struct SListNode* next;
}SListNode;


//����ڵ���Զ���
SListNode* BuySListNode( SListNode x);


//�������β��
void SListPushBack(SListNode** pplist, DataType x);

// �������βɾ
void SListPopBack(SListNode** pplist);

// �������ͷ��
void SListPushFront(SListNode** pplist, DataType x);

// ������ͷɾ
void SListPopFront(SListNode** pplist);

// ���������
SListNode* SListFind(SListNode* plist, DataType x);

// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, DataType x);

// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos);


//���������
void SListDestroy(SListNode** plist);

//��������ЧԪ�صĸ�������
int SListSize(SListNode* plist);

//������Ĵ�ӡ
void SListPrint(SListNode* plist);
///////////////////////////////////////////////
// ��������
void TestSList();
