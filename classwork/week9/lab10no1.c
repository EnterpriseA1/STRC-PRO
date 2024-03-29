#include <stdio.h>
#include <string.h>
int checkLogin(char *login, char *passwd, char *logindb, char *passdb);
int main()
{
    int i;
    char *login[64] = {"user1", "user2", "user3", "user4", "user5"};
    char *password[64] = {"pass1", "pass2", "pass3", "pass4", "pass5"};

    char *loginUser[64];
    char *loginPwd[64];
    printf("Enter login : ");
    gets(loginUser);
    printf("Enter password : ");
    gets(loginPwd);

    int check = 0;
    for (i = 0; i < 5 && !check; i++)
    {
        if (checkLogin(loginUser, loginPwd, login[i], password[i]))
        {
            printf("Welcome\n");
            check = 1;
        }
        if (i == 4 && !check)
        {
            printf("Incorrect login or password\n");
        }
    }
}

int checkLogin(char *login, char *passwd, char *logindb, char *passdb)
{
    int result = 0;
    if (!strcmp(login, logindb) && !strcmp(passwd, passdb))
    {
        result = 1;
    }
    return result;
}