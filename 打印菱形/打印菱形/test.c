#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	int j = 0;
	for (i = n-1; i > 1; i--)//ио╟К╤н
	{
		int t = i;
		while (t - 1)
		{
			printf(" ");
			t--;
		}
		for (j = i; j <= n + 1 - i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 1; i <= n; i++)//об╟К╤н
	{
		int t = i;
		while (t-1)
		{
			printf(" ");
			t--;
		}
		for (j = i; j <= n+1 - i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}