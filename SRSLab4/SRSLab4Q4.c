#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int *arr = malloc(n * sizeof(int));
    int i,j;
    for (i = 1; i<= n; i++){
        arr[i-1] = i;
    }
    for (j = 0; j < n ;j++){
        for (i = 0; i < n; i++){
            printf("%d ",arr[(i+j) % n]);
    }
    printf("\n");
    }
    printf("test");
}