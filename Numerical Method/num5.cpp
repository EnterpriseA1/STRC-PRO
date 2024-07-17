#include <iostream>
using namespace std;
double func(double);
void falsePosition(double, double);
int main()
{
    double left = 1.5;
    double right = 2.0;
    falsePosition(left, right);
}
double func(double x)
{
    return x * x * x * x - 13;
}

void falsePosition(double left, double right)
{
    if (func(left) * func(right) > 0)
    {
        cout << "Error";
        return;
    }
    double c;
    while (func(left) * func(right) < 0)
    {
        c = (left * func(right) - right * func(left)) / (func(right) - func(left));
        if (func(c) == 0.0)
        {
            break;
        }
        else if (func(left) * func(c) < 0)
        {
            right = c;
        }
        else
        {
            left = c;
        }
    }
    cout << c;
}