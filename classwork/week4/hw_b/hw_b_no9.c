#include <stdio.h>
int main()
{
    int max_size = 1000;
    int score[max_size];
    int count = 0, num, i;
    int a = 0, b = 0, c = 0, d = 0, f = 0;

    while (1)
    {
        scanf("%d", &num);
        if (num == -1)
        {
            max_size = count;
            break;
        }
        score[count] = num;
        count++;
    }

    for (i = 0; i < count; i++)
    {
        if (score[i] > 67)
        {
            if (score[i] >= 85)
            {
                printf("%d(A)\n", score[i]);
                a++;
            }
            else if (score[i] >= 75)
            {
                printf("%d(B)\n", score[i]);
                b++;
            }
            else
            {
                printf("%d(C)\n", score[i]);
                c++;
            }
        }
        else if (score[i] >= 55)
        {
            printf("%d(D)\n", score[i]);
            d++;
        }
        else
        {
            printf("%d(F)\n", score[i]);
            f++;
        }
    }
    printf("A(%d)\n", a);
    printf("B(%d)\n", b);
    printf("C(%d)\n", c);
    printf("D(%d)\n", d);
    printf("F(%d)\n", f);
    return 0;
}