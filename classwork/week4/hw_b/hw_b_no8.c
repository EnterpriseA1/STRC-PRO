#include <stdio.h>
int main()
{
    int max_size = 1000;
    int score[max_size];
    int count = 0, num, i;

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

    for (i = 0; i < max_size; i++)
    {
        if (score[i] > 67)
        {
            if (score[i] >= 85)
            {
                printf("%d(A)\n", score[i]);
            }
            else if (score[i] >= 75)
            {
                printf("%d(B)\n", score[i]);
            }
            else
            {
                printf("%d(C)\n", score[i]);
            }
        }
        else if (score[i] >= 55)
        {
            printf("%d(D)\n", score[i]);
        }
        else
        {
            printf("%d(F)\n", score[i]);
        }
    }

    return 0;
}