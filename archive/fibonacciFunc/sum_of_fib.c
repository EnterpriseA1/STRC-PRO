#include <stdio.h>
int fib(int n);
int main(void)
{
    int i;
    int n;
    scanf("%d", &n);
    int temp = 0;

    for (i = 0; i <= n; i++)
    {
        temp += fib(i);
    }
    printf("%d", temp);
}
int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}
