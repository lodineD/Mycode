#include <iostream>

using namespace std;
typedef struct LNode
{
    int length;
    char data;
    struct LNode *next;
} Link;

Link *creatLink()
{
    Link *l1 = (Link *)malloc(sizeof(Link));
    if (l1 == NULL)
    {
        cout << "创建失败！" << endl;
    }
    l1->data = 0;
    l1->next = NULL;
    l1->length = 0;
    return l1;
}

Link *addLink(Link *l, char a)
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
    l->length++;
    return l;
}

void showLink(Link *l)
{
    Link *head = l;
    head = head->next;
    while (head)
    {
        cout << head->data;
        head = head->next;
    }
    cout << endl
         << l->length;
    return;
}

int main()
{
    Link *link = creatLink();
    char da[200];
    scanf("%[^\n]", da);
    showLink(link);
    return 0;
}