#include <stdio.h>
int checkscore(char std[], char keys[]);
int checkQ1(char std[][10], char keys[]);
int main()
{
    int i, j;
    char ans[8][10] = {
        {'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},  // 7
        {'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'},  // 6
        {'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'},  // 5
        {'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'},  // 4
        {'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},  // 8
        {'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},  // 7
        {'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},  // 7
        {'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}}; // 7
    char keys[10] = {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'};
    for (i = 0; i < 8; i++)
    {
        printf("std %d => %d\n", (i + 1), checkscore(ans[i], keys));
    }

    int temp = checkQ1(ans, keys);
    printf("Question 1 total : %d\n", temp);

    temp = mostDifficult(ans, keys);
    printf("Most Difficult : %d", temp);
}
int checkscore(char std[], char keys[])
{
    int i, j, count;
    count = 0;
    for (j = 0; j < 10; j++)
    {
        if (std[j] == keys[j])
        {
            count++;
        }
    }
    return count;
}

int checkQ1(char std[][10], char keys[])
{
    int i, j, count;
    count = 0;
    for (i = 0; i < 8; i++)
    {
        if (std[i][0] == keys[0])
        {
            count++;
        }
    }
    return count;
}

int mostDifficult(char std[][10], char keys[])
{
    int i, j;
    int temp[10] = {0};
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (std[i][j] == keys[j])
            {
                temp[j] += 1;
            }
        }
    }

    int TEMP, TEMP_;
    TEMP = temp[0];
    for (i = 0; i < 10; i++)
    {
        if (temp[i] < TEMP)
        {
            TEMP = temp[i];
            TEMP_ = i + 1;
        }
    }
    return TEMP_;
}