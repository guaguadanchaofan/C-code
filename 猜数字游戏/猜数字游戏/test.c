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
		printf("������ֵĴ�С\n");
		scanf("%d", &num);
		if (num == ret)
		{
			printf("�¶��ˣ�\n");
			break;
		}
		else if (num < ret)
		{
			printf("��С��\n");
		}
		else
			printf("�´���\n");
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
			printf("�������������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}