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

    int max = arr[0];
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("%d", max);
}