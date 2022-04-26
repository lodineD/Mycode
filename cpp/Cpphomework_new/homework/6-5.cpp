#include <iostream>

using namespace std;

int main()
{
    int N;
    int a1, b1;
    int a2, b2;
    int maxbei;
    // int sum, ;
    scanf("%d", &N);
    scanf("%d/%d", &a1, &b1);
    for (int i = 1; i < N; i++)
    {
        scanf("%d/%d", &a2, &b2);
        a1 = a1 * b2 + a2 * b1;
        b1 = b1 * b2;
        // if ()
        for (maxbei = b1; maxbei >= 1; maxbei--)
        {
            if (a1 % maxbei == 0 && b1 % maxbei == 0)
            {
                a1 = a1 / maxbei;
                b1 = b1 / maxbei;
                break;
            }
        }
    }
    int zh = a1 / b1;
    if (a1 % b1 == 0)
    {
        cout << zh;
    }
    else if (a1 % b1 != 0 && zh != 0)
    {
        a1 = a1 - b1 * zh;
        cout << zh << " " << a1 << "/" << b1;
    }
    else if (a1 % b1 != 0 && zh == 0)
    {
        cout << a1 << "/" << b1;
    }
}