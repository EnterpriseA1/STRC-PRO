#include <stdio.h>
#include <stdlib.h>


void counterClockwise_assign(int **arr,int row,int col);

int main()
{
    int n;
    scanf("%d", &n);
    int matrix_size = n*n;
    int num = 1;
    int **arr = malloc(n*sizeof(int*));
    int i,j;
    for (i = 0 ; i < n;i++){
        arr[i] = malloc(n*sizeof(int));
    }
    for (i = 0 ; i < n ; i++){
        for (j = 0 ; j < n ; j++){
            arr[i][j] = 0;
        }
    }
    counterClockwise_assign(arr,n,n);
    int a = 0;
    int sum = 0;
    while (a < n){
        sum += arr[a][a];
        a++;
    }
    printf("%d",sum);

}

void counterClockwise_assign(int **arr,int row,int col){
    int i,j,time_execute = 0;
    int size = row;
    int num = 1;
    while (time_execute < size){
        //RIGHT
        for (i = col - (col - time_execute) ; i < col - 1 - time_execute ; i++){
            arr[time_execute][i] = num;
            num++;
        }
        //DOWN
        for (i = row - (row - time_execute); i < row - time_execute ; i++){
            arr[i][col -  1 - time_execute] = num;
            num++;
        }
        //LEFT
        for (i = col - 2 - time_execute; i >= time_execute ; i--){
            arr[row - 1 - time_execute][i] = num ;
            num++;
        }
        //UP
        for (i = row - 2 - time_execute; i > time_execute ; i--){
            arr[i][col - (col - time_execute)] = num;
            num++;
        }
        time_execute++;
    }
}