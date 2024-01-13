#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int max = -999999,i;
    for (i = 0 ; i < n ; i++){
        int val;
        scanf("%d",&val);
        if (val > max){
            max = val;
        }
    }
    printf("%d",max);   
}