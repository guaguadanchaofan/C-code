#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

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


//初始化
void QueueInit(Queue* q);

//队尾进队
void QueuePush(Queue* q, QDataType x);

//队头出队
void QueuePop(Queue* q);

//获取队头元素数据
QDataType QueueFront(Queue* q);

//获取队尾元素数据
QDataType QueueBack(Queue* q);

//获取队列中有效元素个数 
int  QueueSize(Queue* q);

//检测队列是否为空，如果为空返回非零结果，如果非空返回0
int  QueueEmpty(Queue* q);

//销毁队列
void QueueDestory(Queue* q);
