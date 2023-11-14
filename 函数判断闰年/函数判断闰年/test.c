#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void is_leap(int a)
{
	if (a % 4 == 0 && a % 100 != 0)
	{
		printf("%d是闰年\n", a);
	}
	else if (a % 400 == 0)
	{
		printf("%d是闰年\n", a);
	}
	else
		printf("%d不是闰年\n",a);
}
int main()
{
	int a = 0;
	scanf("%d", &a);
	is_leap(a);
	return 0;
}