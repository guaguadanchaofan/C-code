#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main()
{
	int i = 0;
	for (i = 0; i <= 100000; i++)
	{
		int a = 0;
		int temp = i;
		int count = 1;
		int sum = 0;
		while ( temp/ 10)
		{
			count++;
			temp = temp / 10;
		}
		temp = i;
			while (temp)
			{
				sum = sum + pow(temp % 10, count);
				temp = temp / 10;
			}
			if (sum == i)
				printf("%d是水仙花数\n", i);
	}
	return 0;
}