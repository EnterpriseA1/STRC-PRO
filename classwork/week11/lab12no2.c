#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NO_SCORE 5
typedef struct
{
    char name[20];
    char surname[20];
    int score[NO_SCORE];
    float total;
} Student;

void readStudentData(Student *);
void findTotalScore(Student *);
float findAverage(Student);
void findLessThanTen(Student);
void main()
{
    FILE *fPtr;
    int i, j;
    Student std[10];
    float avg;
    fPtr = fopen("lab12\\no2\\std10.txt", "w");

    for (i = 0; i < 10; i++)
    {
        readStudentData(&std[i]);
        findTotalScore(&std[i]);
        avg = findAverage(std[i]);
        printf("\n\nAverage score is %.2f", avg);
        findLessThanTen(std[i]);
        fprintf(fPtr, "%s %s ", std[i].name, std[i].surname);
        for (j = 0; j < 5; j++)
        {
            fprintf(fPtr, "%d ", std[i].score[j]);
        }
        fprintf(fPtr, "\n");
    }
    fclose(fPtr);

    fPtr = fopen("lab12\\no2\\std10.txt", "r");
    printf("\nRead file : \n");
    char stringsak100[100];
    while (fgets(stringsak100, sizeof(stringsak100), fPtr) != NULL)
    {
        printf("\t%s", stringsak100);
    }
}

void readStudentData(Student *pStd)
{
    int i;
    printf("Enter student data\n");
    printf("\tName : ");
    scanf("%s", pStd->name);
    printf("\tSurname : ");
    scanf("%s", pStd->surname);
    for (i = 0; i < NO_SCORE; i++)
    {
        printf("\tScore %d : ", i + 1);
        scanf("%d", &pStd->score[i]);
    }
}

void findTotalScore(Student *pStd)
{
    int i;
    printf("\nPrint student data");
    printf("\n\t%s %s got score ", pStd->name, pStd->surname);
    pStd->total = 0.0;
    for (i = 0; i < NO_SCORE; i++)
    {
        printf("%6d", pStd->score[i]);
        pStd->total += pStd->score[i];
    }
    printf("\n\tTotal score is %.2f", pStd->total);
}

float findAverage(Student s)
{
    return (s.total / NO_SCORE);
}

void findLessThanTen(Student s)
{
    int i, count = 0;
    printf("\n\nScore less than 10");
    for (i = 0; i < NO_SCORE; i++)
    {
        if (s.score[i] < 10)
        {
            printf("\n\tTest no.%d - %d", i + 1, s.score[i]);
            count++;
        }
    }
    printf("\n\n");
    if (count == 0)
        printf(" -> None\n");
}