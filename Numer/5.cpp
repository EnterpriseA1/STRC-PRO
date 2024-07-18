#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;


double f(double x,double value,int n){
    return  pow(x,n) - value;
}
double secantLine(double xl , double xr,double value,int n){
    return (xl*(f(xr,value,n)) - xr*(f(xl,value,n)))/(f(xr,value,n) - f(xl,value,n));
}

int main(){
    double x = 13,n = 4;
    double xl = 0.0,xr= 1000000.0;
    cout<<"xl = "<<xl<<" | xr = "<<xr<<endl;
    double c, temp;
    double tolerance = 1;
    
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
        cout<<c<<endl;
    }while (abs(f(c,x,n)) > tolerance);         // abs((c - temp)/c)*100 < tolerance;
    cout<<"Result : "<<std::fixed<<std::setprecision(4)<<c<<'\n';

}