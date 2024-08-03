#include <iostream>
#include <math.h>
#include <iomanip>
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
    return std::pow(x, 4.0) - 13;
}

void falsePosition(double left, double right)
{
    if (func(left) * func(right) > 0) // left < x < right (it should be opposite sign)
    {
        std::cout << "Error";
        return;
    }
    double c;
    int i = 0;
    do
    {
        c = (((left * func(right)) - (right * func(left)))) / ((func(right) - func(left)));
        if (i <= 4)
        {
            std::cout << std::fixed << std::setprecision(6) << "iteration " << i
                      << "\tLeft : " << left << " \tRight : " << right << "\tC : " << c << "\t f(c) : " << func(c) << std::endl;
            i++;
        }
        if (func(c) == 0.0)
        {
            break;
        }
        else if (func(c) * func(right) > 0)
        {
            right = c;
        }
        else
        {
            left = c;
        }
    } while (abs(func(c)) > 1e-6);
    std::cout << std::fixed << std::setprecision(6) << c;
}