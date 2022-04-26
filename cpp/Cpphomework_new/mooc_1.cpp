#include <iostream>
#include <iomanip>
#include <map>

using namespace std;
map<int, double> m;

void inm(int line, int n)
{
    int key, val;
    for (int i = 0; i < n; i++)
    {
        cin >> key >> val;
        m[key] = val + m[key];
        if (m[key] == 0 && n == 2)
        {
            m.erase(key);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    inm(n, 1);
    cin >> n;
    inm(n, 2);
    
}