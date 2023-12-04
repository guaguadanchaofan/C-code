#include"queue.h"


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
