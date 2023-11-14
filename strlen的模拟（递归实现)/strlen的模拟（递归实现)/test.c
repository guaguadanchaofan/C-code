#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int is_mystrlen(char* a)
{
	int count = 0;
	while (*a!='\0')
	{
		count++;
		a++;
	}
	return count;
}
int is_mystrlen2(char *b)
{
	if (*b == '\0')
		return 0;
	else
		return 1 + is_mystrlen(b + 1);
}
int main()
{
	char a[] = "dsnajcsbvibiuhasdiua";
	int ret = is_mystrlen(a);
	int ret2 = is_mystrlen2(a);
	printf("%d\n", ret);
	printf("%d\n", ret2);
	return 0;
}