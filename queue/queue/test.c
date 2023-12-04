#include"queue.h"


void test()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueueDestory(&q);
	int numFront = QueueFront(&q);
	int numBack = QueueBack(&q);
	int size = QueueSize(&q);
	int ret = QueueEmpty(&q);
	
	printf("%d \n", numFront);
	printf("%d \n", numBack);
	printf("%d \n", size);
	printf("%d \n", ret);
	QNode* cur = q._front;
	while (cur)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
}
int main()
{
	test();
	return 0;
}