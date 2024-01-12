#include <stdio.h>
#include <math.h>
int main(void)
{
    float a, b;
    scanf("%f %f", &a, &b);

    float c = sqrt(a * a + b * b);
    printf("%.6f", c);
    return 0;
}