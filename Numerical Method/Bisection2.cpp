#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
double func(double);
void bisection(double, double);
int main()
{
    double left = -3.0;
    double right = 0.0;
    bisection(left, right);
}
double func(double x)
{
    return std::pow(x, 4.0) - 13;
}

void bisection(double left, double right)
{
    if (func(left) * func(right) > 0) // left < x < right (it should be opposite sign)
    {
        cout << "Error";
        return;
    }
    double mid = (left + right) / 2.0;
    int i = 0;
    do
    {
        mid = (left + right) / 2.0;
        if (i <= 4)
        {
            cout << std::fixed << std::setprecision(6) << "iteration " << i
                 << "\tLeft : " << left << " \tRight : " << right << "\tMid : " << mid << "\t f(mid) : " << func(mid) << endl;
            i++;
        }
        if (func(mid) == 0.0)
        {
            break;
        }
        else if (func(mid) * func(right) > 0)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    } while (abs(func(mid)) > 1e-6);
    cout << std::fixed << std::setprecision(6) << mid;
}