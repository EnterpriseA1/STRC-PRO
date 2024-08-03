#include <iostream>
#include <iomanip>
#include <math.h>
double func(double, double, double);
void bisection(double, double, double, double);

int main()
{
    double x, n;
    std::cin >> x >> n;
    bisection(0, 1e+6, x, n);
    return 0;
}

double func(double x, double power, double base)
{
    return std::pow(x, power) - base;
}

void bisection(double left, double right, double x, double power)
{
    if (func(left, power, x) * func(right, power, x) > 0)
    {
        std::cout << "Error";
        return;
    }
    double mid = (left + right) / 2.0;
    do
    {
        mid = (left + right) / 2.0;
        if (func(mid, power, x) == 0.0)
        {
            break;
        }
        else if (func(mid, power, x) * func(right, power, x) > 0)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    } while (abs(func(mid, power, x)) > 1e-6);
    std::cout << std::fixed << std::setprecision(4) << mid;
}
