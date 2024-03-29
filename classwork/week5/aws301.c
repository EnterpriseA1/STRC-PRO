#include <stdio.h>
int main(void)
{
    int i, n;
    int a;
    int x[100];
    scanf("%d", &n);

    while ((i < n) ? scanf("%d", &a), x[i] = a, ++i : 0)
    {
    }

    while ((i >= 0) ? printf("%d ", x[i - 1]) : 0, --i)
    {
    }

    return 0;
}

/* old method*/
// for (i = 0; i < n; i++)
// {
//     scanf("%d", &x[i]);
// }

// for (i = n - 1; i >= 0; i--)
// {
//     printf("%d ", x[i]);
// }