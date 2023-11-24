#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int find_only_num(int arr[],int sz)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz; i++)
	{
		for (j = 0; j < sz; j++)
		{
			if(i!=j)
			 {
				if (arr[j] == arr[i])
				{

					break;
				}
			 }
			
		}
		if (j==sz)
		{
			printf("%d", arr[i]);
		}
	}
	return 0;
}
int main()
{
	int arr[] = { 1,1,2,2,3,3,4,4,5,5,6,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
		int ret = find_only_num(arr, sz);
		return 0;
}