#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#include<limits.h>
enum status
{
	VALID,
	INVALID
}sta=INVALID;
int my_atoi(const char* arr)
{
	int flag = 1;
    long long count = 0;
	//空指针
	assert(arr);
	//判断空格
	while (isspace(*arr))
	{
		arr++;
	}
	//空字符串
	if (*arr =='\0')
	{
		return 0;
	}
	//判断正负号
	if (*arr == '-')
	{
		flag = -1;
		arr++;
	}
	else if (*arr == '+')
	{
		arr++;
	}
	while (*arr)
	{
		if (isdigit(*arr))
		{
			count = count * 10 + flag*(*arr - '0');
			if (count > INT_MAX || count < INT_MIN)
			{
				return 0;
			}
		}
		else
		{
			return (int)count;
		}
		arr++;
	}
	if (*arr == '\0')
	{
		sta = VALID;
		return (int)count;
	}
	else
	{
		//遇到非数字字符
        return (int)count;
	}

	//判断越界
	//非数字字符
}
int main()
{
	char arr[] = "-123214";
	int ret = my_atoi(arr);
	//int ret = atoi(arr);
	if (sta == VALID)
	{
		printf("合法转换：%d", ret);

	}
	else if (sta == INVALID)
	{
		printf("非法转换：%d", ret);
	}

	return 0;
}