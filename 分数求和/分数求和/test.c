#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int i = 1;
	int j = 0;
	double sum = 0.0;
	for (j = 1; j <= 99; j++)
	{
		sum += i*1.0/ j;
		i = -i;
	}
	printf("%2f", sum);
	return 0;
}