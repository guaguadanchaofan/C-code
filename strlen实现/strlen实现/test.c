#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int my_strlen(const char* arr)
{
	//getchar(arr);
	int count = 0;
	while (*arr++)
	{
		count++;
	}
	return count;
}
int main()
{
	char arr[10] = "dsajncjk";
	int ret = my_strlen(arr);
	printf("%d", ret);
	return 0;
}