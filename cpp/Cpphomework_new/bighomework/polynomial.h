/**
 * 多项式节点类
 * @author zyd
 * @date 2022/4/17
 *
 **/



class Poly
{
public:
    Poly();
    ~Poly();
    friend Poly *operator+(const Poly &p1, const Poly &p2);
    friend Poly *operator-(const Poly &p1, const Poly &p2);
    Poly *CreateP();
    void _Delete(Poly *pre);
    int getMAXSize();
    int getcoe();
    int getexp();
    Poly *getnext();
    friend void BubbleSort(Poly *pre);

private:
    Poly *next;  // 储存下一个节点
    int MAXSize; // 最大表长
    int coe;     // 多项式的系数
    int exp;     // 多项式的指数
};
