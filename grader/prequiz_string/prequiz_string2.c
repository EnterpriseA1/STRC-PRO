#include <stdio.h>
#include <string.h>
void sumNum(char[]);
int main(void)
{
    char string[31];
    gets(string);

    int i, size = strlen(string);
    char end[] = "end";

    char temp[31];
    while (1)
    {
        gets(temp);
        if (strcmp(temp, end) == 0)
        {
            break;
        }
        sumNum(temp);
    }
}

void sumNum(char string[])
{
    int i;
    int sum = 0, check = 0;
    for (i = 0; i < strlen(string); i++)
    {
        if (string[i] >= '0' && string[i] <= '9')
        {
            check = 1;
            sum += string[i] - '0';
        }
    }

    if (check)
    {
        printf("%d\n", sum);
    }
    else
    {
        printf("no numbers\n");
    }
}
