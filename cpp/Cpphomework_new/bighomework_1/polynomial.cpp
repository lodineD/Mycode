/**
 * 多项式函数实现
 * @author zyd
 * @date 2022/4/17
 *
 **/

#include "polynomial.h"
#include <iostream>
#include <map>

Poly::Poly()
{
    MAXSize = 0;
    coe = 0.0;
    exp = 0.0;
    next = nullptr;
}

Poly::~Poly()
{
    MAXSize = 0;
    coe = 0;
    exp = 0;
    delete next;
}

// 该函数是创建多项式
Poly *Poly::CreateP()
{
    Poly *Head = new Poly;
    std::cout << "请输入多项式的项数" << std::endl;
    std::cin >> Head->MAXSize;
    while (Head->MAXSize <= 0)
    {
        std::cout << "请输入大于0的项数！" << std::endl;
        std::cout << "请继续输入: " << std::endl;
        std::cin >> Head->MAXSize;
    }
    Poly *listP = new Poly;
    Head->next = listP;
    for (int i = 0; i < Head->MAXSize; i++) // 循环构建链表
    {
        Poly *p = new Poly;
        std::cout << "请输入第" << i + 1 << "个项的系数" << std::endl;
        std::cin >> listP->coe;
        std::cout << "请输入第" << i + 1 << "个项的指数" << std::endl;
        std::cin >> listP->exp;
        listP->next = p;
        listP = p;
        listP->next = nullptr;
    }
    return Head;
}

int Poly::getMAXSize()
{
    return MAXSize;
}

int Poly::getcoe()
{
    return coe;
}

int Poly::getexp()
{
    return exp;
}

Poly *Poly::getnext()
{
    return next;
}

Poly *operator+(const Poly &p1, const Poly &p2)
{
    std::map<int, int> m;
    Poly *_p1 = p1.next;
    Poly *_p2 = p2.next;
    for (int i = 0; i < p1.MAXSize; i++)
    {
        m[_p1->exp] = _p1->coe + m[_p1->exp];
        _p1 = _p1->next;
    }
    for (int j = 0; j < p2.MAXSize; j++)
    {
        m[_p2->exp] = _p2->coe + m[_p2->exp];
        if (m[_p2->exp] == 0)
        {
            m.erase(_p2->exp); //如果两个多项式相加一项的系数为0，则删去
        }
        _p2 = _p2->next;
    }
    Poly *p3 = new Poly; // 新建链表头，作为返回值
    p3->MAXSize = m.size();
    Poly *p4;
    p3->next = p4;
    for (auto i = m.rbegin(); i != m.rend(); ++i)
    {
        Poly *p5 = new Poly;
        if (i->second != 0)
        {
            // std:: cout << i->first << ' ' << i->second<<std::endl;
            p4->exp = i->first;
            p4->coe = m[p4->exp];
        }
        p4->next = p5;
        p4 = p5;
        p4->next = nullptr;
    }
    m.clear();
    return p3;
}

Poly *operator-(const Poly &p1, const Poly &p2)
{
    std::map<int, int> m;
    Poly *_p1 = p1.next;
    Poly *_p2 = p2.next;
    for (int i = 0; i < p1.MAXSize; i++)
    {
        m[_p1->exp] = _p1->coe + m[_p1->exp];
        _p1 = _p1->next;
    }
    for (int j = 0; j < p2.MAXSize; j++)
    {
        m[_p2->exp] = m[_p2->exp] - _p2->coe;
        if (m[_p2->exp] == 0)
        {
            m.erase(_p2->exp); //如果两个多项式相减一项的系数为0，则删去
        }
        _p2 = _p2->next;
    }
    Poly *p3 = new Poly; //新建链表头，作为返回值
    p3->MAXSize = m.size();
    Poly *p4;
    p3->next = p4;
    for (auto i = m.rbegin(); i != m.rend(); ++i)
    {
        Poly *p5 = new Poly;
        if (i->second != 0)
        {
            // std:: cout << i->first << ' ' << i->second<<std::endl;
            p4->exp = i->first;
            int a = i->first;
            p4->coe = m[p4->exp];
        }
        p4->next = p5;
        p4 = p5;
        p4->next = nullptr;
    }
    m.clear();
    return p3;
}

void BubbleSort(Poly *pre)
{
    int i, num;         // num进行内层循环
    Poly *p, *q, *tail; //创建三个指针，进行冒泡排序
    p = pre;
    for (i = 0; i < pre->MAXSize - 1; i++) //外层循环
    {
        num = pre->MAXSize - i - 1;
        q = pre->next; //令q指向第一个结点
        p = q->next;   //令p指向后一个结点
        tail = pre;
        while (num--) //内层循环
        {
            if (q->exp < p->exp) //如果该结点的值小于后一个结点，则交换
            {
                q->next = p->next;
                p->next = q;
                tail->next = p;
            }
            tail = tail->next;
            q = tail->next;
            p = q->next;
        }
    }
}

// 输出多项式
void showP(Poly *pre)
{
    Poly *p2 = pre;
    p2 = p2->getnext();
    for (int j = 0; j < pre->getMAXSize(); j++)
    {
        if (p2->getcoe() > 0 && p2->getcoe() != 1)
        {
            j == 0 ? std::cout << p2->getcoe() << "x^" << p2->getexp() : std::cout << "+" << p2->getcoe() << "x^" << p2->getexp();
        }
        else if (p2->getcoe() == 1)
        {
            j == 0 ? std::cout << "x^" << p2->getexp() : std::cout << "+x^" << p2->getexp();
        }
        else if (p2->getcoe() == 0)
        {
            p2 = p2->getnext();
            continue;
        }
        else if (p2->getcoe() == -1)
        {
            std::cout << "-x^" << p2->getexp();
        }
        else if (p2->getcoe() < 0 && p2->getcoe() != -1)
        {
            std::cout << p2->getcoe() << "x^" << p2->getexp();
        }
        p2 = p2->getnext();
    }
    std::cout << std::endl;
}

// 该函数用于计算多项式
double Count(Poly *pre, double n)
{
    double sum = 0;
    Poly *p = pre->getnext();
    for (int i = 0; i < pre->getMAXSize(); i++)
    {
        sum = sum + p->getcoe() * n + p->getnext()->getcoe();
    }
    return sum;
}