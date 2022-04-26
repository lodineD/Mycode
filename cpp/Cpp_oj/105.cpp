#include <iostream>
#include <bitset>
using namespace std;

const int max_number = 100000000;
bitset<max_number + 1> s;

int main()
{
    int k;
    cin >> k;
    for (int i = 1; i < max_number + 1; ++i)
    {
        s.set(i, 1);
    }
    s[1] = 0;
    for (int i = 1; i != max_number; ++i)
    {
        if (s[i])
        {
            for (int j = i * 2; j < max_number + 1; j += i)
            {
                s[j] = 0;
            }
        }
    }
    int num = 0;
    int m = 1;
    for (; m != max_number; ++m)
    {
        if (s[m] == 1)
        {
            num++;
        }
        if (num == k)
        {
            break;
        }
    }
    cout << m;
}