#include <iostream>
#include <math.h>
#include <iomanip>
double func(double, double, double);
void falsePosition(double, double, double, double);
void setInterval(double *, double *, double, double);

int main()
{
    double x, n;
    double left;
    double right;
    std::cin >> x >> n;
    setInterval(&left, &right, x, n);
    falsePosition(left, right, x, n);
}

double func(double x, double n, double base)
{
    return std::pow(x, n) - base;
}

void setInterval(double *left, double *right, double x, double n)
{
    *left = 0;
    *right = 1;
    while (func(*right, n, x) <= 0)
    {
        (*right) += 1;
    }
}

void falsePosition(double left, double right, double x, double power)
{
    if (func(left, power, x) * func(right, power, x) > 0)
    {
        std::cout << "Error" << std::endl;
        return;
    }
    double c;
    do
    {
        c = (((left * func(right, power, x)) - (right * func(left, power, x)))) / ((func(right, power, x) - func(left, power, x)));
        if (func(c, power, x) == 0.0)
        {
            break;
        }
        else if (func(c, power, x) * func(right, power, x) > 0)
        {
            right = c;
        }
        else
        {
            left = c;
        }
    } while (abs(func(c, power, x)) > 1e-6);
    std::cout << std::fixed << std::setprecision(4) << c;
}