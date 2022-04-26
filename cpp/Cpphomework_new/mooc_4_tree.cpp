#include <iostream>
#include <queue>

using namespace std;

typedef char ElemType;

typedef struct CSNode
{
    ElemType data;
    struct CSNode *firstchild, *nextsibling;
} CSNode, *CSTree;

unsigned int TreeDepth(CSTree T)
{
    if (T)
    {
        return (1 + TreeDepth(T->firstchild)) > TreeDepth(T->nextsibling) ? (1 + TreeDepth(T->firstchild)) : TreeDepth(T->nextsibling);
    }
    return 0;
}
/*
    另一种写法
    unsigned int TreeDepth(CSTree T)
    {
        if (!T)
        {
            return 0;
        }
        int left = TreeDepth(T->firschild);
        int right = TreeDepth(T->nextsibling);
        return (left>=right ? left : right) + 1;
    }
*/

void CreateTree(CSTree *T)
{
    (*T) = NULL;
    ElemType Felem;
    ElemType Selem;
    CSNode *p;
    CSNode *r;
    queue<CSNode *> Q;
    for ((cin >> Felem >> Selem); Selem != '#'; cin >> Felem >> Selem)
    {
        CSNode *node;
        node = (CSNode *)malloc(sizeof(CSNode));
        node->data = Selem;
        node->firstchild = NULL;
        node->nextsibling = NULL;
        Q.push(node);
        if (Felem == '#')
        {
            (*T) = node;
            r = node;
        }
        else
        {
            while (Q.front()->data != Felem)
            {
                Q.pop();
            }
            
        }
    }
}

int main()
{
}