#include <iostream>
#include <iomanip>
#include <cmath>
double g(double);
int main()
{
	double x1;
	double x2 = 0;
	int i = 0;
	do
	{
		x1 = x2;
		x2 = g(x1);
		if (g(x1) == 1)
		{
			continue;
		}
		else
		{
			std::cout << "x" << i << " = " << std::fixed << std::setprecision(6) << x2 << std::endl;
			i++;
		}

	} while (std::abs(x2 - x1) > 1e-5);
	return 0;
}

double g(double x)
{
	if (x == 0)
	{
		return 1;
	}
	else
	{
		return (((7 / x) + x) / 2);
	}
	//    return 2.0 - exp(x / 4.0);
}
