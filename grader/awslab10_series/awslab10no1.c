#include <stdio.h>
#include <string.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    char text[n][100];

    int i, j;
    for (i = 0; i < n; i++)
    {
        scanf("%s", &text[i]);
    }

    int check = 0;
    for (i = 0; i < strlen(text); i++)
    {
        check = 0;
        for (j = 0; text[i][j] != '\0'; j++)
        {
            if (text[i][j] >= 'a' && text[i][j] <= 'z')
            {
                check = 1;
            }
            else
            {
                check = 0;
                break;
            }
        }
        if (check)
        {
            printf("%s\n", text[i]);
        }
    }
}