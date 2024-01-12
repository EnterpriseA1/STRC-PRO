#include <stdio.h>
int main()
{
    int year;
    float gpa;
    char approval;
    scanf("%d %f %c", &year, &gpa, &approval);
    if (gpa < 3.00)
    {
        if (year >= 2)
        {
            if (gpa < 2.50)
            {
                printf("not approved\n");
                printf("grade < 2.50");
            }
            else if (approval == 'N')
            {
                printf("not approved\n");
                printf("no help");
            }
            else
            {
                printf("approved");
            }
        }
        else
        {
            printf("not approved\n");
            printf("year < 2");
        }
    }
    else
    {
        printf("approved");
    }
    return 0;
}