#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    int i;
    for (i = 0 ; i < n;i++){
        scanf("%d",&arr[i]);
    }
    int val;
    scanf("%d",&val);
    for (i = 0 ; i < n ; i++){
        if (arr[i] > val){
            printf("%d ",i + 1);
        }
    }
}