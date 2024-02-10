#include <stdio.h>
#include <math.h>

int sum_digit(int, int );

int main(){
    int x;
    scanf("%d", &x);
    int digit = 1;
    int find_digit = 10;
    while (find_digit <= x){
        find_digit *= 10;
        digit++;
    }
    int total_sum = sum_digit(x,digit);
    printf("%d", total_sum);
}
int sum_digit(int n , int digit){
    if (digit == 1){
        return n;
    }
    else{
        return n % 10 + sum_digit(n / 10, digit - 1);
    }
}