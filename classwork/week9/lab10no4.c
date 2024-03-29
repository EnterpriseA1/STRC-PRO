#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str1[100], str2[100], str_rem[100];
    int i = 0, j = 0, k = 0;

    printf("Enter the First string:\n");
    fflush(stdin);
    gets(str1);

    printf("Enter the Second string:\n");
    gets(str2);

    char characters[100] = {'\0'};
    int frequency[100] = {0};
    int loop, counter = 0,
              check = 0; // check if str1[i] is already in characters
    for (i = 0; str1[i] != '\0'; i++)
    {
        for (j = 0; str2[j] != '\0'; j++)
        {
            if (str1[i] == str2[j])
            {
                characters[counter] = str1[i];
                for (loop = 0; characters[loop] != '\0'; loop++)
                {
                    if (str1[i] == characters[loop])
                    {
                        characters[loop] = str1[i];

                        break;
                    }
                    else
                    {
                        characters[counter] = str1[i];
                    }
                }

                for (loop = 0; loop < strlen(characters); loop++)
                {
                    if (str2[j] == characters[loop])
                    {
                        frequency[loop]++;
                    }
                }
                counter++;
                continue;
            }
            else
            {
                str_rem[k] = str2[j];
                k++;
            }
        }
        str_rem[k] = '\0';
        strcpy(str2, str_rem);
        k = 0;
    }
    for (i = 0; i < strlen(characters); i++)
    {
        printf("%c - %d\n", characters[i], frequency[i]);
    }
    printf("Character(s) that didn't remove: ");
    for (i = 0; i < strlen(str1); i++)
    {
        if (str1[i] != characters[i])
        {
            printf("%c ", str1[i]);
        }
    }
    printf("\nOn removing characters from second string we get: %s\n", str_rem);

    return 0;
}
