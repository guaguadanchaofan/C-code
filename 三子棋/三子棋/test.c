#include "game.h"
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	initboard(board, ROW, COL);//��ʼ������
	displayboard(board, ROW, COL);//��ӡ����
	while (1)
	{
		moveboard(board, ROW, COL);//����
		displayboard(board, ROW, COL);//��ӡ����
        ret =iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		computermove(board, ROW, COL);//��������
		displayboard(board, ROW, COL);//��ӡ����
		ret =iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("\n��Ӯ��\n");
	}
	 else if (ret == '#')
	{
		printf("\n����Ӯ��\n");
	}
	 else if(ret == 'Q')
	{
		printf("\nƽ��\n");
	}
}
int main()
{
	int input = 0;
	do
	{
		menu();
		srand((unsigned int)time(NULL));
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}