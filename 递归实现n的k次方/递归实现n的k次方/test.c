#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int power(int n,int k)
{
	if (k >= 1)
	{
		return n * power(n, k - 1);
	}
	else if (k == 0)
		return 1;
}
int main()
{
	int n = 0;
	int k = 0;
	scanf("%d%d", &n,&k);
	int ret = power(n, k);
	printf("%d", ret);
	return 0;
}