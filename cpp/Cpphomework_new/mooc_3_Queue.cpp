#include <iostream>
#include <queue>

using namespace std;
queue<int> Q;

int main()
{
    Q.push(1);
    Q.push(2);
    Q.push(3);
    cout << "元素个数" << Q.size() << endl;
    int a = Q.back();  // 返回最后一个
    int b = Q.front(); // 返回第一个
    cout << a << " " << b << endl;
    Q.pop(); // 删除第一个元素
    a = Q.front();
    cout << a << endl;
    while (!Q.empty())
    {
        cout << Q.front() << " ";
        Q.pop();
    }
    cout << endl;
    // 队列和stack一样没有迭代器,只能不断删除
    cout << Q.size() << endl;
}