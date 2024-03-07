#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NO_SCORE 5
typedef struct {
	char name[16];
	char surname[20];
	int score[NO_SCORE];
	float total;
} Student;

void readStudentData(Student *);
void findTotalScore(Student *);
float findAverage(Student);
void findLessThanTen(Student);


void main() {
	Student std[10];
	float avg;
	int i;
	for(i=0;i<10;i++){
		readStudentData(&std[i]);
	}
	findTotalScore(&std[i]);
	avg = findAverage(std[i]);
	printf("\n\nAverage score is %.2f", avg);
	findLessThanTen(std[i]);
}


void readStudentData(Student *pStd) {
	int i=0;
	//craate file std10.dat
	FILE *fr, *fw;
	fr = fopen("./lab12/no2/std10.txt","r");
	if(fr == NULL){
		fw = fopen("./lab12/no2/first.txt","a");
	}
	else{
		fw = fopen("./lab12/no2/first.txt","a");
	}
	printf("Enter student data\n");
	printf("\tName : ");
	scanf("%s", &pStd->name);
	printf("\tSurname : ");
	scanf("%s", &pStd->surname);
	fprintf (fw,"Name:%s\tSurname%s\t%d",&pStd->name,&pStd->surname);
	for (i=0; i<NO_SCORE; i++) {
		printf("\tScore %d : ", i+1);
		scanf("%d", &pStd->score[i]);
		fprintf (fw,"\t%d",&pStd->score[i]);
	}
	printf("\n");
	if(fr != NULL) fclose(fr);
	if(fw != NULL) fclose(fw);
}
//done

void findTotalScore(Student *pStd) {
	int i;
	printf("\n\nPrint student data");
	printf("\n\t%s %s got score ", pStd->name, pStd->surname);
	pStd->total = 0.0;
	for (i=0; i<NO_SCORE; i++) {
		printf("%6d", pStd->score[i]);
		pStd->total += pStd->score[i];
	}
	printf("\n\tTotal score is %.2f", pStd->total);
}


float findAverage(Student s) {
	return(s.total/NO_SCORE);
}


void findLessThanTen(Student s) {
	int i,count=0;
	printf("\n\nScore less than 0");
	for (i=0; i<NO_SCORE; i++) {
		if (s.score[i] < 10) {
		printf("\n\tTest no.%d - %d", i+1, s.score[i]);
		count++;
		}
	}
	if (count==0)
	printf(" -> None");
}
