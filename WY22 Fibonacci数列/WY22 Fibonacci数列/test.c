#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int a = 0;
    int b = 1;
    int c = a + b;
    while (1)
    {
        if (n == b)
        {
            printf("0\n");
            break;
        }
        else if (n < b)
        {
            int count1 = b - n;
            int count2 = n - a;
            if (count1 > count2)
            {
                printf("%d", count2);
                break;
            }
            else {
                printf("%d", count1);
                break;
            }
        }
        c = a + b;
        a = b;
        b = c;
    }
    return 0;
}