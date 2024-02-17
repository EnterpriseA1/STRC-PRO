#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int showtime[n][2];

    int i, j;
    for (size_t i = 0; i < n; i++)
    {
        /*
        3 6
        4 9
        5 8
        */
        for (size_t j = 0; j < 2; j++)
        {
            scanf("%d", &showtime[i][j]);
        }
    }

    // set fullSchedule = 0
    int fullSchedule[n][10];
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            fullSchedule[i][j] = 0;
        }
    }

    /*
    set fullSchedule true value from showtime
    (show full schedule ex. (3,6) -> {3,4,5,6})
    */
    for (size_t i = 0; i < n; i++)
    {
        for (j = showtime[i][0]; j <= showtime[i][1]; j++)
        {
            int temp = j;
            fullSchedule[i][j - 1] = temp;
        }
    }

    // find max of fullSchedule
    int max = 0;
    int count = 0;
    for (size_t i = 0; i < 10; i++) // repeat 10 (horizontal)
    {
        count = 0;
        for (size_t j = 0; j < n; j++) // repeat 3 (vertical)
        {
            if (fullSchedule[j][i] > 0)
            {
                count++;
            }
        }
        if (count > max)
        {
            max = count;
        }
    }
    printf("%d", max);
}