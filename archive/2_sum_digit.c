#include <stdio.h>
int sumDigit(int);
int main(void)
{
    int number;
    scanf("%d", &number);
    printf("%d", sumDigit(number));
}
int sumDigit(int n)
{
    if (n < 1)
    {
        return 0;
    }
    else
    {
        return n % 10 + sumDigit(n / 10);
    }
}