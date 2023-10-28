#include "game.h"


//�˵�
void menu()
{
	printf("-----------------------------------\n");
	printf("------------  1.play  -------------\n");
	printf("------------  0.exit  -------------\n");
	printf("-----------------------------------\n");
}


//��ʼ������
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


//��ӡ����
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


//����
void moveboard(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("\n��������>>");
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
				printf("�����Ѿ���������������\n");
			}
		}
		else
		{
			printf("�����������������\n");
		}
	}
}


//��������
void computermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("\n��������>>\n");
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


//�ж�ƽ��
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


//�ж���Ӯ
char iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)//�жϺ���
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]&&board[i][1]!=' ')
		{
			return board[i][1];
		}
	}
	for (i = 0; i < col; i++)//�ж�����
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	if (board[0][0]== board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')//�жϽ���
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