#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int high = 8;
    int i = 1;
    int a = 0;
    int b = 0;
    int max = 0;
    int count = 0;
    while (i <= 7)
    {
        scanf("%d %d", &a, &b);
        if ((a + b) > high)
        {
            if ((a + b) > max)
            {
                max = a + b;
                count = i;
            }
        }
        i++;
    }
    printf("%d", count);
    return 0;
}
int main()
{
	int n = 1200;
	int a = 0;
	a = n *1.2;
	return 0;
}

int main()
{
    int i = 1;
    int money = 0;
    int expense = 0;
    int saving = 0;
    while (i <= 12)
    {
        money += 300;
        scanf("%d", &expense);
        money -= expense;
        if (money >= 100)
        {
            saving += (money / 100) * 100;
            money = money - (money / 100) * 100;
        }
        if (money < 0)
        {
            printf("%d", -i);
            break;
        }
        i++;
    }
    if(i==13)
    printf("%.0f", (saving * 1.2)+money);
    return 0;
}
int main()
{
    int n = 0;
    int k = 0;
    scanf("%d %d", &n, &k);
    int sum = 0;
    sum = n;
    while (n >= k)
    {
        sum += n / k;
        n = n % k + n / k;
    }
    printf("%d", sum);
    return 0;
}