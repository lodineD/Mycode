#include <iostream>
#include <windows.h>

using namespace std;

void print_a(int a[]);

int main()
{
    bool change;
    int a[] = {3, 1, 7, 9, 5};
    print_a(a);
    Sleep(1000);
    for (int i = 0; i < 4; i++)
    {
        change = false;
        for (int j = 0; j < 4 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int tem = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tem;
                change = true;
                // system("cls");
                print_a(a);
                Sleep(1000);
            }
        }
        if (!change)
            break;
    }
    system("pause");
}

void print_a(int a[])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < a[i]; j++)
        {
            cout << "□ ";
        }
        cout << a[i] << endl;
    }
}