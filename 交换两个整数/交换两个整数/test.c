#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void swap(int x, int y)
{
	int temp = 0;
	temp = x;
	x = y;
	y = temp;
	printf("%d %d", x, y);
}
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);
	swap(a, b);
	return 0;
}
