#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#include<time.h>


void menu()
{
	printf("------------------\n");
	printf("------1.play------\n");
	printf("------0.exit------\n");
	printf("------------------\n");
}


void game()
{
	int ret = rand() % 100 + 1;
	int num = 0;
	while (1)
	{
		printf("请猜数字的大小\n");
		scanf("%d", &num);
		if (num == ret)
		{
			printf("猜对了！\n");
			break;
		}
		else if (num < ret)
		{
			printf("猜小了\n");
		}
		else
			printf("猜大了\n");
	}
}


int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("输入错误请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}