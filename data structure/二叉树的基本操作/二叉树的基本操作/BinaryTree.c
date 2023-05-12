
//���ѵ�ʱ���ʱ�临�Ӷ���On�����巽�����Բο����壬��ʹ�ô�λ��������е�
//�������ı�����ʽ��ǰ����������򣬺��������ʽ��ÿһ�ַ�ʽ����������������������Ψһ��һ��������Ǹ��ı������ı�


#include<stdio.h>
#include"BinaryTree.h"
#include<assert.h>
#include<stdlib.h>
//���Ľڵ�Ĵ���

BTNode* BinaryTreeCreat(Datatype data) {
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL) {
		assert(0);
		return NULL;
	}
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}



//�����һ���򵥵�ģ�£����Ĺ��첢���������ģ�������ģ�¿μ��е�ͼƬ���������һ�����Բ�������״�ṹ
BTNode* BinaryTreeGreate() {
	BTNode* node1 = BinaryTreeCreat(1);
	BTNode* node2 = BinaryTreeCreat(2);
	BTNode* node3 = BinaryTreeCreat(3);
	BTNode* node4 = BinaryTreeCreat(4);
	BTNode* node5 = BinaryTreeCreat(5);
	BTNode* node6 = BinaryTreeCreat(6);

	node1->left = node2;
	node1->right = node4;

	node2->left = node3;

	node4->left = node5;
	node4->right = node6;

	return node1;
}



// ������ǰ����� ,�ȸ���������
//�������ھ��Ǳ���֮���ӡ�����ʹ�õݹ飬������Ϊ������ʱ��
void PreOrder(BTNode* root) {
	if (NULL == root)
		return;

	printf("%d", root->data);
	PreOrder(root->left);//������߾��ǰѶ���������һ���µ������в���
	PreOrder(root->right);
}
//ǰ������Ľ����123456


// �������������
//����������������

void InOrder(BTNode* root) {
	if (root == NULL)
		return;

	InOrder(root->left);
	printf("%d", root->data);
	InOrder(root->right);
}

//�����321546

// �������������

void PostOrder(BTNode* root) {
	if (root == NULL)
		return;

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d", root->data);
}


//�������325641


// �������ڵ����

int BinaryTreeSize(BTNode* root) {
	if (root == NULL) return 0;
	return 1 + BinaryTreeSize(root->left) + 
	BinaryTreeSize(root->right);
}


// ������Ҷ�ӽڵ����
//Ҷ�ӽڵ�ĸ����������������е�Ҷ�ӽڵ����������������Ҷ�ӽڵ�ĸ���
//ֱ���󲻺������֪����������Ҷ�ӽڵ�ĸ�������������Ҷ�ӽڵ�ĸ�������
int BinaryTreeLeafSize(BTNode* root) {
	if (root == NULL) return 0;

	//����������Ѿ����ǿսڵ��ˣ��ټ���һ���жϣ��ж���Ҷ�ӽڵ�,Ȼ����������һ��1

	if (NULL == root->left && root->right==NULL)
		return 1;
	
		
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
	
	
}


// ��������k��ڵ����
/*
* ˼·��
* ���ǿ����ͷ���0  kҲ����С��0
* ֱ���󲻺��������Ƿ����ת��Ϊ�����⣬��������������Ӧ�õݹ��ҵ�����k-1��
*/
int BinaryTreeLevelKSize(BTNode* root, int k) {
	if (root == NULL || k <= 0) return 0;
	//���k����1���ͷ��ؽڵ�����1
	if (k == 1) return 1;


	//root���ڣ����Ҵ���1.��Ҫȥroot��������k-1����ڵ����������ֻҪ�����ڿ϶�����ת��k=1��ʱ�򷵻�Ϊ1�Ľڵ�
	return BinaryTreeLevelKSize(root->left, k - 1) +
		BinaryTreeLevelKSize(root->right, k - 1);

}

// ����������ֵΪx�Ľڵ�
//�������ж�·ԭ�������һ�����ʽ�������Ż�����������ȥ
BTNode* BinaryTreeFind(BTNode* root, Datatype x) {
	if (root == NULL) return NULL;
	//����������Ѱ���Ƿ���x

	if (root->data == x) {
		return root;
	}
	BTNode* ret;
	//��������Ѱ�ҽ��,�����жϽ���������
	ret = BinaryTreeFind(root->left, x);
	if (ret != NULL) return ret;
	//ΪNULL����û�ҵ�����Ϊ��˵���ҵ��ˣ�ret�����ı��ˣ�ֱ�ӷ��ؾ���
	//������û�ҵ�ֱ�ӷ����ұ߾���
	return BinaryTreeFind(root->right, x);



	////����Ҳ����һ��д
	//BTNode* ret;
	//(ret = BinaryTreeFind(root->left, x) || ret == BinaryTreeFind(root->right, x));
	//return ret;
	
}



//�������ĸ߶�


int BInaryTreeHeight(BTNode* root) {
	if (NULL == root)
		return 0;
	int LeftHeight = BInaryTreeHeight(root->left);
	int RightHeight = BInaryTreeHeight(root->right);
	return LeftHeight > RightHeight ? LeftHeight + 1 : RightHeight + 1;
}



//������������

//���ֱ�ӽ����ڵ����٣����޷�ͨ�����ڵ��ҵ�����������Ӧ����������������������������������
//����Ҫ�޸ĵ���root��ָ��ĸ���proot�Ǹ��ĵ�ַ�ĵ�ַ��*proot�Ǹ��ĵ�ַ,Ҳ����root��**root�Ǹ�
void BinaryTreeDestory(BTNode** proot) {
	assert(0);
	if (*proot == NULL) {
		return NULL;
	}

	BinaryTreeDestory(&(*proot)->left);
	BinaryTreeDestory(&(*proot)->right);
	free(*proot);


	*proot = NULL;
}


int main() {
	BTNode* root = BinaryTreeGreate();
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	int a = BinaryTreeSize(root);
	printf("%d", BinaryTreeSize(root));
	printf("\n");
	printf("%d\n", BInaryTreeHeight(root));
	printf("%d\n", BinaryTreeLevelKSize(root,3));
	printf("%d\n", BinaryTreeFind(root, 3)->data);
	return 0;
}