#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void maopao(int *arr,int sz)
{
	int i = 0;
	int j = 0;
	for (j = sz; j >=0; j--)
	{
		for (i = 0; i < sz-1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}
}
int main()
{
	int arr[5] = {6,5,4,3,2};
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	maopao(arr, sz);
	for (i = 0; i <= sz-1;i++)
	{
		printf("%d", arr[i]);
	}
	return 0;
}