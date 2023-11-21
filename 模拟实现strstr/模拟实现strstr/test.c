#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
char* my_strstr(char* arr1, char* arr2)
{
	char* p = 0;
	int count = 0;

	while (*arr1 && *arr2 != '\0')
	{
		if (*arr1 != *arr2)
		{
			arr1++;
			arr1=arr1-count;
			arr2=arr2-count;
			count = 0;
		}
		else
		{
	     	arr1++;
			arr2++;
			count++;
		}
	}
	p = arr1 - count;
	if (*arr2 == '\0')
		return p;
	else
		return 0;
}
int main()
{
	char arr1[] = "ABCCDE";
	char arr2[] = "CDE";
	char* ret=my_strstr(arr1, arr2);
	printf("%s\n", ret);
	return 0;
}