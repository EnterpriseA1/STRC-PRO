#include <stdio.h>
int main(void)
{
    int g, i, n, t;
    t = 0;

    scanf("%d %d", &n, &g);
    for (t; t < g; t++)
    {
        i = 0;
        while (i < g)
        {
            printf("%d", n);
            i++;
        }
        printf("\n");
    }
    return 0;
}