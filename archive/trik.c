#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void SWAP(int *, int, int);
void main()
{
    int i;
    int pos[3] = {1, 0, 0};
    char input[51];
    for (i = 0; i < 51; i++)
    {
        input[i] = '\0';
    }
    scanf("%s", input);

    for (i = 0; i < strlen(input); i++)
    {
        if (input[i] == 'A')
        {
            if (pos[0])
            {
                SWAP(pos, 0, 1);
            }
            else
            {
                SWAP(pos, 1, 0);
            }
        }
        else if (input[i] == 'B')
        {
            if (pos[1])
            {
                SWAP(pos, 1, 2);
            }
            else
            {
                SWAP(pos, 2, 1);
            }
        }
        else if (input[i] == 'C')
        {
            if (pos[2])
            {
                SWAP(pos, 2, 0);
            }
            else
            {
                SWAP(pos, 0, 2);
            }
        }
    }
    for (i = 0; i < 3; i++)
    {
        if (pos[i] == 1)
        {
            printf("%d", i + 1);
            break;
        }
    }
}

void SWAP(int *arr, int p1, int p2)
{
    int temp = arr[p1];
    arr[p1] = arr[p2];
    arr[p2] = temp;
}