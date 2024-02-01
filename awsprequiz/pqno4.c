#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    int arr_[n];
    int i;
    for (i = 0 ; i < n;i++){
        scanf("%d",&arr[i]);
    }
    for (i = 0 ; i < n;i++){
        scanf("%d",&arr_[i]);
    }
    for (i = 0 ; i < n;i++){
        printf("%d ",arr[i]+arr_[i]);
    }
}