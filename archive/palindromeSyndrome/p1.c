#include <stdio.h>
#include <string.h>
int isPalindrome(char *);
void splitString(char *, char *);
int main(void)
{
    char text[100], returner[100];
    fgets(text, 100, stdin);
    text[strcspn(text, "\n")] = '\0';
    splitString(text, returner);
}
void splitString(char *string, char *res)
{
    int i = 0, j = 0, k = 0;
    int length = strlen(string);
    while (i < length)
    {
        if (*(string + i) != ' ' || i == length - 1)
        {
            res[j++] = string[i];
        }
        else
        {
            if (j > 0)
            {
                res[j] = '\0';
                printf("\"%s\",", res);
                for (k = 0; k < j; k++)
                {
                    res[k] = '\0';
                }
                j = 0;
            }
        }
        i++;
    }
}
int isPalindrome(char *string)
{
    int i, result = 1;
    int length = strlen(string);
    int mid = length / 2;
    for (i = 0; i < mid; i++)
    {
        if (*(string + i) != *(string + (length - i - 1)))
        {
            result = 0;
            break;
        }
    }
    return result;
}
