#include <stdio.h>


void dec_to_bin(int n,char *x,int length);

int main(){
    int n;
    scanf("%d", &n);
    int find_length = n;
    int length = 1;
    while (find_length / 2 > 0){
        length++;
        find_length /= 2;
    }
    char x[length + 1];
    int i;
    x[0] = '0';
    for (i = 1 ; i <= length ; i++){
        x[i] = '\0';
    }
    dec_to_bin(n,x,length);
    printf("%s",x);
}

void dec_to_bin(int n,char *x,int length){
    if (n <= 0){
        return;
    }
    x[--length] = (n % 2) + '0';
    dec_to_bin(n / 2,x,length);
}