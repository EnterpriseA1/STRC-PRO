#include <stdio.h>



int main(){

    int n;
    scanf("%d",&n);
    int count = 1;
    int find_digit = 10;
    while (find_digit < n + 1){
        find_digit *= 10;
        count++;
    }
    printf("%d",count);
    
}