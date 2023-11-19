#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int find(const char* S1, char* S2)
{
	char tmp[20] = { 0 };
	strcpy(tmp, S1);
	strcat(tmp, S2);
	return strstr(tmp, find) != NULL;
}
int main()
{
	char S1[5] = "ABCDE";
	char S2[5] = "abcde";
	int ret= find(S1, S2);
	if (ret == 1)
		printf("yes");
	else
		printf("not");
	return 0;
}