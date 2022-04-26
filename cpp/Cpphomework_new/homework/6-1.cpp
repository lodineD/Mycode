#include <iostream>

using namespace std;

int main()
{
    int N, flag = 1;
    int a[7000];
    cin >> N;
    int num = N;
    int num2 = 0;
    int num3 = 0;
    for (int i = 0; i < 7000; i++)
    {
        a[i] = 0;
    }
    while (num > 3)
    {
        if (flag == 1)
        {
            for (int j = 0; j < N; j++)
            {
                if (a[j] == 1)
                {
                    continue;
                }
                num2++;
                if (num2 % 2 == 0)
                {
                    a[j] = 1;
                    num--;
                }
            }
            flag = 0;
            num2 = 0;
        }
        else if (flag == 0)
        {
            for (int j = 0; j < N; j++)
            {
                if (a[j] == 1)
                {
                    continue;
                }
                num3++;
                if (num3 % 3 == 0)
                {
                    a[j] = 1;
                    num--;
                }
            }
            flag = 1;
            num3 = 0;
        }
    }
    int pre = 0;
    for (int j = 0; j < N; j++)
    {
        if (a[j] == 0 && pre == 0)
        {
            cout << j + 1;
            pre++;
        }
        else if (a[j] == 0 && pre != 0)
        {
            cout << " " << j + 1;
        }
    }
}