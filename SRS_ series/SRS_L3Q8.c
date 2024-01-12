#include <stdio.h>
int main(void)
{
    int x, y, output;
    scanf("%d %d", &x, &y);

    int temp = 0;
    int count = 0;
    // count time
    while (temp < y)
    {
        temp += x;
        count++;
    }

    printf("%d", count);
    return 0;
}