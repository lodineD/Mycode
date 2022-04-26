#include <iostream>

using namespace std;

int n;
int c[10005] = {0};

int lowbit(int x)
{
    return x & -x;
}

void updata(int i, int k) // 原数组i位置上加k
{
    while (i <= 9)
    {
        c[i] += k;
        i += lowbit(i);
    }
}

int getsum(int i) // 求A[1]`A[i]的和
{
    int res = 0;
    while (i > 0)
    {
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}

int main()
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int C[10];
    for (int i = 1; i < 10; i++)
    {
        updata(i, a[i]);
    }
    // for (int i = 1; i < 10; i++)
    // {
    //     cout << c[i];
    // }
    // C[1] = A[1];
    // C[2] = A[1] + A[2];
    // C[3] = A[3];
    // C[i] = A[i - pow(2, k) + 1] + 1]  + A[i - pow(2, k) + 2]+ ```` + A[i];
    // 其中K是i转换为二进制后从最低位高位连续零的个数
    // 例：i = 8（1000），则k = 3;
    // C[4] = A[1] + A[2] + A[3] + A[4];

    // 求A中前7项的和
    // int sum = C[7] + C[6] + C[4];
    // sumi = C[i] + C[i - pow(2, k1)] + C[(i - pow(2, k1)) + pow(2, k2)]+`````;
    // pow(2, k)求法：lowbit
    cout << getsum(6);
}


// 工具