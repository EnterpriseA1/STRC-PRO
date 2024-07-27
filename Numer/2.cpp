#include <iostream>
#include <math.h>
using namespace std;


double f(double x,double value,int n){
    return  pow(x,n) - value;
}
double secantLine(double xl , double xr){
    return (xl+xr)/2;
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
    double x = 13,n = 4;
    double xl = 1.5,xr = 2.0;
    cout<<"xl = "<<xl<<" | xr = "<<xr<<endl;
    double c, temp;
    double tolerance = 1e-7;
    
    do{
        c = secantLine(xl,xr);
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