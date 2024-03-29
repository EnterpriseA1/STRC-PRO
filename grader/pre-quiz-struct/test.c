#include <stdio.h>
#include <string.h>
typedef struct
{
	char name[64];
	char phoneNumber[32];
} phoneBook;

void addRecord(char *someone, char *pnumber);
char *searchPhone(char *name, phoneBook *dir);

void main()
{
	phoneBook directory[50];
	int n;
	scanf("%d", &n);

	int i;
	for (i = 0; i < n; i++)
	{
		addRecord(&directory[i].name, &directory[i].phoneNumber);
	}

	int searchcount = 0;
	scanf("%d", &searchcount);
	char name[64];
	for (i = 0; i < searchcount; i++)
	{
		scanf("%s", name);
		printf("%s\n", searchPhone(&name, &directory[i]));
	}
}

void addRecord(char *someone, char *pnumber)
{
	scanf("%s %s", someone, pnumber);
}

char *searchPhone(char *name, phoneBook *dir)
{
	int i;
	for (i = 0; i < 50; i++)
	{
		if (strcmp(dir[i].name, name) == 0)
		{
			return dir[i].phoneNumber;
		}
	}
	return "N/A";
}
