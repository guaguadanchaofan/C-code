#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	char arr[6] = "ABCDE";
	int n = 0;
	scanf("%d", &n);
		while (n)
		{
			int i = 0;
			char temp = arr[0];
			for (i = 0; i < 5; i++)
			{
				arr[i] = arr[i + 1];
			}
			arr[4] = temp;
			n--;
		}
		printf("%s", arr);
	return 0;
}