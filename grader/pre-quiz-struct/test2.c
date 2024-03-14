#include <stdio.h>
typedef struct
{
	char name[16];
	char surname[20];
	int score[5];
	float stotal;
} Student;
void readStudentData(Student *, int);
void printScore2(Student[], int);

void main()
{
	int n;
	scanf("%d", &n);

	Student std[n];

	int i;
	for (i = 0; i < n; i++)
	{
		readStudentData(&std[i], n);
	}
	printScore2(&std, n);
}

void readStudentData(Student *std, int n)
{
	scanf("%s %s", std->name, std->surname);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &std->score[i]);
	}
}

void printScore2(Student std[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%s %d\n", std[i].name, std[i].score[1]);
	}
}
