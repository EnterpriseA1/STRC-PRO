#include<stdio.h>
typedef struct {
	char name[16];
	char surname[20];
	int score[5];
	float stotal;
} Student;
void readStudentData(Student *,int);
void printMaxScore(Student *, int);

void main(){
	int n;
	scanf("%d",&n);
	
	Student std[n];
	
	int i;
	for(i = 0;i<n;i++){
		readStudentData(&std[i],n);
	}
	int m;
	int index;
	scanf("%d",&m);
	for(i= 0; i<m;i++){
		scanf("%d",&index);
		printMaxScore(&std[i],index);
	}
}

void readStudentData(Student * std,int n){
	scanf("%s", std->name);
	scanf("%s", std->surname);
	int i;
	for(i=0;i<n;i++){
		scanf("%d", &std->score[i]);
	}
}

void printMaxScore(Student *std, int index){
	index = index-1;
	int indexName = 0;
	int max = std[0].score[index];
	int i;
	for(i =0;i<5;i++){
		if(std[i].score[index] > max){
			max = std[i].score[index];
			indexName = i;
		}
	}
	printf("%s %d\n", std[indexName].name, max);
}
