#include <stdio.h>
int main(void)
{
    int num_a, num_b;
    scanf("%d %d", &num_a, &num_b);

    // find GCD
    int i;
    int gcd = 1;
    for (i = 1; i <= num_a && i <= num_b; i++)
    {
        if (num_a % i == 0 && num_b % i == 0)
        {
            gcd = i;
        }
    }
    printf("%d", gcd);
}