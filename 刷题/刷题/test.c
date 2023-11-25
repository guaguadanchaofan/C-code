#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int k = 0;
    scanf("%d", &k);
    double n = 1;
    double Sn = 0;
  while(n)
    {
        Sn += 1 / n;
        if (Sn > k)
        {
            printf("%d",(int) n);
            break;
        }
        n++;
    }
    return 0;
}
int main()
{
    int arr[10] = { 0 };
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    int high = 0;
    scanf("%d", &high);
    high += 30;
    int count = 0;
    for (i = 0; i < 10; i++)
    {
        if (high >= arr[i])
        {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}
int main()
{
    int l = 0;
    int m = 0;
    scanf("%d %d", &l, &m);
    int i = 0;
    int arr[100000] = { 0 };
    for (i = 0; i <= l; i++)
    {
        arr[i] = i;
    }
    int a = 0;
    int b = 0;
    while (m--)
    {
        scanf("%d %d", &a, &b);
        for (i = a; i <= b; i++)
        {
            arr[i] = -1;
        }
    }
    int count = 0;
    for (i = 0; i <= l; i++)
    {
        if (arr[i] >= 0)
        {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}
#include<stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    int j = 0;
    int a = 0;
    for (i = 1; i <= n; i += 2)
    {
        for (j = 1; j <= n; j += 2)
        {
            if (n == i * j)
            {
                int count1 = 0;
                for (a = 1; a < i; a += 2)
                {
                    if (i % a == 0)
                    {
                        count1++;
                    }
                    if (count1 >= 2)
                    {
                        break;
                    }
                }
                int count2 = 0;
                for (a = 1; a < j; a += 2)
                {
                    if (j % a == 0)
                    {
                        count2++;
                    }
                    if (count2 >= 2)
                    {
                        break;
                    }
                }
                if (count1 < 2 && count2 < 2)
                {
                    printf("%d", i > j ? i : j);
                    return 0;
                }
            }
        }
    }
    return 0;
}
#include<stdio.h>
int main()
{
    int n = 0;
    int i = 0;
    scanf("%d", &n);
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            printf("%d", (n / i));
            break;
        }
    }
    return 0;
}