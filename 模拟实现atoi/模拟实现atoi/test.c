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
	//��ָ��
	assert(arr);
	//�жϿո�
	while (isspace(*arr))
	{
		arr++;
	}
	//���ַ���
	if (*arr =='\0')
	{
		return 0;
	}
	//�ж�������
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
		//�����������ַ�
        return (int)count;
	}

	//�ж�Խ��
	//�������ַ�
}
int main()
{
	char arr[] = "-123214";
	int ret = my_atoi(arr);
	//int ret = atoi(arr);
	if (sta == VALID)
	{
		printf("�Ϸ�ת����%d", ret);

	}
	else if (sta == INVALID)
	{
		printf("�Ƿ�ת����%d", ret);
	}

	return 0;
}