#include <stdio.h>
void numsLetter(int num)
{
    switch (num)
    {
    case 0:
        printf("Zero");
        break;
    case 1:
        printf("One");
        break;
    case 2:
        printf("Two");
        break;
    case 3:
        printf("Three");
        break;
    case 4:
        printf("Four");
        break;
    case 5:
        printf("Five");
        break;
    case 6:
        printf("Six");
        break;
    case 7:
        printf("Seven");
        break;
    case 8:
        printf("Eight");
        break;
    case 9:
        printf("Nine");
        break;
    default:
        printf("Invalid");
        break;
    }
}

int main()
{
    int a;
    scanf("%d", &a);
    int hund = (a / 100) % 100;
    int tens = (a / 10) % 10;
    int digits = a % 10;

    if (a >= 100 && a <= 999)
    {
        numsLetter(hund);
        printf(" ");
        numsLetter(tens);
        printf(" ");
        numsLetter(digits);
    }
    return 0;
}
