#include <stdio.h>
#include <stdlib.h>

void transpose(int ***arr,int *row,int *col);
void print_array(int **arr,int row,int col);
void swap(int *x,int *y);

int main(){
    int r,c;
    scanf("%d %d",&r,&c);
    int **arr;
    arr =  (int**)malloc(r * sizeof(int*));
    int i,j;
    for (i = 0 ; i < r ;i++){
        arr[i] = (int*)malloc(c * sizeof(int));
    }
    for (i = 0; i < r;i++){
        for (j= 0; j < c; j++)
        {
            int val;
            scanf("%d%*c",&val);
            arr[i][j] = val;
        }
        
    }
    transpose(&arr,&r,&c);
    print_array(arr,r,c);
}


void print_array(int **arr,int row,int col){
    int i,j;
     for (i = 0; i < row;i++){
        for (j= 0; j < col; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

 void transpose(int ***arr, int *row, int *col) {
    int i, j;
    swap(row, col);
    int **temp= (int **)malloc(*row * sizeof(int *));
    for (i = 0; i < *row; i++) {
        temp[i] = (int *)malloc(*col * sizeof(int));
    }
    for (i = 0; i < *row; i++) {
        for (j = 0; j < *col; j++) {
            temp[i][j] = (*arr)[j][i];
        }
    }
    for (i = 0; i < *col; i++) {
        free((*arr)[i]);
    }
    free(*arr);
    *arr = temp;
}

void swap(int *x,int *y){
    int temp = 0;
    temp = *y;
    *y = *x;
    *x = temp;
}