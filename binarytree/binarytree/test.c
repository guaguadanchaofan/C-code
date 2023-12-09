#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
typedef char BTDataType;

typedef struct BinaryTree
{
	BTDataType _a;
	struct BinaryTree* _left;
	struct BinaryTree* _right;
}BinaryTree;



//前序遍历
void prevOrder(BinaryTree* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->_a);
	prevOrder(root->_left);
	prevOrder(root->_right);
}

//中序遍历
void InOrder(BinaryTree* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->_left);
	printf("%c ", root->_a);
	InOrder(root->_right);
}

//后序遍历
void PostOrder(BinaryTree* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->_left);
	PostOrder(root->_right);
	printf("%c ", root->_a);
}

//树大小
int TreeSize(BinaryTree* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + TreeSize(root->_left) + TreeSize(root->_right);
	}
}
//树叶子大小
int TreeLeafSize(BinaryTree* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return TreeLeafSize(root->_left) + TreeLeafSize(root->_right);
}

//创建树
BinaryTree* CreateTree(BTDataType x)
{
	BinaryTree* node = (BTDataType*)malloc(sizeof(BTDataType));
	node->_a = x;
	node->_left = NULL;
	node->_right = NULL;
	return node;
}
int maxDepth(BinaryTree* root) {
	if (root == NULL)
	{
		return 0;
	}
	int leftDepth = maxDepth(root->_left);
	int rightDepth = maxDepth(root->_right);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}
int main()
{
	BinaryTree* A = CreateTree('A');
	BinaryTree* B = CreateTree('B');
	BinaryTree* C = CreateTree('C');
	BinaryTree* D = CreateTree('D');
	BinaryTree* E = CreateTree('E');
	A->_left = B;
	A->_right = C;
	B->_left = D;
	B->_right = E;
	prevOrder(A);
	printf("\n");
	InOrder(A);
	printf("\n");
	PostOrder(A);
	printf("\n");
	printf("TreeSize:%d\n", TreeSize(A));
	printf("TreeLeafSize:%d\n", TreeLeafSize(A));
	int ret = maxDepth(A);
	return 0;
}