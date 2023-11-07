#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void Poscount(int x)//ÕýÐò
{
	if (x < 10)
	{
		printf("%d\n", x);
		return x;
	}
	else
		printf("%d ", x % 10);
		return Poscount(x/10);
}
void Revcount(int x)//ÄæÐò
{
	if (x >9)
	{
		Revcount(x / 10);
	}
		printf("%d ", x % 10);
}
int main()
{
	int a = 0;
	scanf("%d", &a);
	Poscount(a);
	Revcount(a);
	return 0;
}