#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int arr[n];

    int i;
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int cond = 0, check = 0;
    while (1)
    {
        scanf("%d", &cond);
        if (cond == -1)
        {
            break;
        }
        else
        {
            check = 0;
            for (size_t i = 0; i < n; i++)
            {
                if (arr[i] > cond)
                {
                    printf("%d ", i + 1);
                    check = 1;
                }
                else
                {
                    continue;
                }
            }
            if (check == 0)
            {
                printf("0");
            }
            printf("\n");
        }
    }
}