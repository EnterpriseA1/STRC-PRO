#include <stdio.h>
void printHead();
void printBody();

void main()
{
    int width, height;
    scanf("%d %d", &width, &height);
    printHead(width);
    printBody(width, height);
    printHead(width);
}

void printHead(int x)
{
    int i;
    for (size_t i = 0; i < x; i++)
    {
        printf("*");
    }
    printf("\n");
}

void printBody(int x, int y)
{
    int i, j;
    for (size_t i = 0; i < y - 2; i++)
    {
        for (size_t j = 0; j < x; j++)
        {
            if (j == 0 || j == x - 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
