#include "game.h"


//菜单
void menu()
{
	printf("-----------------------------------\n");
	printf("------------  1.play  -------------\n");
	printf("------------  0.exit  -------------\n");
	printf("-----------------------------------\n");
}


//初始化棋盘
void initboard(char board[ROW][COL], int row, int col)
{
	int j = 0;
	int i = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
    }
}


//打印棋盘
void displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (j = 0; j < row; j++)
	{
		for (i = 0; i < col; i++)
		{
			printf(" %c ", board[j][i]);
			if (i <col-1)
			{
				printf("|", board[j][i]);
			}
		}
		if (j < row - 1)
		{
			printf("\n-----------\n");
		}
	}
}


//下棋
void moveboard(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("\n输入坐标>>");
	while(1)
	{
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <=col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标已经有了请重新输入\n");
			}
		}
		else
		{
			printf("坐标错误请重新输入\n");
		}
	}
}


//电脑下棋
void computermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("\n电脑下棋>>\n");
	while(1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}

	}
}


//判断平局
int isfull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}


//判断输赢
char iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)//判断横向
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]&&board[i][1]!=' ')
		{
			return board[i][1];
		}
	}
	for (i = 0; i < col; i++)//判断竖向
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	if (board[0][0]== board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')//判断交叉
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (1 == isfull(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}