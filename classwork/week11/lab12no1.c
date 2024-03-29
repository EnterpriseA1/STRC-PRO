#include <stdio.h>
#include <string.h>
void addRecord(char *name, int age);
int main()
{
    char name[64];
    int age;
    printf("Enter name : ");
    scanf("%s", name);
    printf("Enter age : ");
    scanf("%d", &age);
    addRecord(name, age);
    return 0;
}

void addRecord(char *name, int age)
{
    FILE *fptr;
    fptr = fopen("./lab12/no1/first.txt", "r");
    if (fptr == NULL)
    {
        fclose(fptr);
        fptr = fopen("./lab12/no1/first.txt", "w");
        fprintf(fptr, "%s \t %d \n", name, age);
        fclose(fptr);
    }
    else
    {
        fclose(fptr);
        fptr = fopen("./lab12/no1/first.txt", "a");
        fprintf(fptr, "%s \t %d \n", name, age);
        fclose(fptr);
    }
}
