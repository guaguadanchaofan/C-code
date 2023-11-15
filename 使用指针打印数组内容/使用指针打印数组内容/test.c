#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int i = 0;
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int* p = arr;
	int sz = sizeof(arr) / sizeof(int);
	for (i = 0; i < sz; i++)
	{
		printf("%d\n", *p + i);
	}
	return 0;
}