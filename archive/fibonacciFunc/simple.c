#include <stdio.h>
int simpleFib(int);
int main(void)
{
    int n = 8, i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", simpleFib(i));
    }
}
int simpleFib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return simpleFib(n - 1) + simpleFib(n - 2);
}