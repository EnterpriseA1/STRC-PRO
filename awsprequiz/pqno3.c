#include <stdio.h>

int main(){
    int r,c;
    scanf("%d %d",&r,&c);
    int arr[r][c];
    int i,j,k;
    for (i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int range;
    scanf("%d",&range);
    for (i = 0 ; i < range ;i++){
        int val;
        int f = 0;
        scanf("%d",&val);
        for (j = 0; j < r;j++){
            for (k = 0; k < c; k++){
                if (arr[j][k] > val){
                    printf("%d ",arr[j][k]);
                    f = 1;
                }
            }
        }
        if (!f){
            printf("%d",0);
        }
        printf("\n");
    }
}