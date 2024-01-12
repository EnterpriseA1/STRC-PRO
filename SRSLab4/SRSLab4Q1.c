#include <stdio.h>

int main(){
    int n;
    char x = '*';
    scanf("%d",&n);
    if (n % 2 == 0){
        int start = 0;
        int i;
        for (start = 0; start < n / 2; start++){
            for (i = 0 ; i < 2*(start + 1);i++){
                printf("%c",x);
            }
            printf("\n");
        }
        for (start = (n / 2) - 1;start > 0; start--){
            for (i = 0 ; i < 2*start; i++){
                 printf("%c",x);
            }
            printf("\n");
        }
    }
    else{
        int start = 0;
        int i;
        int temp = (n+1) / 2;
        for (start = 0 ; start < temp; start++){
            for (i = 0 ; i < (2*start) + 1;i++){
                printf("%c",x);
                
            }
            printf("\n");
        }
        for (start = temp - 1;start > 0; start--){
            for (i = 0 ; i < (2*start) - 1; i++){
                 printf("%c",x);
            }
            printf("\n");
        }
    }
}