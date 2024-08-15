#include <iostream>
#include <iomanip>
#include <cmath>
double func(double);
double deriv(double);
double newton(double);
int main()
{
    double x0 = 2.0;
    std::cout << std::fixed << std::setprecision(6) << newton(x0);
    return 0;
}
double newton(double x)
{
    double temp;
    double Dx;
    int i = 0;
    do
    {
        temp = x;
        Dx = -(func(x) / deriv(x));
        x = x + Dx;
        std::cout << "iteration #" << i << " :\t";
        std::cout << std::fixed << std::setprecision(6) << "x(" << i << ") = " << temp
                  << ", x(" << i + 1 << ") = " << std::fixed << std::setprecision(6) << x
                  << ", Error = " << std::fixed << std::setprecision(6) << std::abs(Dx / x)
                  << std::endl;
        i++;

    } while (std::abs(Dx / x) > 1e-6); // while (std::abs(x - temp) > 1e-6);
    return x;
}

double func(double x)
{
    // return exp(-x / 4) * (2 - x) - 1;
    return pow(x, 2.0) - 7.0;
}
double deriv(double x)
{
    // return -exp(-x / 4) * (1.5 - x / 4);
    return 2.0 * x;
}