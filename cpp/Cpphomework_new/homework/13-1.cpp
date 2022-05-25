#include <iostream>

using namespace std;

void BubbleSort(int a[]);
void SelectionSort(int a[]);

int main()
{
    int a[100];
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    BubbleSort(a);
    cout << endl;
    SelectionSort(a);
    return 0;
}

void BubbleSort(int a[])
{
    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = 0; j < 10 - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int k;
                k = a[j];
                a[j] = a[j + 1];
                a[j + 1] = k;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        i == 0 ? cout << a[i] : cout << " " << a[i];
    }
}

void SelectionSort(int a[])
{
    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = i; j < 10 - 1; j++)
        {
            if (a[i] < a[j + 1])
            {
                int k;
                k = a[i];
                a[i] = a[j + 1];
                a[j + 1] = k;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        i == 0 ? cout << a[i] : cout << " " << a[i];
    }
}