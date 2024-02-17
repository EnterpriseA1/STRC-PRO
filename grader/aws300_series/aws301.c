#include <stdio.h>

int main()
{
    int row, col;
    scanf("%d %d", &row, &col);
    int arr[row + 1][col + 1];
    int i, j;
    for (i = 0; i < row; i++)
    {
        int sum = 0;
        for (j = 0; j < col; j++)
        {
            int val;
            scanf("%d", &val);
            arr[i][j] = val;
            sum += val;
        }
        arr[i][col] = sum;
    }
    int a = 0;
    while (a < col)
    {
        int d;

        for (d = 0; d < row; d++)
        {
        }
    }

    for (i = 0; i <= row; i++)
    {
        for (j = 0; j <= col; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}