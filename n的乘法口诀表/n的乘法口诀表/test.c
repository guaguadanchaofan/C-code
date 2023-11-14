#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void Table(int n)
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%2d*%d=%2d  ", i, j, i * j);
		}
		printf("\n");
	}
}
int main()
{
	int n = 0;
	scanf("%d",&n);
	Table(n);
	return 0;
}