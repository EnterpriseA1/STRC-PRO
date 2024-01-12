#include <stdio.h>
int main()
{
    int hour, minute;
    scanf("%d:%d", &hour, &minute);

    if (hour >= 7 && hour <= 9)
    {
        if (hour == 7 && minute < 10)
        {
            printf("N");
        }
        else if (hour == 9 && minute > 30)
        {
            printf("N");
        }
        else
        {
            printf("Y");
        }
    }
    else
    {
        printf("N");
    }

    return 0;
}