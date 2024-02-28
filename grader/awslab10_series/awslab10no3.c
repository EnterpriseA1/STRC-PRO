#include <stdio.h>
#include <string.h>
int checklower(char *);
int checkUpper(char *);
int checklogin(char *, int);
int checkpass(char *, int);
int main(void)
{
    char login[10] = {'\0'};
    char pass[10] = {'\0'};
    char output[10] = {'\0'};
    int n;
    scanf("%d\n", &n);

    int i;
    char temp[100] = {'\0'};
    for (i = 0; i < n; i++)
    {
        gets(temp);
        int j_ = 0;
        int iterator = 0;
        while (temp[iterator] != ':')
        {
            iterator++;
        }

        for (j_ = 0; j_ < 10; j_++)
        {
            login[j_] = '\0';
            pass[j_] = '\0';
        }

        j_ = 0;
        int looper1, looper2;
        for (looper1 = 0; looper1 < iterator; looper1++)
        {
            login[j_++] = temp[looper1];
        }

        j_ = 0;
        for (looper2 = iterator + 1; looper2 < strlen(temp); looper2++)
        {
            pass[j_++] = temp[looper2];
        }

        if (checklogin(login, strlen(login)) && checkpass(pass, strlen(pass)))
        {
            printf("%s\n", login);
        }
    }
}

int checklower(char *arr)
{
    int i;
    for (i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] >= 'a' && arr[i] <= 'z')
        {
            return 1;
        }
    }
    return 0;
}

int checkUpper(char *arr)
{
    int i;
    for (i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] >= 'A' && arr[i] <= 'Z')
        {
            return 1;
        }
    }
    return 0;
}

int checklogin(char *arr, int size)
{
    int i;
    int lower = checklower(arr);
    int upper = checkUpper(arr);
    if (size == 4)
    {
        if (arr[0] >= '0' && arr[0] <= '9')
        {
            return 0;
        }
        else
        {
            if (lower || upper)
            {
                return 1;
            }
        }
    }
    else
    {
        return 0;
    }
    return 0;
}

int checkpass(char *arr, int size)
{
    int i, check = 0;
    int lower = checklower(arr);
    int upper = checkUpper(arr);

    int countNum = 0;
    for (i = 0; i < size; i++)
    {
        if (arr[i] >= '0' && arr[i] <= '9')
        {
            countNum++;
        }
    }

    if (size >= 4 && size <= 8)
    {
        if (upper && countNum >= 2)
        {
            return 1;
        }
    }
    return 0;
}