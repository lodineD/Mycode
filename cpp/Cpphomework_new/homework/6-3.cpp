#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string s;
    cin >> s;
    char c[100];
    strcpy(c, s.c_str());
    int n1 = 0;
    int n2;
    int len = strlen(c);
    for (n2 = 3; n2 <= len; n2++)
    {
        if ((len + 2 - n2) % 2 == 0)
        {
            n1 = (len + 2 - n2) / 2;
        }
        if (n1 <= n2 && n1 != 0)
        {
            break;
        }
        else
        {
            n1 = 0;
            continue;
        }
    }
    for (int i = 0; i < n1 - 1; i++)
    {
        cout << c[i];
        for (int j = 0; j < len - 2 * n1; j++)
        {
            cout << " ";
        }
        cout << c[len - 1 - i] << endl;
    }
    for (int i = n1 - 1; i < len - n1 + 1; i++)
    {
        cout << c[i];
    }
}