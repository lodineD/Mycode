#include <iostream>

using namespace std;

typedef struct _HaffNode
{
    struct _HaffNode *right;
    struct _HaffNode *left;
    int data;
} HaffNode;

HaffNode *Create(int n)
{
    HaffNode *Hafftree[100];
    HaffNode *p;
    for (int i = 0; i < n; i++)
    {
        p = new HaffNode;
        cin >> p->data;
        p->right = nullptr;
        p->left = nullptr;
        Hafftree[i] = p;
    }
    HaffNode *head = nullptr;
    int min1 = 0, min2 = 0;
    int temp = 0;
    while (1)
    {
        for (int i = 0; i < n; i++)
        {
            if (Hafftree[i] != nullptr && Hafftree[min1]->data > Hafftree[i]->data)
            {
                min1 = i;
            }
        }
        // 防止第一次后min1还是最小值，导致min2对应仍为空而报错
        for (int i = 0; i < n; i++)
        {
            if (Hafftree[i] != nullptr && i != min1)
            {
                min2 = i;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i == min1)
                continue;
            if (Hafftree[i] != nullptr && Hafftree[min2]->data > Hafftree[i]->data)
            {
                min2 = i;
            }
        }
        HaffNode *p2 = new HaffNode;
        p2->data = Hafftree[min1]->data + Hafftree[min2]->data;
        p2->left = Hafftree[min1];
        p2->right = Hafftree[min2];
        head = p2;
        Hafftree[min1] = p2;
        Hafftree[min2] = nullptr;
        for (int i = 0; i < n; i++)
        {
            if (Hafftree[i] != nullptr)
            {
                temp++;
            }
        }
        if (temp == 1)
        {
            break;
        }
        else
        {
            temp = 0;
        }
    }
    return head;
}

int WPL(HaffNode *Hafft, int length)
{
    HaffNode *p = Hafft;
    if (p->left == nullptr && p->right == nullptr)
    {
        return p->data * length;
    }
    else
    {
        return WPL(p->left, length + 1) + WPL(p->right, length + 1);
    }
}

void DFS(HaffNode *Hafft)
{
    HaffNode *p = Hafft;
    cout << p->data;
    if (p->left != nullptr)
    {
        cout << "(";
        DFS(p->left);
        cout << ",";
    }
    if (p->right != nullptr)
    {
        DFS(p->right);
        cout << ")";
    }
}

void Code(HaffNode *Hafft, int length)
{
    HaffNode *p = Hafft;
    static int code[100];
    // for (int i=0;i<100;i++)
    // {
    //     code[i] = 0;
    // }
    if (p->left == nullptr && p->right == nullptr)
    {
        for (int i = 0; i < length; i++)
        {
            cout << code[i];
        }
        cout << " ";
    }
    else
    {
        code[length] = 0;
        Code(p->left, length + 1);
        code[length] = 1;
        Code(p->right, length + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    HaffNode *Hafft = Create(n);
    cout << WPL(Hafft, 0) << endl;
    DFS(Hafft);
    cout << endl;
    Code(Hafft, 0);
    return 0;
}