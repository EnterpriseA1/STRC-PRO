#include <stdio.h>
int main(void)
{
    int g, i, n;
    i = 0;

    scanf("%d %d", &n, &g);
    while (i < g)
    {
        printf("%d", n);
        i++;
    }

    return 0;
}