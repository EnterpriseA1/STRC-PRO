#include <iostream>
#include <math.h>
using namespace std;


double f(double x,double value,int n){
    return  pow(x,n) - value;
}
double secantLine(double xl , double xr,double value,int n){
    return (xl*(f(xr,value,n)) - xr*(f(xl,value,n)))/(f(xr,value,n) - f(xl,value,n));
}

void setInterval(double *xl, double *xr, double value, int n) {
    *xl = 0;
    *xr = 1;
    while (f(*xr, value, n) <= 0) {
        (*xr)++;
    }
    *xl = *xr - 1;
}

int main(){
    double x,n;
    cin>>x>>n;
    double xl,xr;
    setInterval(&xl, &xr, x, n);
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
    printf("Result : %.4lf\n",c);

}