#include <stdio.h>



int main(){

    int n;
    scanf("%d",&n);
    int arr[n][n - 1];
    int i,j;
    for (i = 0 ; i < n ; i++){
        for (j = 0 ; j < n - 1 ; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int max = 0,p = 0;
    for (i = 0 ; i < n ;i++){
        int sum_  = 0;
        for (j = 0 ; j < n - 1;j++){
            sum_ += arr[i][j];
        }
        if (sum_ > max){

             max = sum_;
             p = i + 1;
        }
    }
    printf("%d %d",p,max);
}