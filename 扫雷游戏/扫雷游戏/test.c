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
	initborad(mine, ROWS, COLS,set='0');//��ʼ��
	initborad(show, ROWS, COLS,set='*');//��ʼ��
	dispalyborad(show, ROW, COL);//��ӡ����
	/*dispalyborad(mine, ROW, COL);*/
	setmine(mine, ROW, COL);//������
	finemine(mine,show, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		printf("��ѡ����Ϸ\n");
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
			printf("ѡ�����\n");
			break;
		}
	} 
	while (input);
	return 0;
}