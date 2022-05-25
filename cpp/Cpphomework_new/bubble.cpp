#include <iostream>

using namespace std;

int main()
{
    int a[100];
    int n;
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = 0; j < 10 - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int k;
                k = a[j];
                a[j] = a[j + 1];
                a[j + 1] = k;
            }
            // int k;
            // k = a[j];
            // a[j] = a[j + 1];
            // a[j + 1] = k;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        cout << a[i];
    }
    return 0;
}