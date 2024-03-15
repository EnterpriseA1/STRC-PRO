#include <stdio.h>
#include <string.h>
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
        if (strlen(temp) > size)
        {
            printf("%s\n", temp);
        }
    }
}