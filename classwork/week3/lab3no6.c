#include <stdio.h>
int main(){
	int score,temp;
	scanf("%d",&score);
	temp = 85 - score;

	if (score>67){
		if (score>=85){
			printf("A\n");
		}
		else if(score >=75){
			printf("B\n");
			printf("%d score(s) away from A",temp);
		}
		else{
			printf("C\n");
			printf("%d score(s) away from A",temp);
		}
	}
	else if(score>=55){
		printf("D\n");
		printf("%d score(s) away from A",temp);
	}
	else{
		printf("F\n");
		printf("%d score(s) away from A",temp);
	}
	return 0;
}
