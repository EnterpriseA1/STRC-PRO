#include <iostream>

int main (){
    int y,z;
    double x=0.0;
    while ((43*x)-180 <=0)
    {
        x++;
    }

    y=x-1;
    z=x;
    x=y;
    
    while ((43*x)-180 <=0)
    {
        x+=0.000001;
    }
    printf("Range : [%d,%d]\nAnswer : %.6lf",y,z,x);
}