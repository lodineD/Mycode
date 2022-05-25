#include <iostream>
#include <cstring>

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
         << l->length << endl;
    return;
}

void _delete(Link *l, char a)
{
    for (int i = 0; i < l->length; i++)
    {
        Link *head = l;
        Link *p = l;
        head = head->next;
        while (head)
        {
            if (head->data == a)
            {
                p->next = head->next;
                l->length--;
                break;
            }
            head = head->next;
            p = p->next;
        }
    }
}

int main()
{
    Link *link = creatLink();
    char da[200];
    scanf("%[^\n]", da);
    for (int i = 0; i < strlen(da); i++)
    {
        addLink(link, da[i]);
    }
    showLink(link);
    char B;
    cin >> B;
    _delete(link, B);
    showLink(link);
    return 0;
}