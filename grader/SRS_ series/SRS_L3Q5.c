#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int money;
    scanf("%d", &money);

    int i;
    int *arr = malloc(sizeof(int) * 7);

    for (i = 0; i < 7; i++)
    {
        arr[i] = 0;
    }

    while (money > 0)
    {
        if (money >= 1000)
        {
            money -= 1000;
            arr[0]++;
        }
        else if (money >= 500)
        {
            money -= 500;
            arr[1]++;
        }
        else if (money >= 100)
        {
            money -= 100;
            arr[2]++;
        }
        else if (money >= 50)
        {
            money -= 50;
            arr[3]++;
        }
        else if (money >= 20)
        {
            money -= 20;
            arr[4]++;
        }
        else if (money >= 10)
        {
            money -= 10;
            arr[5]++;
        }
        else if (money >= 1)
        {
            money -= 1;
            arr[6]++;
        }
    }
    for (i = 0; i < 7; i++)
    {
        printf("%d ", arr[i]);
    }
}