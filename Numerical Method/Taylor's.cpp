#include <iostream>
#include <iomanip>
#include <cmath>
double taylor(double, double, int);
double funcD1(double);
double funcD2(double);
double funcD3(double);
int fact(int);

int main()
{
    double x = 4;
    double x0 = 2;
    double temp = 0, ans = 0;
    double answer = std::log(x);
    int i = 0;

    for (i = 0; i < 4; i++)
    {
        switch (i)
        {
        case 1:
            temp = taylor(x, x0, i) * funcD1(x0);
            break;
        case 2:
            temp = taylor(x, x0, i) * funcD2(x0);
            break;
        case 3:
            temp = taylor(x, x0, i) * funcD3(x0);
            break;
        default:
            temp = std::log(x0);
            break;
        }
        ans += temp;
        std::cout << "N" << i << " = " << std::fixed << std::setprecision(6) << ans;
        std::cout << ", Error = " << std::fixed << std::setprecision(6) << std::abs(answer - ans) << std::endl;
    }
}

double taylor(double x, double x0, int i)
{
    return std::pow(x - x0, i) / fact(i);
}
double funcD1(double x)
{
    return 1 / x;
}
double funcD2(double x)
{
    return -1 / std::pow(x, 2.0);
}

double funcD3(double x)
{
    return 2 / std::pow(x, 3.0);
}

int fact(int n)
{
    if (n == 1)
        return 1;
    else
        return n * fact(n - 1);
}
