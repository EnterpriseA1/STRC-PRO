#include <stdio.h>
int main(void)
{
    int row = 3, col;
    scanf("%d", &col);
    int arr[row][col];

    int i, j;

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            arr[i][j] = 0;
        }
    }

    for (size_t i = 0; i < row - 1; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (size_t i = 0; i < row - 1; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            arr[row - 1][j] += arr[i][j];
        }
    }

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}