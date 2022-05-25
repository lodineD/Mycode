#include <iostream>

using namespace std;

void fastsort(int a[], int low, int high)
{
    if (low >= high)
    {
        return; // 条件记得加
    }
    int key = a[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (i < j && key > a[j])
        {
            j--;
        }
        if (i < j)
        {
            a[i] = a[j];
            i++;
        }
        while (i < j && key > a[i])
        {
            i++;
        }
        if (i < j)
        {
            a[j] = a[i];
            j--;
        }
    }
    //以下的不要写在while里面
    a[i] = key;
    fastsort(a, low, --i);
    fastsort(a, ++j, high);
}

int main()
{
    int a[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    fastsort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}