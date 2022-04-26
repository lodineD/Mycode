#include <iostream>

using namespace std;

typedef struct QNode //定义队列结点的数据结构
{
    QNode *next; //指针域,指向下一个结点
    int data;    //数据域，存储队列信息
} Que;

typedef struct LinkQueue //定义队列的数据结构
{
    QNode *front; //队首指针,指向QNode类型的指针
    QNode *rear;  //队尾指针
} LinkQ;

LinkQ *CreatQ()
{
    LinkQ *LQ = (LinkQ *)malloc(sizeof(LinkQ));
    Que *q = (Que *)malloc(sizeof(Que));
    if (q == NULL)
    {
        cout << "创建失败！" << endl;
    }
    q->data = 0;
    q->next = NULL;
    LQ->front = q;
    LQ->rear = q;
    return LQ;
}

void addQ(LinkQ *LQ, int data)
{
    Que *q2 = (Que *)malloc(sizeof(Que));
    q2->data = data;
    q2->next = NULL;
    while (LQ->rear->next)
    {
        LQ->rear = LQ->rear->next;
    }
    LQ->rear->next = q2;
    LQ->rear = LQ->rear->next;
}



void showQ(LinkQ *LQ)
{
    LinkQ *LQ2 = LQ;
    LQ2->front = LQ2->front->next;
    while (LQ2->front)
    {
        cout << LQ2->front->data << endl;
        LQ2->front = LQ2->front->next;
    }
    return;
}


int main()
{
    LinkQ *q = CreatQ();
    addQ(q, 1);
    addQ(q, 2);
    addQ(q, 3);
    showQ(q);
    return 0;
}