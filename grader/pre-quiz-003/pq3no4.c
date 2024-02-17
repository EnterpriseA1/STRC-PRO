#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int a[n];
    int b[n];

    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }

    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", a[i] + b[i]);
    }
}