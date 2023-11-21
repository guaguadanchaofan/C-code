#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
char* my_strcpy(char* arr1, const char* arr2)
{
	assert(arr1 != NULL);
	assert(arr2 != NULL);
	int* p = arr1;
	while (*arr2)
	{
		*arr1 = *arr2;
		arr2++;
		arr1++;
	}
	*arr1 = *arr2;
	return p;
}
int main()
{
	char arr1[20] = {0};
	char arr2[] = "hello";
	char * ret =my_strcpy(arr1, arr2);
	printf("%s\n", ret);
	return 0;
}