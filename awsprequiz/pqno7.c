#include <stdio.h>

int main(){

    int r,c;
    scanf("%d %d",&r,&c);
    int arr[r][c];
    int i,j,k;
    for (i = 0 ; i < r;i++){
        for (j = 0 ; j < c;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int range;
    scanf("%d",&range);
    int s_value[range];
    for (i = 0 ; i < range ;i++){
        scanf("%d",&s_value[i]);
    }
    for (i = 0 ; i < r ; i++){
        for (j = 0 ; j < c ; j++){
            int f = 0;
            for (k = 0 ; k < range ; k++){
                if (arr[i][j] == s_value[k]){
                    printf("(%d) ",arr[i][j]);
                    f = 1;
                }
            }
            if (!f){
                printf("%d " ,arr[i][j]);
            }
        }
        printf("\n");
    }
}