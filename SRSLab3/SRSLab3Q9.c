#include <stdio.h>

void sort_array(int arr[]){
    int size = 3;
    int i,j;
    for (i = 0; i < size; i++){
        for (j = i+1; j < size; j++){
            if (arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        } 
    }
}

void re_order(int arr[],char y[]){
    int size = 3;
    int i;
    for(i = 0; i < size; i++){
        printf("%d ",arr[y[i]-'A']);
    }
}

int main(){
    int arr[3] = {0};
    int i;
    for (i = 0;i<3;i++){
        scanf("%d",&arr[i]);
    }
    char order[4];
    scanf("%s",order);
    sort_array(arr);
    re_order(arr,order);
}