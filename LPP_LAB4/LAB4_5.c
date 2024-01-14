#include <stdio.h>
#include <stdlib.h>


int main(){
    int n;
    int max_end = 0;
    int max_start = 0;
    scanf("%d",&n);
    int arr[n][2];
    int i,j;
    int max_range = 0;
    for (i = 0 ; i < n;i++){
        for (j = 0 ; j < 2;j++){
            scanf("%d",&arr[i][j]);
            int end = arr[i][j];
            if (end > max_range){
                max_range = end;
            }
        }
    }
    int arr_time[max_range];

    for (i = 0 ; i < max_range; i++){
        arr_time[i] = 0;
    }
    for (i = 0 ; i < n; i++){
        for (j = arr[i][0] ; j <= arr[i][1];j++){
            arr_time[j]++;
        }
    }
    int max_time = 0;

     for (i = 0 ; i < max_range; i++){
        if (arr_time[i] > max_time){
            max_time = arr_time[i];
        }
    }
    printf("%d",max_time);
    
}
