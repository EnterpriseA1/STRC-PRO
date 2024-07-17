#include <iostream>
using namespace std;
int main()
{
    double x = 0;
    while (43 * x - 180 <=   0)
    {
        x++;
    }
    double z = x;
    double y = z - 1;
    x = y;

    while (43 * x - 180 <= 0)
    {
        x = x + 0.000001;
    }

    cout << "x = " << x << endl;
    return 0;
}