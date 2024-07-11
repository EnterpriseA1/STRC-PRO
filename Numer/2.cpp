#include <iostream>
#include <math.h>


using namespace std;
double round_(double n){
    double t1 = n * pow(10, 6);
    int t2 = static_cast<int>(t1);
    n = t2 / pow(10, 6);
    return n;
}

double fifo (double *x, double *y,double final){
    double result = (*x+*y)/2;
    if (result < final){
        *x = result;
    }
    else{
        *y = result;
    }
    return result;
}

int main (){
    double a1,a2,x=1.5,y=2.0,answer;
    int i;

    answer = sqrt(sqrt(13));

    answer = round_(answer);

    printf("answer = %lf\n",answer);

    for(i=0;i<4;i++){
        a1 = fifo(&x,&y,answer);
    }
    printf("a1 = %lf\n",a1);


    do{
        a2 = round_(fifo(&x,&y,answer));
    }while (a2 != answer);
    printf("a2 = %.6lf",a2);
}