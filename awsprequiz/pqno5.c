#include <stdio.h>

int main(){
    int r = 2,c;
    scanf("%d",&c);
    int arr[r + 1][c];
    int i,j;
    for (i = 0 ; i < c;i++){
        arr[r][i] = 0;
    }
    for (i = 0 ; i < r ; i++){
        for (j = 0 ; j < c ; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for (i = 0 ; i < r ; i++){
        for (j = 0 ; j < c ; j++){
            arr[r][j] += arr[i][j];
        }
    }
     for (i = 0 ; i <= r ; i++){
        for (j = 0 ; j < c ; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

}