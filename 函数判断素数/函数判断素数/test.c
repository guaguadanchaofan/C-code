#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void prinum()
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 100; i <= 200; i++)
	{
		count = 0;
		for (j = 2; j <= i-1; j++)
		{
			if (i % j == 0)
			{
				count++;
			}
		}
		if (count==0)
		{
			printf("%d  ", i);
		}
	}
}
int main()
{
prinum();
	return 0;
}