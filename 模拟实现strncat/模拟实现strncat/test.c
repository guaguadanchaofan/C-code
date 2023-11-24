#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
void my_strncat(char* arr1, const char* arr2, int num)
{
	assert(arr1 && arr2);
	while (*arr1)
	{
		arr1++;
	}
	while (num)
	{
		*arr1 = *arr2;
		arr1++;
		arr2++;
		num--;
	}
	*arr1 = '\0';
}
int main()
{
	char arr1[20] = "nihao";
	char arr2[20] = "hehe";
	my_strncat(arr1, arr2, 1);
	printf(arr1);
	return 0;
}