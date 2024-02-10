#include <stdio.h>
#include <math.h>

int reverse(int,int);

int main(){
    int n;
    scanf("%d",&n);
    int digit = 1;
    int find_digit = 10;
    while (find_digit <= n){
        find_digit*=10;
        digit++;
    }
    int rev = reverse(n,digit);
    printf("%d",rev);
    

}

int reverse(int num,int digit){
    if (digit == 1){
        return num;
    }
    return (num % 10) * pow(10,digit - 1) + reverse(num / 10, digit - 1);
    
}