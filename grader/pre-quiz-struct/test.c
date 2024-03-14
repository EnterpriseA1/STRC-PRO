#include<stdio.h>
#include<string.h>
typedef struct {
	char name[64];
	char phoneNumber[32];
} phoneBook;

void addRecord(char *someone, char *pnumber);
char *searchPhone(char *name, phoneBook);

void main(){
	phoneBook directory[50];
	int n;
	scanf("%d",&n);
	
	int i;
	for(i = 0;i<n;i++){
		addRecord(&directory[i].name,&directory[i].phoneNumber);
	}
	
	int searchcount = 0;
	scanf("%d",&searchcount);
	char *name;
	for(i = 0;i<searchcount;i++){
		scanf("%s", name);
		searchPhone(name, &directory[]);
	}
}

void addRecord(char *someone, char *pnumber){
	scanf("%s %s", someone,pnumber);
}

char *searchPhone(char *name,phoneBook *dir){
	char * result;
	if(!(strcmp(name,dir->name))){
		result = dir->name;
	}
	else{
		result = "N/A";
	}
	return result;
}
