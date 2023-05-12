#pragma once



typedef int Datatype;

//�������Ķ����кܶ�����������ʹ�ú��Ӷ��巨

typedef struct BTNode {
	Datatype* left;
	Datatype* right;
	Datatype data;
}BTNode;


//���Ĵ���
BTNode* BinaryTreeGreate();



// ������ǰ����� 

void PreOrder(BTNode* root);

// �������������

void InOrder(BTNode* root);

// �������������

void PostOrder(BTNode* root);

// �������ڵ����

int BinaryTreeSize(BTNode* root);

// ������Ҷ�ӽڵ����

int BinaryTreeLeafSize(BTNode* root);

// ��������k��ڵ����

int BinaryTreeLevelKSize(BTNode* root, int k);

// ����������ֵΪx�Ľڵ�

BTNode* BinaryTreeFind(BTNode* root, Datatype x);

//�������ĸ߶�
int BInaryTreeHeight(BTNode* root);

//������������
void BinaryTreeDestory(BTNode** root);


