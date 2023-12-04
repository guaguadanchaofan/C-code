#include"Stack.h"

void test()
{
	Stack s;
	SrackInit(&s);
	SrackPush(&s, 1);
	SrackPush(&s, 2);
	SrackPush(&s, 3);
	SrackPush(&s, 4);
	SrackPush(&s, 5);
	int size= SrackSize(&s);
	printf("%d \n", size);
	int num = SrackEmpty(&s);
	printf("%d \n", num);
	while (s._top != 0)
	{
		int ret = SrackTop(&s);
		printf("%d ", ret);
		SrackPop(&s);
	}
}
int main()
{
	test();
	return 0;
}