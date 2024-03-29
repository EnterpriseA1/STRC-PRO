#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int countVowel(char[], int *);
void main()
{
    int i;
    char text[MAX];
    int cVowel;
    printf("Enter text : ");
    gets(text);

    int *vowelCount;
    vowelCount = malloc(sizeof(int) * 5);
    cVowel = countVowel(text, vowelCount);
    char vowels[] = {'A', 'E', 'I', 'O', 'U'};

    printf("Text : [%s] has %d vowels\n", text, cVowel);
    for (i = 0; i < 5; i++)
    {
        printf("%c : %d\n", vowels[i], vowelCount[i]);
    }
}

int countVowel(char t[], int *vowelCount)
{
    int i = 0, count = 0;
    for (i = 0; i < 5; i++)
    {
        vowelCount[i] = 0;
    }
    i = 0;
    while (i < MAX && t[i] != '\0')
    {
        if (t[i] == 'A' || t[i] == 'a')
        {
            vowelCount[0] += 1;
            count++;
        }
        else if (t[i] == 'E' || t[i] == 'e')
        {
            vowelCount[1] += 1;
            count++;
        }
        else if (t[i] == 'I' || t[i] == 'i')
        {
            vowelCount[2] += 1;
            count++;
        }
        else if (t[i] == 'O' || t[i] == 'o')
        {
            vowelCount[3] += 1;
            count++;
        }
        else if (t[i] == 'U' || t[i] == 'u')
        {
            vowelCount[4] += 1;
            count++;
        }
        i++;
    }
    return count;
}