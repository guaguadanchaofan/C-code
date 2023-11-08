#include "game.h"
void meum()
{
	printf("-----------------------------\n");
	printf("----------1.play-------------\n");
	printf("----------0.exit-------------\n");
	printf("-----------------------------\n");
}
void game()
{
	char set = 0;
	char mine[ROWS][COLS] = {0};
	char show[ROWS][COLS] = {0};
	initborad(mine, ROWS, COLS,set='0');//初始化
	initborad(show, ROWS, COLS,set='*');//初始化
	dispalyborad(show, ROW, COL);//打印棋盘
	/*dispalyborad(mine, ROW, COL);*/
	setmine(mine, ROW, COL);//设置雷
	finemine(mine,show, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		printf("请选择游戏\n");
		meum();
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
				break;
		case 0:
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} 
	while (input);
	return 0;
}