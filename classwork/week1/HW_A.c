#include <stdio.h>

int main()
{
    int a, b, c, d, e;
    int max, temp, second_max;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    max = a;
    temp = ((b > max) ? (max = b) : max);
    temp = ((c > max) ? (max = c) : max);
    temp = ((d > max) ? (max = d) : max);
    temp = ((e > max) ? (max = e) : max);

    second_max = 0;
    temp = (a > second_max) ? ((a < max) ? second_max = a : second_max) : second_max;
    temp = (b > second_max) ? ((b < max) ? second_max = b : second_max) : second_max;
    temp = (c > second_max) ? ((c < max) ? second_max = c : second_max) : second_max;
    temp = (d > second_max) ? ((d < max) ? second_max = d : second_max) : second_max;
    temp = (e > second_max) ? ((e < max) ? second_max = e : second_max) : second_max;

    printf("Max %d\nSecond Max %d", max, second_max);
    return 0;
}