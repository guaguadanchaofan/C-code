#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void is_leap(int a)
{
	if (a % 4 == 0 && a % 100 != 0)
	{
		printf("%d������\n", a);
	}
	else if (a % 400 == 0)
	{
		printf("%d������\n", a);
	}
	else
		printf("%d��������\n",a);
}
int main()
{
	int a = 0;
	scanf("%d", &a);
	is_leap(a);
	return 0;
}