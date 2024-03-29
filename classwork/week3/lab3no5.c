#include <stdio.h>
int main(){
	
	int month;
	scanf("%d",&month);
	if(month>0){
		if(month==12){
			printf("Winter");
		}
		else if(month>=9){
			printf("Autumn");
		}
		else if(month>=6){
			int temp = 12 - month;
			printf("Summer\n");
			printf("%d month(s) until Winter",temp);
		}
		else if(month>=3){
			printf("Spring");
		}
		else{
			printf("Winter");
		}
	}
	else{
		printf("No Season");
	}
	return 0;
}
