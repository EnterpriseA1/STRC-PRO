#include <stdio.h>
#include <string.h>
int checkPalindrome(char *);
int main(void)
{
    int i;
    char text[10];
    while (1)
    {
        scanf("%s", text);
        if (!(strcmp(text, "end")))
        {
            break;
        }
        printf("%s %s\n", text, checkPalindrome(text) ? "is palindrome\n" : "not palindrome\n");
    }
}

int checkPalindrome(char *string)
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

/* testcases
radar
level
apple
kayak
banana
civic
mango
rotor
grape
racecar
*/