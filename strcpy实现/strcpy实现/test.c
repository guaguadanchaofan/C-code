#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void my_strcpy(const char* arr,  char* arr1)
{
	while (*arr!='\0')
	{
		*arr1 = *arr;
		*arr1++;
		*arr++;
	}
}
int main()
{
	char arr[20] = "dnsajihduisahnc";
	char arr1[20] = { 0 };
	my_strcpy(arr, arr1);
	printf("%s\n", arr);
	printf("%s\n", arr1);

	return 0;
}