#include"Stack.h"

void test()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	int size= StackSize(&s);
	printf("%d \n", size);
	int num = StackEmpty(&s);
	printf("%d \n", num);
	while (s._top != 0)
	{
		int ret = StackTop(&s);
		printf("%d ", ret);
		StackPop(&s);
	}
}
int main()
{
	test();
	return 0;
}