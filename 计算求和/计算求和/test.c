#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int n = 0;
	int i = 0;
	int k = 0;
	int sum = 0;
	int count = 0;
	scanf("%d%d", &n, &i);
	for (k = 0; k< i; k++)
	{
		sum = sum*10 + n;
		count += sum;
	}
	printf("%d", count);
	return 0;
}