#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void finnum(int* arr, int a, int sz)
{
	int left = 0;
	int right = sz - 1;
	int mid = 0;
	while (left<=right)
	{
		mid = (left + right) / 2;
		if (arr[mid] > a)
		{
			right = mid-1;
		}
		else if(arr[mid] < a)
		{
			left = mid+1;
		}
		else if (arr[mid] = a)
		{
			printf("%d", mid);
			break;
		}
	}
	if (left > right)
	{
		printf("’“≤ªµΩ\n");
	}
	return 0;
}
	int main()
	{
		int arr[] = { 1,2,3,4,5,6,7,8,9};
		int a = 0;
		int sz = sizeof(arr) / sizeof(int);
		scanf("%d", &a);
        finnum(arr, a, sz);
		return 0;
	}