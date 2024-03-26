#include <stdio.h>
#include <string.h>
typedef struct
{
    char loginname[64];
    char password[64];
} account;
typedef struct
{
    char stdID[16];
    char nameSurname[25];
    account stdACC;
} hoststd;

int checkLogin(account, hoststd);
int main()
{
    int i;
    account login;
    hoststd cs[5] = {
        {"66-040626-2686-9", "MR.A", "user1", "pass1"},
        {"66-040626-2686-9", "MR.B", "user2", "pass2"},
        {"66-040626-2686-9", "MR.C", "user3", "pass3"},
        {"66-040626-2686-9", "MR.D", "user4", "pass4"},
        {"66-040626-2686-9", "MR.E", "user5", "pass5"}};

    fflush(stdin);
    printf("Enter login : ");
    gets(login.loginname);
    printf("Enter password : ");
    gets(login.password);
    fflush(stdin);

    int check = 0;
    for (i = 0; i < 5 && !check; i++)
    {
        if (checkLogin(login, cs[i]))
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

int checkLogin(account login, hoststd cs)
{
    int result = 0;
    if (!strcmp(login.loginname, cs.stdACC.loginname) && !strcmp(login.password, cs.stdACC.password))
    {
        result = 1;
    }
    return result;
}