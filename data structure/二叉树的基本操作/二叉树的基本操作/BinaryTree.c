
//建堆的时候的时间复杂度是On，具体方法可以参考讲义，是使用错位相减法进行的
//二叉树的便利方式有前序遍历，中序，后序遍历方式，每一种方式都是先左子树再右子树，唯一的一个区别就是根的便利在哪边


#include<stdio.h>
#include"BinaryTree.h"
#include<assert.h>
#include<stdlib.h>
//树的节点的创建

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



//这个是一个简单的模仿，数的构造并不是这样的，这里是模仿课件中的图片构造出来的一个可以操作的树状结构
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



// 二叉树前序遍历 ,先根再左再右
//假设现在就是遍历之后打印输出，使用递归，出口是为空树的时候
void PreOrder(BTNode* root) {
	if (NULL == root)
		return;

	printf("%d", root->data);
	PreOrder(root->left);//遍历左边就是把二叉树当做一个新的树进行操作
	PreOrder(root->right);
}
//前序遍历的结果是123456


// 二叉树中序遍历
//先左再中再右子树

void InOrder(BTNode* root) {
	if (root == NULL)
		return;

	InOrder(root->left);
	printf("%d", root->data);
	InOrder(root->right);
}

//结果是321546

// 二叉树后序遍历

void PostOrder(BTNode* root) {
	if (root == NULL)
		return;

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d", root->data);
}


//结果就是325641


// 二叉树节点个数

int BinaryTreeSize(BTNode* root) {
	if (root == NULL) return 0;
	return 1 + BinaryTreeSize(root->left) + 
	BinaryTreeSize(root->right);
}


// 二叉树叶子节点个数
//叶子节点的个数就是求左子树中的叶子节点个数加上右子树中叶子节点的个数
//直接求不好求如果知道左子树中叶子节点的个数加上右子树叶子节点的个数就行
int BinaryTreeLeafSize(BTNode* root) {
	if (root == NULL) return 0;

	//这里代表它已经不是空节点了，再加上一个判断，判断是叶子节点,然后让他返回一个1

	if (NULL == root->left && root->right==NULL)
		return 1;
	
		
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
	
	
}


// 二叉树第k层节点个数
/*
* 思路：
* 树是空树就返回0  k也不能小于0
* 直接求不好求，想想是否可以转化为子问题，即到其子树中求，应用递归找到它的k-1层
*/
int BinaryTreeLevelKSize(BTNode* root, int k) {
	if (root == NULL || k <= 0) return 0;
	//如果k等于1，就返回节点总数1
	if (k == 1) return 1;


	//root存在，而且大于1.就要去root子树中求k-1中求节点个数，这样只要它存在肯定可以转到k=1的时候返回为1的节点
	return BinaryTreeLevelKSize(root->left, k - 1) +
		BinaryTreeLevelKSize(root->right, k - 1);

}

// 二叉树查找值为x的节点
//或运算有短路原则，如果第一个表达式不成立才会往右子树中去
BTNode* BinaryTreeFind(BTNode* root, Datatype x) {
	if (root == NULL) return NULL;
	//再在子树中寻找是否有x

	if (root->data == x) {
		return root;
	}
	BTNode* ret;
	//用来接收寻找结果,用来判断接着往下走
	ret = BinaryTreeFind(root->left, x);
	if (ret != NULL) return ret;
	//为NULL就是没找到，不为空说明找到了，ret发生改变了，直接返回就行
	//如果左边没找到直接返回右边就行
	return BinaryTreeFind(root->right, x);



	////或者也可以一步写
	//BTNode* ret;
	//(ret = BinaryTreeFind(root->left, x) || ret == BinaryTreeFind(root->right, x));
	//return ret;
	
}



//二叉树的高度


int BInaryTreeHeight(BTNode* root) {
	if (NULL == root)
		return 0;
	int LeftHeight = BInaryTreeHeight(root->left);
	int RightHeight = BInaryTreeHeight(root->right);
	return LeftHeight > RightHeight ? LeftHeight + 1 : RightHeight + 1;
}



//二叉树的销毁

//如果直接将根节点销毁，就无法通过根节点找到左右子树，应该是先销毁左右子树，再销毁左右子树
//这里要修改的是root所指向的根，proot是根的地址的地址，*proot是根的地址,也就是root，**root是根
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