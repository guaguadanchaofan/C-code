#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
int my_strlen(char* arr1)
{
	assert(arr1 != NULL);
	int count = 0;
	while (*arr1)
	{
		arr1++;
		count++;
	}
	return count;
}
int main()
{
	char arr1[] = "sdnsajkdhsakjc";
	int ret = my_strlen(arr1);
	printf("%d", ret);
	return 0;
}