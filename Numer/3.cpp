#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;


double f(double x,double value,int n){
    return  pow(x,n) - value;
}
double secantLine(double xl , double xr){
    return (xl+xr)/2;
}

int main(){
    double x,n;
    cin>>x>>n;
    double xl = 0.0,xr= 1000000.0;
    double c, temp;
    double tolerance = 1e-4;
    
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
        cout<<c<<endl;
    }while (abs(f(c,x,n)) > tolerance);         // abs((c - temp)/c)*100 < tolerance;
    cout<<"Result : "<<std::fixed<<std::setprecision(4)<<c<<'\n';

}