#include <stdio.h>
int main()
{
    int a, b, c, d;
    int max;

    scanf("%d/%d/%d/%d", &a, &b, &c, &d);

    if (a % 2 != 0 && b % 2 != 0 && c % 2 != 0 && d % 2 != 0)
    {
        printf("no");
    }
    else
    {
        max = 0;
        max = (a > max &&a % 2 == 0 ? max = a : max);
        (b > max &&b % 2 == 0 ? max = b : max);
        (c > max &&c % 2 == 0 ? max = c : max);
        (d > max &&d % 2 == 0 ? max = d : max);
        printf("%d", max);
    }
    return 0;
}