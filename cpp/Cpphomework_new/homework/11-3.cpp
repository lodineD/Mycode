#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> qu;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        qu.push(m);
    }
    qu.pop();
    qu.pop();
    qu.push(11);
    qu.push(12);
    int temp = 0;
    while (!qu.empty())
    {
        temp == 0 ? cout << qu.front() : cout << " " << qu.front();
        qu.pop();
        temp++;
    }
    return 0;
}