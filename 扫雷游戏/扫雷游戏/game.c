#include"game.h"


void initborad(char borad[ROWS][COLS],int row, int col,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			borad[i][j] =set;
		}
	}
}



void dispalyborad(char borad[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("--------game-------\n");
	for (j = 0; j <= col; j++)
	{
		printf("%d ",j);
	}
	printf("\n");

	for (i = 1; i <=row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <=col; j++)
		{
			printf("%c ", borad[i][j]);
		}
		printf("\n");
	}
}




void setmine(char borad[ROWS][COLS], int row, int col)
{
	int count = minecount;
	int x = 0;
	int y = 0;
	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (borad[x][y] == '0')
		{
			borad[x][y] = '1';
			count--;
		}
	}
}


int get_mine_count(char borad[ROWS][COLS], int x, int y)
{
	return (borad[x - 1][y - 1] +
		borad[x - 1][y] +
		borad[x - 1][y + 1] +
		borad[x][y - 1] +
		borad[x][y + 1] +
		borad[x + 1][y - 1] +
		borad[x + 1][y] +
		borad[x + 1][y + 1] - 8 * '0');
}


void finemine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col-minecount)
	{
		printf("��������������>>\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= row)
		{
			if (show[x][y] != '*')
			{
				printf("�����Ѿ��Ź�������������\n");
			}
			else
			{
				if (mine[x][y] == '1')
				{
					printf("���ź��㱻ը����\n");
					dispalyborad(mine, ROW, COL);
					break;
				}
				else
				{
					int count = get_mine_count(mine, x, y);
					show[x][y] = count + '0';
					win++;
					dispalyborad(show, ROW, COL);
				}
			}
		}
		else
		{
			printf("�����������������\n");
		}
	}
	if (win == row * col - minecount)
	{
		printf("��ϲ��Ӯ��");
		dispalyborad(mine, ROW, COL);
	}
}


