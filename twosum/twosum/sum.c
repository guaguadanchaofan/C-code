#include<stdio.h>
int qiuhe(int arr[], int k, int sz)
{
	int i = 0;
	int j = 0;
	int sum = i + j;
	for (i = 0; i <= sz; i++)
	{
		for (j = i; j <= sz; j++)
		{
			if (arr[i] + arr[j] == k)
				printf("%d %d", i, j);
		}
	}

	return 0;
}
int main()
{
	int arr[] = { 2,5,7,9 };
	int taeget = 12;
	int size = sizeof(arr) / sizeof(arr[0]);
	int sizesum = qiuhe(arr, taeget, size);
	return 0;
}
