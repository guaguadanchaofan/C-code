#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
void Reverse(char* str)
{
    char tmp;
    char* left = str;
    char* right = str + strlen(str) - 1;
    while (left < right)
    {
        tmp = *left;
        *left = *right;
        *right = tmp;
        ++left;
        --right;
    }
}
int main()
{
	char str[100] = {0};
	; while (gets(str))
	{
		Reverse(str);
		printf("%s", str);
	}
	return 0;
}