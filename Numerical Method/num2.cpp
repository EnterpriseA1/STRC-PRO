#include <iostream>
using namespace std;
double func(double);
void bisection(double, double);
int main()
{
    double left = 1.5;
    double right = 2.0;
    bisection(left, right);
}
double func(double x)
{
    return x * x * x * x - 13;
}

void bisection(double left, double right)
{
    if (func(left) * func(right) > 0)
    {
        cout << "Error";
        return;
    }
    double mid;
    while (func(left) * func(right) < 0)
    {
        mid = (left + right) / 2.0;
        if (func(mid) == 0.0)
        {
            break;
        }
        else if (func(left) * func(mid) < 0)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    cout << mid;
}