#include <iostream>

using namespace std;

void Merge(int a[], int l, int r, int mid)
{
    int tem[100], k, i, j;
    i = l;
    j = mid + 1;
    for (k = l; k <= r; k++)
    {
        tem[k - l] = a[k]; //看清楚赋值
    }
    for (k = l; k <= r; k++) // 赋值不要错
    {
        if (i > mid) // 第一个数组的指针到顶，只需移动第二个数组
        {
            a[k] = tem[j - l];
            j++;
        }
        else if (j > r) //同理
        {
            a[k] = tem[i - l];
            i++;
        }
        else if (tem[i - l] > tem[j - l])
        {
            a[k] = tem[j - l];
            j++;
        }
        else
        {
            a[k] = tem[i - l];
            i++;
        }
    }
}

void Msort(int a[], int l, int r)
{
    if (l >= r)
    {
        return; //不要忘了
    }
    int mid = (l + r) / 2;
    Msort(a, l, mid);
    Msort(a, mid + 1, r);
    Merge(a, l, r, mid);
}

int main()
{
    int a[] = {2, 3, 4, 1, 5};
    Msort(a, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}