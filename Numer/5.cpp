#include <iostream>
#include <math.h>


double f(double x,double value,int n){
    return  pow(x,n) - value;
}
double secantLine(double xl , double xr,double value,int n){
    return (xl*(f(xr,value,n)) - xr*(f(xl,value,n)))/(f(xr,value,n) - f(xl,value,n));
}

int main(){
    double x = 13,n = 4;
    double xl = 1.5,xr= 2.0;
    double c, temp;
    double tolerance = 1e-6;
    
    do{
        c = secantLine(xl,xr,x,n);
        if(f(c,x,n) > 0){
            temp = xr;
            xr = c;
        }
        else{
            temp = xl;
            xl = c;
        }
    }while (abs(f(c,x,n)) > tolerance);         // abs((c - temp)/c)*100 < tolerance;
    printf("Result : %.6lf\n",c);

}