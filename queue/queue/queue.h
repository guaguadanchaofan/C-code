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


//��ʼ��
void QueueInit(Queue* q);

//��β����
void QueuePush(Queue* q, QDataType x);

//��ͷ����
void QueuePop(Queue* q);

//��ȡ��ͷԪ������
QDataType QueueFront(Queue* q);

//��ȡ��βԪ������
QDataType QueueBack(Queue* q);

//��ȡ��������ЧԪ�ظ��� 
int  QueueSize(Queue* q);

//�������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
int  QueueEmpty(Queue* q);

//���ٶ���
void QueueDestory(Queue* q);
