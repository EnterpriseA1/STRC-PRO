#include <stdio.h>
int main()
{
    int i, count;
    scanf("%d", &count);
    int score[count];

    for (i = 0; i < count; i++)
    {
        scanf("%d", &score[i]);
    }
    for (i = 0; i < count; i++)
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