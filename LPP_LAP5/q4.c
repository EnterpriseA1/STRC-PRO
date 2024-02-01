#include <stdio.h>
#include <math.h>


int main(){

    int n;
    scanf("%d",&n);
    int i,j,k;
    for (i = 0 ; i < n ; i++){
        int num;
        int sum_ = 0;
        scanf("%d",&num);
        int temp = num;
        int find_digit = 10;
        int digit = 1;
        while (find_digit <= num + 1){
            find_digit *= 10;
            digit++;
        }
        int m_digit = digit;
        int amp = pow(10,digit - 1);
        
        while (temp > 0){
            int current_digit = temp / amp;
            sum_ += pow(current_digit,m_digit);
            temp -= current_digit * amp;
            amp /= 10;
            }
        if (sum_ == num){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    
}