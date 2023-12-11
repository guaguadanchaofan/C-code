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

//��̬�����ڴ�
QNode* BuyQueueNode(QDataType x)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = x;
	node->_next = NULL;
	return node;
}
//��ʼ��
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = NULL;
	q->_rear = NULL;
}

//��β����
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

//��ͷ����
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

//��ȡ��ͷԪ������
QDataType QueueFront(Queue* q)
{
	assert(q); 
	return  q->_front->_data;
}

//��ȡ��βԪ������
QDataType QueueBack(Queue* q)
{
	assert(q);
	return  q->_rear->_data;
}

//��ȡ��������ЧԪ�ظ��� 
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

//�������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
int  QueueEmpty(Queue* q)
{
	assert(q);
	return q->_front == NULL;
}

//���ٶ���
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

//ǰ�����
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

//�������
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

//�������
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

//����С
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
//��Ҷ�Ӵ�С
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

//������
BinaryTree* CreateTree(BTDataType x)
{
	BinaryTree* node = (BTDataType*)malloc(sizeof(BTDataType));
	node->_a = x;
	node->_left = NULL;
	node->_right = NULL;
	return node;
}

//�����
int maxDepth(BinaryTree* root) {
	if (root == NULL)
	{
		return 0;
	}
	int leftDepth = maxDepth(root->_left);
	int rightDepth = maxDepth(root->_right);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

//��������k��ڵ����
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

//����������ֵΪx�Ľڵ�
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

//����������
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

//�������
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

//�ж��ǲ�����ȫ������
//�Ƿ���1 ���Ƿ���0
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