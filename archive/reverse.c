#include <stdio.h>
int uwufufu(int);
int main(void)
{
    int n = 5;
    int sum = 0;
    while (1)
    {
        if (n < 0)
        {
            break;
        }
        sum += n;
        n--;
    }
    printf("%d\n", sum);
    printf("%d\n", uwufufu(5));
}
int uwufufu(int n)
{
    if (n == 0)
    {
        return n;
    }
    else
    {
        return n + uwufufu(n - 1);
    }
}