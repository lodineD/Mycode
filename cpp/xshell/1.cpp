#include <iostream>

using namespace std;

int main()

{

    int month;
    cout << "please input  month:";
    while (cin >> month)
    {
        int first = 1;
        int second = 1;
        int result = 1;
        for (int i = 3; i <= month; ++i)
        {
            result = first + second; //xn=xn-1 + xn-2
            first = second;
            second = result;
        }
        cout << "result =" << result << endl;
    }
    return 0;
}