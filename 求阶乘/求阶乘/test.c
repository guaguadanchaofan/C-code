#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int factorial(int n)
{
	if (n == 1)
		return n;
	else
		return n * factorial(n - 1);
}
void factorial_2(int n)
{
	int i = 0;
	int sum = 1;
	for (i = n; i > 0; i--)
	{
		sum = sum * i;
	}
	printf("%d\n", sum);
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = factorial(n);
	factorial_2(n);
	printf("%d", ret);
	return 0;
}