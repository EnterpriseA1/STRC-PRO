#include <stdio.h>
#include <stdlib.h>


int main(){
    int n;
    int max_end = 0;
    int max_start = 0;
    scanf("%d",&n);
    size_t i;
    int **arr = malloc(n*sizeof(int * ));
    for (i = 0 ; i < n;i++){
        arr[i] = malloc(2*sizeof(int));
    }
    for (i = 0 ; i < n; i++){
        int start,end;
        scanf("%d %d",&start,&end);
        arr[i][0] = start; arr[i][1] = end;
        if (end > max_end){
            max_end = end;
        }
        if (start > max_start){
            
        }
    }
    size_t arr_size = max_end;
    int *time = malloc(arr_size * sizeof(int));
    for (i = 0; i < arr_size; i++){
        time[i] = 0;
    }
    for (i = 0; i < n; i++){
        int start_val = arr[i][0];
        int end_val = arr[i][1];
        for (int j = start_val - 1; j < end_val; j++){
            time[j] += 1;
        }
    }
    int max_time = 0;
    for (i = 0; i < arr_size - 1; i++){
        printf("%d ",time[i]);
        if (time[i] > max_time){
            max_time = time[i];
        }
    }
    printf("\n%d",max_time);
}