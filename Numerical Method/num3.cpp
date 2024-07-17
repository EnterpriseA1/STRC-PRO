#include <iostream>
#include <math.h>
using namespace std;
double func(double, double, double);
void bisection(double, double, double, double);

int main()
{
    double x, n;
    cin >> x >> n;
    bisection(0, 1e+6, x, n);
    return 0;
}

double func(double x, double power, double base)
{
    return pow(x, power) - base;
}

void bisection(double left, double right, double x, double power)
{
    if (func(left, power, x) * func(right, power, x) >= 0)
    {
        cout << "Error";
        return;
    }
    double mid;
    while (right - left >= 1e-9)
    {
        if (func(mid, power, x) == 0)
        {
            break;
        }
        else if (func(left, power, x) * func(mid, power, x) < 0)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
        mid = (left + right) / 2.0;
    }
    printf("%.4lf", mid);
}
