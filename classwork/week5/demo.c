#include <stdio.h>
int main(void)
{
    int i, j, n;
    int think[] = {3, 14, 34, 4, 85, 8, 17, 9};
    n = sizeof(think) / sizeof(think[0]);

    int max = think[0];
    for (i = 0; i < n; i++)
    {
        if (think[i] > max)
        {
            max = think[i];
        }
    }
    printf("%d", max);
    return 0;
}