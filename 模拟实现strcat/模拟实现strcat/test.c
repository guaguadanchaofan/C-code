#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
char* my_strcat(char* arr1, char* arr2)
{
	assert(arr1 != NULL);
	assert(arr2 != NULL);

	int* p = arr1;
	while (*arr1 != '\0')
	{
		arr1++;
	}
	while (*arr2 != '\0')
	{
		*arr1 = *arr2;
			arr1++;
			arr2++;
	}
	*arr1 = *arr2;
	return p;
}
int main()
{
	char arr1[40] = "ABCD";
	char arr2[] = "nihao";
	char* ret = my_strcat(arr1, arr2);
	printf("%s", ret);
	return 0;
}