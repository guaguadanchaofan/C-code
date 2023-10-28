#include "game.h"
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	initboard(board, ROW, COL);//初始化棋盘
	displayboard(board, ROW, COL);//打印棋盘
	while (1)
	{
		moveboard(board, ROW, COL);//下棋
		displayboard(board, ROW, COL);//打印棋盘
        ret =iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		computermove(board, ROW, COL);//电脑下棋
		displayboard(board, ROW, COL);//打印棋盘
		ret =iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("\n你赢了\n");
	}
	 else if (ret == '#')
	{
		printf("\n电脑赢了\n");
	}
	 else if(ret == 'Q')
	{
		printf("\n平局\n");
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
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误重新选择\n");
			break;
		}
	} while (input);
	return 0;
}