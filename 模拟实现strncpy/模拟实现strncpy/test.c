#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void my_strncpy(char* arr1, const char* arr2, int num)
{
	while (num)
	{
		*arr1 = *arr2;
		arr1++;
		arr2++;
		num--;
	}
}
int main()
{
	char arr1[10] = "abc";
	char arr2[20] = "acddef";
	my_strncpy(arr1, arr2, 3);
	printf(arr1);
	return 0;
}