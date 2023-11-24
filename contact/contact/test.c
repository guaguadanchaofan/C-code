#include"contact.h"


int main()
{
	int input = 0;
	Contact con;//创建结构体
	initcontact(&con);//初始化结构体
	Loadinfo(&con);//加载
	do
	{
		meau();
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			save(&con);
			DestroyContact(&con);
			break;
		case ADD:
			add(&con);
			break;
		case DEL:
			del(&con);
			break;
		case SEARCH:
			search(&con);
			break;
		case MODIFY:
			modify(&con);
			break;
		case SHOW:
			show(&con);
			break;
		case SORT:
			sort(&con);
			break;
		default:
			printf("选择错误，请重新选择\n");
		}
	} while (input);
	return 0;
}