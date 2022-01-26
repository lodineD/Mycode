
#include <iostream>

using namespace std;

int n;

struct student
{
    int num;
    float score;
    struct student *next;
};

struct student *create()
{
    struct student *head;
    struct student *p1, *p2;
    n = 0;
    int numtmp;
    cin >> numtmp;
    if (numtmp == 0)
        return NULL;

    p1 = p2 = new struct student;
    p1->num = numtmp;
    cin >> p1->score;
    p1->next = NULL;
    head = NULL;
    while (numtmp != 0)
    {
        n = n + 1;
        if (n == 1)
            head = p1;
        else
            p2->next = p1;
        p2 = p1;
        cin >> numtmp;
        if (numtmp == 0)
            continue;
        p1 = new struct student;
        p1->next = NULL;
        cin >> p1->score;
        p1->num = numtmp;
    }
    return (head);
}

/* print funcion -- print the num and score of each student
   input:
      head -- the head pointer of the link
   output:
   none
*/

void print(struct student *head)
{
    struct student *p = head;
    if (head == NULL)
        return;
    do
    {
        cout << p->num << "    " << p->score << endl;
        p = p->next;
    } while (p != NULL);
}

/* tuichu function
   input:
       head  --  the head pointer of the link
   output:
       none
 */
void tuichu(struct student *head)
{
    struct student *p = head;
    struct student *q;
    if (p == NULL)
        return;
    do
    {
        q = p->next;
        delete p;
        p = q;
    } while (p != NULL);
    return;
}

int main()
{
    struct student *head;
    head = create();
    print(head);
    tuichu(head);
    return 0;
}
