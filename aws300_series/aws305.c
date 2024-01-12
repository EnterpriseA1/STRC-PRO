#include <stdio.h>
int main(void)
{
    int i, j;
    int row, col;
    scanf("%d %d", &row, &col);
    int arr[row + 1][col + 1];

    // clear matrix value
    for (i = 0; i <= row; i++)
    {
        for (j = 0; j <= col; j++)
        {
            arr[i][j] = 0;
        }
    }

    // input matrix & sum
    int temp = 0,
        total = 0;
    for (i = 0; i < row; i++)
    {
        temp = 0;
        for (j = 0; j < col; j++)
        {
            scanf("%d", &arr[i][j]);
            temp += arr[i][j];
            arr[i][col] = temp;
            arr[row][j] += arr[i][j];
        }
        total += arr[i][col];
        arr[row][col] = total;
    }

    // print matrix
    for (i = 0; i <= row; i++)
    {
        for (j = 0; j <= col; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}