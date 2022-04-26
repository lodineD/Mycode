#include <iostream>
#include <queue>

using namespace std;

// typedef int ElemType;
template <class ElemType>
struct BiNode
{
    ElemType data;
    BiNode<ElemType> *rchild, *lchild;
};

template <class ElemType>
class BiTree
{
private:
    BiNode<ElemType> *root;
    BiNode<ElemType> *Creat(BiNode<ElemType> *bt);
    void Release(BiNode<ElemType> *bt);
    void PreOrder(BiNode<ElemType> *bt);   // 前序遍历
    void MidOrder(BiNode<ElemType> *bt);   // 中序遍历
    void reOrder(BiNode<ElemType> *bt);    // 后序遍历
    void levelOrder(BiNode<ElemType> *bt); // 层序遍历
public:
    BiTree() { root = Creat(root); }
    ~BiTree() { Release(root); }
    void PreOrder() { PreOrder(root); }
    void MidOrder() { MidOrder(root); }
    void reOrder() { reOrder(root); }
    void levelOrder() { levelOrder(root); }
};

template <class ElemType>
BiNode<ElemType> *BiTree<ElemType>::Creat(BiNode<ElemType> *bt)
{
    char ch;
    cout << "请输入树的节点：" << endl;
    cin >> ch;
    if (ch == '#')
    {
        return NULL;
    }
    else
    {
        bt = new BiNode<ElemType>;
        bt->data = ch;
        bt->lchild = Creat(bt->lchild);
        bt->rchild = Creat(bt->rchild);
    }
    return bt;
}

template <class ElemType>
void BiTree<ElemType>::Release(BiNode<ElemType> *bt)
{
    if (bt != NULL)
    {
        Release(bt->lchild);
        Release(bt->rchild);
        delete bt;
    }
}

template <class ElemType>
void BiTree<ElemType>::PreOrder(BiNode<ElemType> *bt)
{
    if (bt == NULL)
    {
        return;
    }
    else
    {
        cout << bt->data << " ";
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}

template <class ElemType>
void BiTree<ElemType>::MidOrder(BiNode<ElemType> *bt)
{
    if (bt != NULL)
    {
        MidOrder(bt->lchild);
        cout << bt->data << " ";
        MidOrder(bt->rchild);
    }
    else
    {
        return;
    }
}

template <class ElemType>
void BiTree<ElemType>::reOrder(BiNode<ElemType> *bt)
{
    if (bt != NULL)
    {
        reOrder(bt->lchild);
        reOrder(bt->rchild);
        cout << bt->data << " ";
    }
    else
    {
        return;
    }
}

template <class ElemType>
void BiTree<ElemType>::levelOrder(BiNode<ElemType> *bt)
{
    queue<BiNode<ElemType> *> q;
    BiNode<ElemType> *q2;
    if (bt == NULL)
    {
        return;
    }
    else
    {
        q.push(bt);
        while (!q.empty())
        {
            q2 = q.front();
            if (q2->lchild != NULL)
            {
                q.push(q2->lchild);
            }
            if (q2->rchild != NULL)
            {
                q.push(q2->rchild);
            }
            cout << q.front()->data << " ";
            q.pop();
        }
    }
}

int main()
{
    BiTree<char> T;
    T.PreOrder();
    cout << endl;
    T.MidOrder();
    cout << endl;
    T.reOrder();
    cout << endl;
    T.levelOrder();
    return 0;
}