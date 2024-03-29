#include <stdio.h>
long convert(long h, long m, long s);
void main()
{
    int h, m, s;
    scanf("%d %d %d", &h, &m, &s);
    printf("%d", convert(h, m, s));
}
long convert(long h, long m, long s)
{
    int hour = h * 3600;
    int minute = m * 60;
    int second = s;
    int total = hour + minute + second;
    return total;
}