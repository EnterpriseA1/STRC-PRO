#include <iostream>
#include <math.h>


int factorial(int i){
    if(i == 0){
        return 1;
    }else{
        return i * factorial(i-1);
    }
}
double taylor(double x, double x0, int i){
    return pow(x-x0, i)/factorial(i);
}
double f1(double x){
    return 1/x;
}
double f2(double x){
    return (-1/pow(x, 2));
}
double f3(double x){
    return 2/pow(x, 3);
}

int main(){
    double x = 4, x0 = 2, a = 0, temp, ta = 1.386294;
    int i;
    for (i = 0; i < 4; i++)
    {
        switch (i)
        {
        case 1: temp = taylor(x,x0,i) * f1(x0);
            break;
        case 2: temp = taylor(x,x0,i) * f2(x0);
            break;
        case 3: temp = taylor(x,x0,i) * f3(x0);
            break;
        default: temp = 0.693147;
            break;
        }

        a += temp;
        printf("N%d = %.6lf\n",i,a);
        printf("Error%d = %.6lf\n",i,abs(ta-a));
    }
}