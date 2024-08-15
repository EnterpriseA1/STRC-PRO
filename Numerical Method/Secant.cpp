#include <iostream>
#include <iomanip>
#include <cmath>
double func(double);
double secant(double, double);
double deriv(double x, double xOld);
int main()
{
    double x = 3.0;
    double xOld = 2.0;
    std::cout << std::fixed << std::setprecision(6) << secant(x, xOld);
    return 0;
}

double secant(double x, double xOld)
{
    double dx;
    int i = 0;
    do
    {
        dx = deriv(x, xOld);
        xOld = x;
        x = x + dx;
        std::cout << "iteration #" << i << " :\t";
        std::cout << "x(" << i << ") = " << std::fixed << std::setprecision(6) << xOld
                  << ", x(" << i + 1 << ") = " << std::fixed << std::setprecision(6) << x
                  << ", Error = " << std::fixed << std::setprecision(6) << std::abs(x - xOld)
                  << std::endl;
        i++;
    } while (std::abs(x - xOld) > 1e-6);
    return x;
}

double deriv(double x, double xOld)
{
    return -((func(x) * (xOld - x)) / (func(xOld) - func(x)));
}

double func(double x)
{
    // return exp(-x / 4.0) * (2.0 - x) - 1.0;
    return pow(x, 2.0) - 7.0;
}