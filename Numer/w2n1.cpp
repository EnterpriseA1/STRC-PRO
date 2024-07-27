#include <iostream>
#include <math.h>


double f(double n,int x){
    return  (x/n);
}

int main(){
    double x = 7, n1 = 0, n2;
    double tolerance = 1e-4;
    int i;

    do{
        n2 = n1;
        n1 = f(n2, x);
        printf("Result : %.6lf\n",n1);
    }while (abs(n1 - n2) > tolerance);
    printf("Result : %.6lf\n",n1);

}