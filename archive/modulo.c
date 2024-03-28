#include <stdio.h>
void main()
{
    int i, j;
    int num;
    int arr[10];
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &num);
        arr[i] = num % 42;
    }

    int distinct = 0;
    int check = 0;
    for (i = 0; i < 10; i++)
    {
        check = 0;
        for (j = i + 1; j < 10; j++)
        {
            if (arr[i] == arr[j])
            {
                check = 1;
                break;
            }
        }
        distinct = check ? distinct : distinct + 1;
    }
    printf("%d", distinct);
}