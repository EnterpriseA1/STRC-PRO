// Integer Version
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
// String Version

#include <stdio.h>
#include <string.h>
#include <math.h>
#include<stdlib.h>
int main()
{
    char st[7];
    int i, a ,j;
    scanf("%d", &a);
    for (int i = 0; i < a; i++)
    {
        scanf("%s", st);
        int sum =0,var=0;
        for (j = 0; j < strlen(st); j++)
        {
            int f;

            f = st[j] - '0';
            sum = sum + pow(f, strlen(st)) ;
        }
        var = atoi(st);
        if (sum == var){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }

}
