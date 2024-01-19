#include <stdio.h>
#include <stdlib.h>

void merge_horizontal(int ***dest_Array, int **arr_a,int **arr_b,int size,int start_inx,int* new_size);
void merge_vertical(int ***dest_Array, int **arr_a,int **arr_b,int size,int start_inx,int* new_size);
void print_array(int **arr, int row, int col);
int main(){

    int ARR_SIZE;
    char direction;
    scanf("%d",&ARR_SIZE);
    int new_rowSize = ARR_SIZE;
    int new_colSize = ARR_SIZE;
    int **ARR_A = malloc(sizeof(int*) * ARR_SIZE);
    int **ARR_B = malloc(sizeof(int*) * ARR_SIZE);
    int **RES_ARR = NULL;
    int M_INX;
    int i,j;
    for (i = 0 ; i < ARR_SIZE ; i++){
         ARR_A[i] = malloc(sizeof(int) * ARR_SIZE);
         ARR_B[i] = malloc(sizeof(int) * ARR_SIZE);
    }
    for (i = 0 ; i < ARR_SIZE ; i++){
        for (j = 0 ; j < ARR_SIZE ; j++){
            ARR_A[i][j] = 0;    
            ARR_B[i][j] = 0;    
        }
    }
    for (i = 0 ; i < ARR_SIZE ; i++){
        for (j = 0 ; j < ARR_SIZE;j++){
            scanf("%d",&ARR_A[i][j]);
        }
    }
     for (i = 0 ; i < ARR_SIZE ; i++){
        for (j = 0 ; j < ARR_SIZE;j++){
            scanf("%d",&ARR_B[i][j]);
        }
    }
    scanf("\n%c",&direction);
    scanf("%d",&M_INX);
    
    if (direction == 'H'){
        merge_horizontal(&RES_ARR,ARR_A,ARR_B,ARR_SIZE,M_INX,&new_colSize);
    }
    else{
        merge_vertical(&RES_ARR,ARR_A,ARR_B,ARR_SIZE,M_INX,&new_rowSize);
    }
    print_array(RES_ARR,new_rowSize,new_colSize);
}

void merge_horizontal(int ***dest_Array, int **arr_a,int **arr_b,int size,int start_inx,int* new_size){
    int NewArrsize = (start_inx - 1) + size;
    int i,j;
    *dest_Array = malloc(sizeof(int*) * size);
    for (i = 0 ; i < NewArrsize ; i++){
        (*dest_Array)[i] = malloc(sizeof(int) * NewArrsize);
    }
    int range_holder = (start_inx % 2 == 0 && start_inx != size) ? (1) : (0);
    for (i = 0 ; i < size ;i++){
        for (j = 0 ; j < NewArrsize ; j++){
            (*dest_Array)[i][j] = 0;
        }
    }
    for (i = 0 ; i < size ; i++){
        for (j = 0 ; j < size ; j++){
            (*dest_Array)[i][j] += arr_a[i][j];
        }
    }
    for (i = 0 ; i < size ; i++){
        for (j = start_inx - 1; j < NewArrsize ; j++){
            (*dest_Array)[i][j] += arr_b[i][j - ((start_inx + 1 - size) + range_holder)];
        }
    }
    *new_size = NewArrsize;
}
void merge_vertical(int ***dest_Array, int **arr_a,int **arr_b,int size,int start_inx,int* new_size){
    int NewArrsize = (start_inx - 1) + size;
    int i,j;
    *dest_Array = malloc(sizeof(int*) * NewArrsize);
    for (i = 0 ; i < NewArrsize ; i++){
        (*dest_Array)[i] = malloc(sizeof(int) * size);
    }
    for (i = 0 ; i < NewArrsize ;i++){
        for (j = 0 ; j < size ; j++){
            (*dest_Array)[i][j] = 0;
        }
    }
    for (i = 0 ; i < size ; i++){
        for (j = 0 ; j < size ; j++){
            (*dest_Array)[i][j] += arr_a[i][j];
        }
    }
    for (i = start_inx - 1 ; i < NewArrsize ; i++){
        for (j = 0; j < size ; j++){
            (*dest_Array)[i][j] += arr_b[i - (start_inx - 1)][j];
        }
    }
    *new_size = NewArrsize;
}
void print_array(int **arr,int row,int col){
    int i,j;
    for (i = 0 ; i < row ; i++){
        for (j = 0 ; j < col; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}