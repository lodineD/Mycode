#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    double sum = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        sum = pow(-1, i) / (2 * i + 1) + sum;
    }
    cout << fixed
         << setprecision(6) << sum * 4;
}