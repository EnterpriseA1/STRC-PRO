#include <stdio.h>
#include <stdlib.h>


int main(){
    int row,col;
    scanf("%d %d",&row,&col);
    int MATRIX_A[row][col];
    int MATRIX_B[row][col];
    int i,j;
    for (i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            MATRIX_A[i][j] = 0;
            MATRIX_B[i][j] = 0;
        }
    }
    for (i = 0; i < row; i++){
        for(j = 0; j < col; j++){
                scanf("%d",&MATRIX_A[i][j]);
            }
    }
    for (i = 0; i < row; i++){
        for(j = 0; j < col; j++){
                scanf("%d",&MATRIX_B[i][j]);
            }
    }
    for (i = 0; i < row; i++){
        for (j = 0 ; j < col; j++){
            printf("%d ",MATRIX_A[i][j] + MATRIX_B[i][j]);
        }
        printf("\n");
    }
}