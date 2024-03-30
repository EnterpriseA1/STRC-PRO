#include <stdio.h>
#include <string.h>
typedef struct
{
    int length;
    int repeat;
    char word[32];
} storage;

void splitString(char *, storage *, int *);
void checkCond(storage *, int);
int main(void)
{
    storage word[1000];
    char string[1001];
    int totalWord;
    fgets(string, 1001, stdin);
    string[strcspn(string, "\n")] = '\0';
    splitString(string, &word, &totalWord);
    checkCond(&word, totalWord);
}

void splitString(char *string, storage *word, int *ptr)
{
    int i = 0, j = 0, k = 0;
    int wordcount = 0;
    char temp[32];
    int length = strlen(string);
    while (i <= length)
    {
        if (i != length && string[i] != ' ')
        {
            temp[j++] = string[i];
            temp[j] = '\0';
        }
        else
        {
            strcpy(word[wordcount].word, temp);
            for (k = 0; k < j; k++)
            {
                temp[k] = '\0';
            }
            wordcount++;
            j = 0;
        }
        i++;
    }
    *ptr = wordcount;
}

void checkCond(storage *word, int numberOfWord)
{
    int i, j, count = 0;
    int result = 0;
    for (i = 0; i < numberOfWord; i++)
    {
        count = 0;
        for (j = 0; j < numberOfWord; j++)
        {
            if (!(strcmp(word[i].word, word[j].word)))
            {
                count++;
            }
        }
        word[i].length = strlen(word[i].word);
        word[i].repeat = count;
    }

    int maxLength = 0, maxRepeat = 0;
    for (i = 0; i < numberOfWord; i++)
    {
        if (word[i].repeat > word[maxRepeat].repeat)
        {
            maxRepeat = i;
        }
        if (word[i].length > word[maxLength].length)
        {
            maxLength = i;
        }
    }
    printf("%s %s", word[maxRepeat].word, word[maxLength].word);
}
/*
This your teacher lectures for your exam
your lectures

Random case that I thinking from my deadass brain it's fucking random case to test
case thinking
*/