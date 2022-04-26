#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s[100];
    string s2;
    int num = 0;
    while (cin >> s2)
    {
        s[num] = s2;
        num++;
        if (cin.get() == '\n')
        {
            break;
        }
    }
    string max = s[0];
    for (int i = 1; i < num; i++)
    {
        if (max.size() < s[i].size())
        {
            max = s[i];
        }
    }
    cout << max;
}