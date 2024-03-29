#include <stdio.h>
int main(void)
{
    int i, j, n;
    int think[21];
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &think[i]);
    }

    // part a
    printf("a) ");
    for (i = 0; i < 4; i++)
    {
        printf("%d ", think[i]);
        if (i == 3)
        {
            printf("\n");
        }
    }

    // part b
    printf("b) ");
    for (i = 0; i < n; i++)
    {
        if (think[i] > think[2])
        {
            printf("%d ", think[i]);
        }
    }
    printf("\n");

    // part c
    printf("c) ");
    for (i = 0; i < n; i++)
    {
        if (think[i] > think[2])
        {
            printf("%d ", i);
        }
    }
    printf("\n");

    // part d
    think[n] = think[2] + think[3];
    printf("d) ");
    for (i = 0; i < n + 1; i++)
    {
        printf("%d ", think[i]);
    }
    printf("\n");

    // part e
    think[3] = think[4] - think[2];
    printf("e) ");
    for (i = 0; i < n + 1; i++)
    {
        printf("%d ", think[i]);
    }
    printf("\n");

    // part f
    printf("f) ");
    if (think[1] > think[5])
    {
        printf("%d\n", 2);
    }
    else
    {
        printf("%d\n", 6);
    }

    // part g
    int temp;
    temp = think[1];
    think[1] = think[n];
    think[n] = temp;

    printf("g) ");
    for (i = 0; i < n + 1; i++)
    {
        printf("%d ", think[i]);
    }

    // part h
    int count = 0;
    printf("\nh) new=[");
    for (i = 0; i < n + 1; i++)
    {
        if (think[i] % 2 == 0)
        {
            count++;
        }
    }
    int new[count];
    for (i = 0, j = 0; i < n + 1; i++)
    {
        if (think[i] % 2 == 0)
        {
            new[j] = think[i];
            j++;
        }
    }
    for (i = 0; i < count; i++)
    {
        if (i == count - 1)
        {
            printf("%d", new[i]);
        }
        else
        {
            printf("%d ", new[i]);
        }
    }

    printf("]");

    return 0;
}