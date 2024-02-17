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

    int count;
    int temp = arr[0];
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] > temp)
        {
            temp = arr[i];
            arr[i] = temp;
        }
    }
}