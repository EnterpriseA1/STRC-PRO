#include <stdio.h>
int main(void)
{
    int i, j, k;
    int row, column;
    char letter;

    scanf("%c %d %d", &letter, &column, &row);
    for (i = 1; i <= row; i++)
    {
        for (j = 1; j <= column; j++)
        {
            printf("%c", letter);
        }
        printf("\n");
    }
    return 0;
}