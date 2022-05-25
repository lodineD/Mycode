#include <iostream>
#include <cstring>

using namespace std;

class recordList
{
private:
    int a[100];
    int currentSize;

public:
    recordList();
    void MergeSort();
    void MSort(int r, int l);
    void Merge(int l, int r, int mid);
    void getData();
    void HeapSort();
    void swap(int a, int b);
    void FilterDown(int p, int len);
};

recordList::recordList()
{
    memset(a, 0, 100);
    currentSize = 0;
}

void recordList::Merge(int l, int r, int mid)
{
    int tem[100], k, i, j;
    i = l;
    j = mid + 1;
    for (k = l; k <= r; k++)
    {
        tem[k - l] = a[k];
    }
    for (k = l; k <= r; k++)
    {
        if (i > mid)
        {
            a[k] = tem[j - l];
            j++;
        }
        else if (j > r)
        {
            a[k] = tem[i - l];
            i++;
        }
        else if (tem[i - l] < tem[j - l])
        {
            a[k] = tem[i - l];
            i++;
        }
        else
        {
            a[k] = tem[j - l];
            j++;
        }
    }
}

void recordList::MSort(int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int mid = (r + l) / 2;
    MSort(l, mid);
    MSort(mid + 1, r);
    Merge(l, r, mid);
}

void recordList::MergeSort()
{
    MSort(0, currentSize - 1);
    for (int i = 0; i < currentSize; i++)
    {
        i == 0 ? cout << a[i] : cout << " " << a[i];
    }
}

void recordList::getData()
{
    cin >> currentSize;
    for (int i = 0; i < currentSize; i++)
    {
        cin >> a[i];
    }
}

void recordList::HeapSort()
{
    //对表heap[0]到heap[n-1]进行排序，使得表中各个待排序记录按其关键字，非递减排序
    for (int i = (currentSize - 2) / 2; i >= 0; i--)
        FilterDown(i, currentSize - 1); //建立初始大顶堆
    for (int i = currentSize - 1; i >= 1; i--)
    {
        int k = a[0];
        a[0] = a[i];
        a[i] = k;             //交换元素
        FilterDown(0, i - 1); //重新构建最大堆
    }
    for (int i = 0; i < currentSize; i++)
    {
        i == 0 ? cout << a[i] : cout << " " << a[i];
    }
}

void recordList::FilterDown(int i, int len)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int temMin = i;
    if (l <= len && a[temMin] > a[l])
    {
        temMin = l;
    }
    if (r <= len && a[temMin] > a[r])
    {
        temMin = r;
    }
    if (temMin != i)
    {
        // cout << a[i] << " " << a[temMin] << endl;
        int j = a[i];
        a[i] = a[temMin];
        a[temMin] = j;
        // cout << a[i] << " " << a[temMin] << endl;
        FilterDown(temMin, len);
    }
}

int main()
{
    recordList L;
    L.getData();
    L.MergeSort();
    cout << endl;
    L.HeapSort();
}