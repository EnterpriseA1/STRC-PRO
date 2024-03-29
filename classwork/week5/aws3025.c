#include <stdio.h>
int main(void)
{
    int row, column;
    scanf("%d %d", &row, &column);
    int A[row][column];

    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    int temp = 0;
    for (i = 0; i < row; i++)
    {
        temp = 0;
        for (j = 0; j < column; j++)
        {
            temp = A[i][j] + 1;
            printf("%d ", temp);
        }
        printf("\n");
    }
}