#include <iostream>
using namespace std;

int A;
int ans = 0;                                //所需硬币总数
int ret[6] = {0};                           //所需每种硬币的数量
int moneycnt[6];                            //现有6种硬币的数量
int moneyval[6] = {1, 5, 10, 50, 100, 500}; //每种硬币的面值

int main()
{
    cin >> A;
    for (int i; i < 1; i++)
    {
        cout << A <<endl;
    } 
}