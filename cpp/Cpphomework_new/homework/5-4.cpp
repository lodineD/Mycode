#include <iostream>
#include <iomanip>
#include <map>

using namespace std;
map<int, double> m;

void inm(int line, int n)
{
    for (int i = 0; i < line; i++)
    {
        int key;
        double val;
        cin >> key >> val;
        m[key] = val + m[key];
        if (n == 2 && m[key] == 0)
        {
            m.erase(key);
        }
    }
}

int main()
{
    int line;
    cin >> line;
    inm(line, 1);
    cin >> line;
    inm(line, 2);
    cout << m.size();
    for (auto i = m.rbegin(); i != m.rend(); i++)
    {
        if (i->second != 0)
        {
            cout << " " << fixed << setprecision(1) << i->first << ' ' << i->second;
        }
    }
}