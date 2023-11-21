#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>
void my_memmove(void* arr1, void* arr2, unsigned int sz)
{
	assert(arr1 && arr2);
	if (*(char*)arr1 < *(char*)arr2)//从前往后拷贝
	{
		while (sz--)
		{
		*((char*)arr1) = *((char*)arr2);
		*((char*)arr1)++;
		*((char*)arr2)++;
	    }
    }
		else//从后往前拷贝
		{
			while (sz--)
			{
				*((char*)arr1 + sz) = *((char*)arr2 + sz);
			}
		}

}
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9 };
	my_memmove(arr1, arr1+1, 12);
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d", arr1[i]);
	}
	return 0;
}