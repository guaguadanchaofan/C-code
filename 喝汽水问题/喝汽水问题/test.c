#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int n = 0;
	int i = 0;
	scanf("%d", &n);
	i = n;
	while (n > 1)
	{
		i += n/2;
		n = n / 2+n%2;
	}
	printf("%d", i);
	return 0;
}
