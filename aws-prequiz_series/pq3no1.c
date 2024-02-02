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

    int cond;
    int check = 0;
    scanf("%d", &cond);
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] > cond)
        {
            printf("%d ", i + 1);
        }
        else
        {
            check = 1;
            if (check != 0)
            {
                continue;
            }
        }
    }
}