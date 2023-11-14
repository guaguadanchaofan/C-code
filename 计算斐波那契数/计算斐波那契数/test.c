#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int ASCII(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return ASCII(n-2) + ASCII(n - 1);
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = ASCII(n);
	printf("%d", ret);
	return 0;
}