#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

// struct cmp
// {
//     int a, b;
//     bool operator < (int x, int y)
//     {
//         return x > y;
//     }
// };

struct node
{
    int a, b;
    friend bool operator<(node x, node y)
    {
        return x.a > y.a; //结构体中a小的优先级高
    }
};

int main()
{
    priority_queue<int> p; // 默认从大到小
    p.push(10);
    p.push(30);
    p.push(20);
    cout << p.size() << endl;
    while (!p.empty())
    {
        cout << p.top() << " ";
        p.pop();
    }
    priority_queue<int, vector<int>, greater<int>> q; // 从小到大
    q.push(10);
    q.push(30);
    q.push(20);
    
    cout << q.size() << endl;
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
    return 0;
}