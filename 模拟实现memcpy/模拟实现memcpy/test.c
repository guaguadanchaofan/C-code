#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
void my_memcpy( void* arr2,const void* arr1, int count)
{
	assert(arr1);
	while (count--)
	{
		*(char*)arr2 = *(char*)arr1;
		arr2 = (char*)arr2 + 1;
	    arr1 = (char*)arr1 + 1;
	}
}
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7 };
	int arr2[10] = { 0 };
	my_memcpy(arr2, arr1, 12);
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("%d ", arr2[i]);
	}
	return 0;
}