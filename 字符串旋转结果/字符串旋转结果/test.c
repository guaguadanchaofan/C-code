#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

int find(const char* S1, char* S2)
{
	char tmp[200] = { 0 };
	strcpy(tmp, S1);
	strcat(tmp, S1);
	return strstr(tmp, S2) != NULL;
}
int main()
{
	char S1[] = "ABCDE";
	char S2[] = "bcdef";
	int ret= find(S1, S2);
	if (ret == 1)
		printf("yes");
	else
		printf("not");
	return 0;
}