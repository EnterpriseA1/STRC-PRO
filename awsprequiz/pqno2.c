#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    int i,j;
    for (i = 0 ; i < n ;i++){
        scanf("%d",&arr[i]);
    }
    int num;
    for (scanf("%d",&num); num != - 1;scanf("%d",&num)){
        int f = 0;
        for (j = 0 ; j < n;j++){
            if (arr[j] > num){
                printf("%d ",j + 1);
                f = 1;    
            }
        }
        if (!f){
            printf("%d",0);
        }
        printf("\n");
    }
}