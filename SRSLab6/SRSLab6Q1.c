#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double average (int *arr,int size);
int main(){
    int n;
    scanf("%d",&n);
    int *arr = malloc(sizeof (int) * n);
    int i;
    for (i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }
    double divider = 0;
    double avg = average(arr,n);
    for (i = 0 ; i < n ; i++){
        divider += pow(arr[i] - avg,2);
    }
    printf("%.2f",sqrt(divider / (n - 1)));

}

double average (int *arr,int size){
    double result = 0;
    double sum = 0;
    int i;
    for (i = 0 ; i < size;i++){
        sum += arr[i];
    }
    result = sum / size;
    return result;
}