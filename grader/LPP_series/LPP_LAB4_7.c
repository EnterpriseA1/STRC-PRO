#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int arr[n + 1][n + 1];

    int i, j;
    for (i = 0; i < n + 1; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            arr[i][j] = 0;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            arr[n][j] += arr[i][j];
            arr[i][n] += arr[i][j];
        }
    }

    int state = 1;
    for (j = 0; j < n; j++)
    {
        if (arr[n][j] != arr[j][n])
        {
            state = 0;
            break;
        }
    }
    if (state)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
}