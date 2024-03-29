#include <stdio.h>
#include <string.h>
typedef struct
{
	char name[64];
	char phoneNumber[32];
} phoneBook;

void addRecord(char *someone, char *pnumber);
char *searchPhone(char *name, phoneBook dir[]);

void main()
{
	int n, i;
	phoneBook directory[50];
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		addRecord(directory[i].name, directory[i].phoneNumber);
	}

	int m;
	char tempName[64];

	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%s", tempName);
		printf("%s\n", searchPhone(tempName, &directory));
	}
}

void addRecord(char *someone, char *pnumber)
{
	scanf("%s %s", someone, pnumber);
}

char *searchPhone(char *name, phoneBook dir[])
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