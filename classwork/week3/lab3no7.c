#include <stdio.h>
int main(){
	int score,temp;
	char grade;
	scanf("%d",&score);
	temp = 85-score;
	
	
	if (score>67){
		if (score>=85){
			grade = 'A';
			printf("A\n");
		}
		else if(score >=75){
			grade = 'B';
			printf("B\n");
			printf("%d score(s) away from A\n",temp);
		}
		else{
			grade = 'C';
			printf("C\n");
			printf("%d score(s) away from A\n",temp);
		}
	}
	else if(score>=55){
		grade = 'D';
		printf("D\n");
		printf("%d score(s) away from A\n",temp);
	}
	else{
		grade = 'F';
		printf("F\n");
		printf("%d score(s) away from A\n",temp);
	}
	
	switch(grade){
		case 'A': printf("Excellent"); break;
		case 'B': printf("Good"); break;
		case 'C': printf("So So"); break;
		case 'D': printf("Fails"); break;
		case 'F': printf("Get Lost"); break;
		default: printf("Invalid"); break;
	}
	return 0;
}
