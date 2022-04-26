#include <iostream>
#include <queue>
#include <stack>

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

void AllPath(CSTree T, stack<ElemType> *S1)
{
    // stack<ElemType> S1;

    while (T != NULL)
    {
        S1->push(T->data);
        if (T->firstchild == NULL)
        {
            stack<ElemType> S2;
            S2 = (*S1);
            while (!S2.empty())
            {
                printf("%c\n", S2.top());
                S2.pop();
            }
        }
        else
        {
            AllPath(T->firstchild, S1);
        }
        S1->pop();
        T = T->nextsibling;
    }
}

void CreateTree(CSTree *T)
{
    (*T) = NULL;
    ElemType Felem;
    ElemType Selem;
    CSNode *r = NULL; // r为指向当前结点的指针
    CSNode *p = NULL; // p为指向队列front的指针
    queue<CSNode *> Q;
    for (scanf("%c%c", &Felem, &Selem); Selem != '#'; scanf("%c%c", &Felem, &Selem))
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
            p = Q.front();
            if (!(p->firstchild))
            {
                p->firstchild = node;
                r = node;
            }
            else
            {
                r->nextsibling = node;
                r = node;
            }
        }
    }
}

void DestroyTree(CSTree *T)
{
    if (*T)
    {
        DestroyTree(&((*T)->firstchild));
        DestroyTree(&((*T)->nextsibling));
        free(*T);
        (*T) = NULL;
    }
}

int main()
{
    CSTree T;
    CreateTree(&T);
    // cout << T->nextsibling->data << endl;
    // PrintTree(T);
    stack<ElemType> s;
    AllPath(T, &s);
    /*while (!s.empty()) {
        cout << s.top()	<< endl;
        s.pop();
    }*/
    cout << TreeDepth(T) << endl;
    DestroyTree(&T);
    if (!T)
    {
        cout << "delete successfully" << endl;
    }
    return 0;
}