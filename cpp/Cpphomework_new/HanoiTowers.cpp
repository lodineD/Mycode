#include <iostream>

using namespace std;

class Hanoi
{
public:
    void HanoiTowers(int n, char a, char b, char c);
    void Move(int n, char s, char t);
};

void Hanoi::HanoiTowers(int n, char a, char b, char c)
{
    if (n == 1)
    {
        Move(1, a, b);
    }
    else
    {
        HanoiTowers(n - 1, a, c, b);
        Move(n, a, b);
        HanoiTowers(n - 1, c, b, a);
    }
}

void Hanoi::Move(int n, char s, char t)
{
    cout << "将圆盘" << n << "从塔座" << s << "移动到塔座" << t << endl;
}

int main()
{
    Hanoi H;
    H.HanoiTowers(4, 'A', 'B', 'C');
}