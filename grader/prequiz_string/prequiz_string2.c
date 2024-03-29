#include <stdio.h>
#include <string.h>
int sumNum(char *);
int main(void)
{
    int n, i;
    char string[100];
    char temp[100];

    fgets(string, 100, stdin);
    string[strcspn(string, "\n")] = '\0';
    int condition = sumNum(string);
    scanf("%d\n", &n);

    printf("%d\n", condition);
    for (i = 0; i < n; i++)
    {
        fgets(temp, 100, stdin);
        temp[strcspn(temp, "\n")] = '\0';
    }
    if (sumNum(temp) == condition)
    {
        printf("%s\n", temp);
    }
    for (i = 0; i < strlen(temp); i++)
    {
        temp[i] = '\0';
    }
    fflush(stdin);
}

int sumNum(char *string)
{
    int i;
    int sum = 0, check = 0;
    for (i = 0; i < strlen(string); i++)
    {
        if (string[i] >= '0' && string[i] <= '9')
        {
            sum += string[i] - '0';
        }
    }
    return sum;
}
