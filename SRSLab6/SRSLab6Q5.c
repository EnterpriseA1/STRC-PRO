#include <stdio.h>

int main(void){
    int N,M,L,K,C,amount = 1,total_electricity = 0;
    int array[100][100] = {0} ;
    scanf("%d%d%d%d%d",&N,&M,&L,&K,&C); 
    for(int i = 0;i < N;i++){
       for(int j = 0;j < M;j++){
          scanf("%d" ,&array[i][j]);
          total_electricity += array[i][j];
       }
    }   
    int fuel_consume = L*K*C;
    int finalconsumtion = total_electricity + fuel_consume;
    while(C * amount < finalconsumtion){
       amount++;
    }
    printf("%d",amount);
}