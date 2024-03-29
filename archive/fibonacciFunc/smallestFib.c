#include <stdio.h>
int simpleFib(int);
int main()
{
    int n, i;
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i <= n; i++)
    {
        arr[i] = simpleFib(i);
    }
    for (i = 0; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int number;
    scanf("The smallest Fibonacci number greater %d", &number);
    for (i = 0; i <= n; i++)
    {
        if (arr[i] >= number)
        {
            printf("%d\n", arr[i]);
            break;
        }
    }
}
int simpleFib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return simpleFib(n - 1) + simpleFib(n - 2);
    }
}
