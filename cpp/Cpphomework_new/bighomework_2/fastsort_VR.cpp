#include <iostream>
#include <Windows.h>

using namespace std;

void fastSort(int a[], int low, int high);
void print_a(int a[], int low, int high);

int main()
{
    int a[] = {3, 1, 7, 9, 5};
    print_a(a, 0, 4);
    Sleep(1000);
    fastSort(a, 0, 4);
    print_a(a, 0, 4);
    return 0;
}

void fastSort(int a[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int pivot = a[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (i < j && pivot < a[j])
        {
            j--;
            print_a(a, i, j);
            Sleep(1000);
        }
        if (i < j)
        {
            a[i] = a[j];
            i++;
            print_a(a, i, j);
            Sleep(1000);
        }
        while (i < j && pivot > a[i])
        {
            i++;
            print_a(a, i, j);
            Sleep(1000);
        }
        if (i < j)
        {
            a[j] = a[i];
            j--;
            print_a(a, i, j);
            Sleep(1000);
        }
    }
    a[i] = pivot;
    fastSort(a, low, --i);
    fastSort(a, ++j, high);
}

void print_a(int a[], int low, int high)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < a[i]; j++)
        {
            cout << "□ ";
        }
        if (i == low || i == high)
        {
            cout << a[i] << " "
                 << "<-" << endl;
        }
        else
        {
            cout << a[i] << endl;
        }
    }
    cout << endl;
}