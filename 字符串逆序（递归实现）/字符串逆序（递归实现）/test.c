#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void reverse_string(char* string)
{
	int len = strlen(string);
	char temp = 0;
	temp = *string;
	*string = *(string + len - 1);
	*(string + len - 1) = '\0';
	if (strlen(string + 1) > 2)
		reverse_string(string + 1);
	*(string + len - 1) = temp;
}
int main()
{
	char arr[] = "abcdef";
	reverse_string(arr);
	return 0;
}