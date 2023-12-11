#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef char BTDataType;

typedef struct BinaryTree
{
	BTDataType _a;
	struct BinaryTree* _left;
	struct BinaryTree* _right;
}BinaryTree;

typedef  BinaryTree* QDataType;

typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;


typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

//动态申请内存
QNode* BuyQueueNode(QDataType x)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = x;
	node->_next = NULL;
	return node;
}
//初始化
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = NULL;
	q->_rear = NULL;
}

//队尾进队
void QueuePush(Queue* q, QDataType x)
{
	assert(q);
	QNode* cur = BuyQueueNode(x);
	if (q->_front == NULL)
	{
		q->_front = q->_rear = cur;
	}
	else
	{
		q->_rear->_next = cur;
		q->_rear = cur;
	}
}

//队头出队
void QueuePop(Queue* q)
{
	assert(q);
	if (q->_front == NULL)
	{
		return;
	}
	else
	{
		QNode* save = q->_front->_next;
		free(q->_front);
		q->_front = save;
	}
}

//获取队头元素数据
QDataType QueueFront(Queue* q)
{
	assert(q); 
	return  q->_front->_data;
}

//获取队尾元素数据
QDataType QueueBack(Queue* q)
{
	assert(q);
	return  q->_rear->_data;
}

//获取队列中有效元素个数 
int  QueueSize(Queue* q)
{
	assert(q);
	QNode* cur = q->_front;
	int count = 0;
	while (cur)
	{
		cur = cur->_next;
		count++;
	}
	return count;
}

//检测队列是否为空，如果为空返回非零结果，如果非空返回0
int  QueueEmpty(Queue* q)
{
	assert(q);
	return q->_front == NULL;
}

//销毁队列
void QueueDestory(Queue* q)
{
	assert(q);
	if (q->_front == NULL)
	{
		return;
	}

	while (q->_front)
	{
		QueuePop(q);
	}
}

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

//树深度
int maxDepth(BinaryTree* root) {
	if (root == NULL)
	{
		return 0;
	}
	int leftDepth = maxDepth(root->_left);
	int rightDepth = maxDepth(root->_right);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

//二叉树第k层节点个数
int BinaryTreeLevelKSize(BinaryTree* root,int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

//二叉树查找值为x的节点
BinaryTree* BinaryTreeFind(BinaryTree* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->_a == x)
	{
		return root;
	}
	BinaryTree* node = BinaryTreeFind(root->_left, x);
	if (node)
	{
		return node;
	}
	node = BinaryTreeFind(root->_right, x);
	if (node)
	{
		return node;
	}
	return NULL;
}

//二叉树销毁
void BinaryTreeDestory(BinaryTree* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeDestory(root->_left);
	BinaryTreeDestory(root->_right);
	free(root);
}

//层序遍历
void BinaryTreeLevelOrder(BinaryTree* root)
{
	if (root == NULL)
	{
		return;
	}
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BinaryTree* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->_a);
		if (front->_left)
		{
			QueuePush(&q, front->_left);
		}
		if (front->_right)
		{
			QueuePush(&q, front->_right);
		}
	}
	printf("\n");
}

//判断是不是完全二叉树
//是返回1 不是返回0
int BinaryTreeComplete(BinaryTree* root)
{
	if (root == NULL)
	{
		return 1;
	}
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BinaryTree* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
		{
			break;
		}
		QueuePush(&q, front->_left);
		QueuePush(&q, front->_right);
	}
	while (!QueueEmpty(&q))
	{
		if (QueueFront(&q)!=NULL)
		{
			QueueDestory(&q);
			return 0;
		}
		QueuePop(&q);
	}
	QueueDestory(&q);
	return 1;
}
int main()
{
	BinaryTree* A = CreateTree('A');
	BinaryTree* B = CreateTree('B');
	BinaryTree* C = CreateTree('C');
	BinaryTree* D = CreateTree('D');
	BinaryTree* E = CreateTree('E');
	BinaryTree* F = CreateTree('F');
	A->_left = B;
	A->_right = C;
	B->_left = D;
	B->_right = E;
	C->_right = F;
	prevOrder(A);
	printf("\n");
	InOrder(A);
	printf("\n");
	PostOrder(A);
	printf("\n");
	printf("TreeSize:%d\n", TreeSize(A));
	printf("TreeLeafSize:%d\n", TreeLeafSize(A));
	int ret = maxDepth(A);
	int k = 3;
	printf("BinaryTreeLevelKSize:%d", BinaryTreeLevelKSize(A, k));
	printf("\n");
	printf("%c ", BinaryTreeFind(A, 'B')->_a);
	printf("\n");
	BinaryTreeLevelOrder(A);
	printf("%d ", BinaryTreeComplete(A));
	return 0;
}