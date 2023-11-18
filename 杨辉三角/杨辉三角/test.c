#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	int data[30] = { 1 };
	int i = 0;
	int j = 0;
	printf("1 \n");
	for (i = 1; i < n; i++)
	{
		for (j = i; j >0; j--)
		{
			data[j] = data[j] + data[j - 1];
		}
		for (j = 0; j < i; j++)
		{
			printf("%d ",data[j]);
		}
		printf("1 \n");
	}

	return 0;
}