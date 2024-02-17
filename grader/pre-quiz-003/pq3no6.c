#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int cond, check = 0;
    scanf("%d", &cond);

    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] == cond)
        {
            printf("(%d) ", arr[i]);
            check = 1;
        }
        else
        {
            printf("%d ", arr[i]);
        }
    }
}