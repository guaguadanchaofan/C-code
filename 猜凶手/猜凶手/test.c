#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int kill = 0;
	for (kill = 'a'; kill <= 'd'; kill++)
	{
		if ((kill != 'a') + (kill == 'c') + (kill == 'd') + (kill != 'd') == 3)
			printf("Ð×ÊÖÊÇ%c", kill);
	}
	return 0;
}