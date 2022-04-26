#include <iostream>
#include <queue>

using namespace std;

template <class T>
class HuffmanNode
{
public:
    T key;
    HuffmanNode *left;
    HuffmanNode *right;
    HuffmanNode *parent;
    HuffmanNode(T value, HuffmanNode *l, HuffmanNode *r, HuffmanNode *p) : key(value), left(l), right(r), parent(p) {}
};

template <class T>
class Huffman
{
private:
    HuffmanNode<T> *root;
    HuffmanNode<T> *Create(HuffmanNode<T> *bt);
    void Destory(HuffmanNode<T> *bt);
    void PreOrder(HuffmanNode<T> *bt);
    void MidOrder(HuffmanNode<T> *bt);
    void reOrder(HuffmanNode<T> *bt);

public:
    Huffman() { root = Create(root); }
    ~Huffman() { Destroy(root); }
    void PreOrder() { PreOrder(root); }
    void MidOrder() { MidOrder(root); }
    void reOrder() { reOrder(root); }
};

template <class T>
HuffmanNode<T> *Huffman<T>::Create(HuffmanNode<T> *bt)
{
    
}

int main()
{
    return 0;
}