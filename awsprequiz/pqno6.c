#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int i;
    int arr[n];
    for (i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }
    int value;
    scanf("%d",&value);
    for (i = 0 ; i < n ; i++){
        if (arr[i] == value){
            printf("(%d) ",arr[i]);
        }
        else{
            printf("%d ",arr[i]);
        }
    }
}