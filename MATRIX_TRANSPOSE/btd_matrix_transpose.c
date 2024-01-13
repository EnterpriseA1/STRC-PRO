#include <stdio.h>
#include <stdlib.h>

void transpose(int ***arr, int *row, int *col);
void print_array(int **arr, int row, int col);
void swap(int *x, int *y);
void get_input(int ***destarray, int *row, int *col);

int main() {
    int **arr = NULL;
    int row = 0, col = 0;
    get_input(&arr, &row, &col);
    transpose(&arr, &row, &col);
    print_array(arr, row, col);
    for (int i = 0; i < row; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

void print_array(int **arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void transpose(int ***arr, int *row, int *col) {
    int i, j;
    swap(row, col);
    int **temp = (int **)malloc(*row * sizeof(int *));
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

void swap(int *x, int *y) {
    int temp = *y;
    *y = *x;
    *x = temp;
}

void get_input(int ***destarray, int *row, int *col) {
    int con = 1;
    int count = 0;
    int i, j;
    int *arr = NULL;
    int time = 1;
    while (con) {
        int val;
        char newline;
        scanf("%d%c", &val, &newline);
        if (newline == '\n' && val != -1){
            (*row)++;
            if (time){(*col)++;}
            time = 0;
        }
        if (val == -1){
            con = 0;
        }
        else {
            if (time){(*col)++;}
            int *reloc = realloc(arr, (count + 1) * sizeof(int));
            if (reloc != NULL) {
                arr = reloc;
                arr[count] = val;
                count++;
            }
        }
    }
    *destarray = malloc(*row * sizeof(int *));
    for (i = 0; i < *row; i++) {
        (*destarray)[i] = malloc(*col * sizeof(int));
    }
    int index = 0;
    for (i = 0; i < *row; i++) {
        for (j = 0; j < *col; j++) {
            (*destarray)[i][j] = arr[index++];
        }
    }
    free(arr);
}


