#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void Printbit(int num)
{
	int count = 0;
	for (int i = 0; i <= 31; i++)
	{
		if (num>>i & 1 == 1)
			count++;
	}
	printf("%d", count);
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	Printbit(num);
	return 0;
}