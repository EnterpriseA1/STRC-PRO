#include <stdio.h>
int calcFunc(int);
int main(void)
{
    int n, i;
    int sum = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        sum += calcFunc(i);
    }
    printf("%d\n", sum);
}
int calcFunc(int n)
{
    if (n <= 3)
    {
        return 1;
    }
    return calcFunc(n - 2) + calcFunc(n - 3);
}
