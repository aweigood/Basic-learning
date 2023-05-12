#pragma once



typedef int Datatype;

//二叉树的定义有很多种这里我们使用孩子定义法

typedef struct BTNode {
	Datatype* left;
	Datatype* right;
	Datatype data;
}BTNode;


//树的创建
BTNode* BinaryTreeGreate();



// 二叉树前序遍历 

void PreOrder(BTNode* root);

// 二叉树中序遍历

void InOrder(BTNode* root);

// 二叉树后序遍历

void PostOrder(BTNode* root);

// 二叉树节点个数

int BinaryTreeSize(BTNode* root);

// 二叉树叶子节点个数

int BinaryTreeLeafSize(BTNode* root);

// 二叉树第k层节点个数

int BinaryTreeLevelKSize(BTNode* root, int k);

// 二叉树查找值为x的节点

BTNode* BinaryTreeFind(BTNode* root, Datatype x);

//二叉树的高度
int BInaryTreeHeight(BTNode* root);

//二叉树的销毁
void BinaryTreeDestory(BTNode** root);


