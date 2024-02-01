#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int i;
    for (i = 0 ; i < n ; i++){
        int score,midterm,final;
        scanf("%d %d %d",&score,&midterm,&final);
        int total = score + midterm + final;
        if (total >= 80 ){
            printf("A");
        }
        else if (total >= 75){
            printf("B+");
        }
        else if (total >= 70){
            printf("B");
        }
        else if (total >= 65){
            printf("C+");
        }
        else if (total >= 60){
            printf("C");
        }
        else if (total >= 55){
            printf("D+");
        }
        else if (total >= 50){
            printf("D");
        }
        else{
            printf("F");
        }
        printf("\n");
    }

}