#include"contact.h"


int main()
{
	int input = 0;
	Contact con;//�����ṹ��
	initcontact(&con);//��ʼ���ṹ��
	Loadinfo(&con);//����
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
			printf("ѡ�����������ѡ��\n");
		}
	} while (input);
	return 0;
}