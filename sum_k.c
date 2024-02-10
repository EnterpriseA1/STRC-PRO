#include <stdio.h>

void sum_k(int *,int,int,int,int);

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    int i;
    for (i = 0 ; i < n ;i++){
        scanf("%d",&arr[i]);
    }
    sum_k(arr,0,0,k,n);
}

void sum_k(int *arr,int i,int j,int k,int n){
    if (i == n && j == n){
        printf("%d",-1);
        return;
    }
    if (i < n && j == n){
        i++;
        j=0;
    }
    if (arr[i] + arr[j] == k){
        printf("%d %d\n",i + 1,j + 1);
        return;
    }
    sum_k(arr,i,j+1,k,n);
}