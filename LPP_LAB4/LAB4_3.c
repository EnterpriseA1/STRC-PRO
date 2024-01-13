#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,dest;
    int count = 0;
    scanf("%d %d",&n,&dest);
    int *arr = malloc(n*sizeof(int));
    int i,j;
    for(i = 0;i<n;i++){
        int val;
        scanf("%d",&val);
        arr[i] = val;
    }
    for(i = 0;i<n;i++){
        for(j= i + 1;j< n;j++){
            if ((arr[i] + arr[j]) == dest){
                count++;
            }
        }
    }
    printf("%d",(count) ? count : -1);
}