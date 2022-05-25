#include <iostream>

using namespace std;

typedef struct student
{
    int Id;
    string name;
    int s;
} st;

int main()
{
    int n;
    cin >> n;
    st s[100];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].Id >> s[i].name >> s[i].s;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (s[j].s < s[j + 1].s)
            {
                st k;
                k = s[j];
                s[j] = s[j + 1];
                s[j + 1] = k;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << s[i].Id << " " << s[i].name << " " << s[i].s << endl;
    }
    return 0;
}