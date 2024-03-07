#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addRecord(char *name, int age);

int main(void){
	char name[64];
	int age;
	printf("Enter name: "); scanf("%s",name);
	printf("Enter age: "); scanf("%d",&age);
	addRecord(name, age);
	return 0;
}

void addRecord(char *name, int age){
	FILE *fr, *fw;
	fr = fopen("./lab12/no1/first.txt","r");
	if(fr == NULL){
		fw = fopen("./lab12/no1/first.txt","a");
		fprintf (fw,"%s\t%d\n",name,age);
	}
	else{
		fw = fopen("./lab12/no1/first.txt","a");
		fprintf (fw,"%s\t%d\n",name,age);
	}
	if(fr != NULL) fclose(fr);
	if(fw != NULL) fclose(fw);
}
