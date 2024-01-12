#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int *arr = NULL;
    arr = malloc(sizeof(int) * 3);

    char *nominator = NULL;
    nominator = malloc(sizeof(char) * 4);

    // clear data
    for (int i = 0; i < 3; i++)
    {
        arr[i] = 0;
        nominator[i] = 0;
    }

    int i, j;
    // input data
    for (i = 0; i < 3; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%s", nominator);

    // sort data
    int temp = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // find min max
    int min = arr[0],
        max = arr[0];

    for (i = 0; i < 3; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    // order array a<b<c
    int *output = malloc(sizeof(int) * 3);
    for (i = 0; i < 3; i++)
    {
        if (nominator[i] == 'A')
        {
            output[i] = min;
        }
        if (nominator[i] == 'C')
        {
            output[i] = max;
        }
        if (nominator[i] == 'B')
        {
            output[i] = arr[1];
        }
    }

    // output a<b<c
    for (i = 0; i < 3; i++)
    {
        printf("%d ", output[i]);
    }
    return 0;
}