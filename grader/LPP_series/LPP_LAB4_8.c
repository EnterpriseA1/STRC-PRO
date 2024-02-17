#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);

    int i;
    int temp = n;
    int count = 0;
    while (temp > 0)
    {
        if (temp % 2 == 1)
        {
            count++;
        }
        temp /= 2;
    }
    printf("%d", count);
}