#include <iostream>

using namespace std;
typedef struct LNode
{
    int data;
    struct LNode *next;
} Link;

Link *creatLink()
{
    Link *l1 = (Link *)malloc(sizeof(Link));
    if (l1==NULL)
    {
        cout << "创建失败！" << endl;
    }
    l1->data = 0;
    l1->next = NULL;
    return l1;
}

Link *addLink(Link *l, int a)
{
    Link *head = l;
    Link *l2 = (Link *)malloc(sizeof(Link));
    l2->data = a;
    l2->next = NULL;
    while (head->next)
    {
        head = head->next;
    }
    head->next = l2;
    return l;
}

void showLink(Link *l)
{
    Link *head = l;
    head = head->next;
    while (head)
    {
        cout << head->data << endl;
        head = head->next;
    }
    return;
}

int main()
{
    Link *link = creatLink();
    link = addLink(link, 1);
    link = addLink(link, 2);
    link = addLink(link, 3);
    showLink(link);
    return 0;
}