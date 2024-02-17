#include <stdio.h>
int main(void)
{
    int n;
    int target;
    scanf("%d %d", &n, &target);

    int i;
    int arr[n];
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int temp;
    int j;
    int count = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                count++;
            }
        }
    }
    if (count)
    {
        printf("%d", count);
    }
    else
    {
        printf("-1");
    }
}