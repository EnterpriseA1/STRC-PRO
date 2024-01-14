#include <stdio.h>
#include <stdlib.h>

int main(){
    int summation = 0;
    int arr[7] = {0};
    int i;
    for (i = 0 ; i < 7;i++){
        int amount;
        scanf("%d",&amount);
        summation += amount;
    }
    int first_half = 0;
    int second_half = 0;
    int sum_price = 0;
    int unit = 1;
    int s_price = 80;
    while (unit <= summation){
        if (unit > 100 && unit < 250){
            s_price = 70;
        }
        else if (unit > 250){
            s_price = 60;
        }
        sum_price += s_price;
        unit++;
    }
    int income = 100 * summation;
    int outcome = income - sum_price;
    printf("%d\n",sum_price);
    printf("%d\n",income);
    printf("%d",outcome);
}