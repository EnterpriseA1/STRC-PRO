#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    int max_size = n + 1;
    int **arr = malloc(max_size*sizeof(int*));
    int i,j;
    for (i = 0 ; i < max_size;i++){
        arr[i] = malloc(max_size*sizeof(int));
    }
    for (i = 0 ; i < max_size ; i++){
        for (j = 0 ; j < max_size ; j++){
            arr[i][j] = 0;
        }
    }
    for (i = 0 ; i < n ; i++){
        for (j = 0 ; j < n ; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for (i = 0 ; i < n ; i++){
        for (j = 0 ; j < n ; j++){
            arr[i][n] += arr[i][j];
            arr[n][j] += arr[i][j];
        }
        arr[n][n] += arr[i][n];
    }
    if ((arr[n][n] / arr[n][0]) == n){
        printf("yes");
    }
    else{
        printf("no");
    }
    return 0;
}   