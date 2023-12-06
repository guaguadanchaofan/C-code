#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int QDataType;

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


typedef struct {
	Queue q1;
	Queue q2;
} MyStack;


MyStack* myStackCreate() {
	MyStack* ms = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&ms->q1);
	QueueInit(&ms->q2);
	return ms;
}

void myStackPush(MyStack* obj, int x) {
	if (QueueEmpty(&obj->q1) == 0)
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

int myStackPop(MyStack* obj) {
	Queue* pEmpty = &obj->q1, * pNonEmpty = &obj->q2;
	if (QueueEmpty(&obj->q1) == 0)
	{
		pNonEmpty = &obj->q1;
		pEmpty = &obj->q2;
	}
	while (QueueSize(pNonEmpty) > 1)
	{
		QueuePush(pEmpty, QueueFront(pNonEmpty));
		QueuePop(pNonEmpty);
	}
	int front = QueueFront(pNonEmpty);
	QueuePop(pNonEmpty);
	return front;
}

int myStackTop(MyStack* obj) {
	Queue* pEmpty = &obj->q1, * pNonEmpty = &obj->q2;
	if (QueueEmpty(&obj->q1) == 0)
	{
		pEmpty = &obj->q2;
		pNonEmpty = &obj->q1;
	}

	return QueueBack(pNonEmpty);
}

bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	QueueDestory(&obj->q1);
	QueueDestory(&obj->q2);
	free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/