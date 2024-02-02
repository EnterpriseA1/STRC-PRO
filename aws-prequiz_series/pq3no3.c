#include <stdio.h>
int main(void)
{
    int row, col;
    scanf("%d %d", &row, &col);
    int arr[row][col];

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int m;
    scanf("%d", &m);

    int cond[m];
    int i, j, k;
    for (size_t i = 0; i < m; i++)
    {
        scanf("%d", &cond[i]);
    }

    int count = 0, check = 0;
    while (count < m)
    {
        check = 0;
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                if (arr[i][j] > cond[count])
                {
                    printf("%d ", arr[i][j]);
                    check = 1;
                }
                else
                {
                    continue;
                }
            }
        }
        if (check == 0)
        {
            printf("0");
        }
        printf("\n");
        count++;
    }
}