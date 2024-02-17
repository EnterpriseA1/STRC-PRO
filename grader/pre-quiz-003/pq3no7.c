#include <stdio.h>
int main(void)
{
    int row, col;
    scanf("%d %d", &row, &col);
    int arr[row][col];

    int i, j, k;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int m, count = 0, check = 0;
    scanf("%d", &m);
    int cond[m];

    for (i = 0; i < m; i++)
    {
        scanf("%d", &cond[i]);
    }

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            for (k = 0; k < m; k++)
            {
                if (arr[i][j] == cond[k])
                {
                    printf("(%d) ", arr[i][j]);
                    check = 1;
                    continue;
                }
            }
            if (check != 1)
            {
                printf("%d ", arr[i][j]);
            }
            check = 0;
        }
        printf("\n");
    }
}