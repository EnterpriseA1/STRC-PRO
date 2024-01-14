#include <stdio.h>
#include <stdlib.h>

void maxmin(double *x,double *y,double arr[],int arr_size){
    double max=arr[0],min=arr[0];
    int i;
    for (i = 0 ; i < arr_size ; i++){
        double max_temp = ((max < arr[i]) ? (max = arr[i]) : 0);
        double min_temp = ((min > arr[i]) ? (min = arr[i]) : 0);
    }
    *x = max;
    *y = min;
}
void matrix_normalize(double *max,double *min,double arr[],int arr_size){
    int k;
    double dif = *max - *min;
    for (k = 0; k < arr_size ; k++){
        arr[k] = ((arr[k] - *min) / dif);
    }
}
void printf_matrix(int row,int col,double arr[]){
    int i,j,count;
    count = 0;
    for (i = 0; i < row ; i++){
        for (j = 0 ;j < col;j++){
            printf("%.4lf ",arr[count]);
            count++;
        }
        printf("\n");
    }

}
int main()
{
// Formula to normalize is X = [(Xi-Xmin)/(Xmax-Xmin)]
    int col,row;
    double max,min;
    double *arr;
    scanf("%d\n%d",&col,&row);
    int arr_size = col * row;
    arr = malloc(arr_size * sizeof(double));
    if (arr == NULL){
        printf("MALLOC FAILED");
    }
    int i,j;
    for (i = 0 ; i < arr_size;i++){
    double val;
    scanf("%lf",&val);
    arr[i] = val;
   }
   maxmin(&max,&min,arr,arr_size);
   matrix_normalize(&max,&min,arr,arr_size);
   printf_matrix(row,col,arr);
}
