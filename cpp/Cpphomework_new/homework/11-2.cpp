#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        if (s[i] == ')')
        {
            st.pop();
        }
    }
    if (st.empty())
    {
        cout << "括号匹配！" << endl;
    }
    else
    {
        cout << "括号不匹配！" << endl;
    }
    return 0;
}