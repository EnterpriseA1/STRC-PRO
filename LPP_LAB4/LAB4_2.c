#include <stdio.h>
#include <stdlib.h>

void sorted(int *arr,int length){
    int i,j;
    for (i = 0 ; i < length; i++){
        for(j=i+1;j < length; j++){
            if (arr[i] > arr[j]){
                int temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    int i;
    for (i = 0 ; i < n ; i++){
        int val;
        scanf("%d",&val);
        arr[i] = val;
    }
    sorted(arr,n);
    int count = 1;
    int max_count = 1;
    int max_int = 0;
    for (i = 0 ; i < n ;i++){
        printf("%d : COUNT %d : MAXINT\n",count,max_int);
        if (i == n - 1){
            if (count > max_count){
                max_count = count;
                max_int = arr[i];
                }
        }
        else {
            if (arr[i] == arr[i+1]){
                 count++;
            }
            else {
                if (count > max_count){
                    max_count = count;
                    max_int=arr[i];
                    }
                count = 1;

            }
        }
    }
    printf("%d",max_int);
}
