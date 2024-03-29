#include <stdio.h>
#include <string.h>
int main(void)
{
    char s[80];
    int i, sum = 0;

    printf("Enter input: ");
    gets(s);

    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            sum += s[i] - '0';
        }
    }
    printf("%d", sum);
}
