#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
int my_strcmp(const char* arr1, const char* arr2)
{
	int ret = 0;
	assert(arr1 !=NULL && arr2 != NULL);
	while (*arr1||*arr2)
	{
		if ((*arr1 - *arr2) > 0)
		{
			ret = 1;
			break;
		}
		else if ((*arr1 - *arr2) < 0)
		{
			ret = -1;
			break;
		}
		arr1++;
		arr2++;
	}
	return ret;
}
int main()
{
	char arr1[] = "ABCD";
	char arr2[] = "aBCD";
	int ret = my_strcmp(arr1, arr2);
	printf("%d", ret);
	return 0;
}