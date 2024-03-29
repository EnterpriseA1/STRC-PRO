#include <stdio.h>

int checkNumber(int n1, int n2);
int multiply(int n1, int n2);

void main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    checkNumber(a, b);
}

int checkNumber(int n1, int n2)
{
    int checknum1 = (n1 > 20 && n1 < 60) ? 1 : 0;
    int checknum2 = (n2 > 20 && n2 < 60) ? 1 : 0;
    if (checknum1 && checknum2 == 1)
    {
        printf("%d", multiply(n1, n2));
    }
    else
    {
        return 0;
    }
}

int multiply(int n1, int n2)
{
    int result = n1 * n2;
    return result;
}