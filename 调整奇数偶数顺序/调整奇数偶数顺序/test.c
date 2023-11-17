#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int arr[] = {1,2,3,5,6,7,8,9};
	int sz = sizeof(arr) / sizeof(arr[0]);
	int temp = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < sz; i++)
	{
		for (j = 0; j < sz - i; j++)
		{
			if (j < sz -i- 1)
			{
				if (arr[j] % 2 == 0)
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
	for (i = 0; i < sz; i++)
	{
		printf("%d",arr[i]);
	}
	return 0;
}