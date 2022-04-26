#include <iostream>

using namespace std;

class Gragm
{
private:
    int **AdjMatrix;
    int numVertex; // 定点个数
    int numEdge;   // 边的个数
public:
    Gragm(int numVert);
    ~Gragm();
    int weight(int from, int to); // 取出权重
    void setEdge(int from, int to, int weight);
    void delEdge(int from, int to);
    int FirstAdj(int oneVertex); //取出该节点与其最近的节点
};

Gragm::Gragm(int numVert)
{
    // 构造方式
    numVertex = numVert;
    AdjMatrix = new int *[numVertex];
    for (int i = 0; i < numVertex; i++)
    {
        AdjMatrix[i] = new int[numVertex];
    }
    for (int i = 0; i < numVertex; i++)
    {
        for (int j = 0; j < numVertex; j++)
        {
            AdjMatrix[i][j] = 0;
        }
    }
}

Gragm::~Gragm()
{
    for (int i = 0; i < numVertex; i++)
    {
        delete[] AdjMatrix[i];
    }
    delete[] AdjMatrix;
}

int Gragm::weight(int from, int to)
{
    return AdjMatrix[from][to];
}

void Gragm::setEdge(int from, int to, int weight)
{
    if (AdjMatrix[from][to] == 0)
    {
        numEdge++;
    }
    AdjMatrix[from][to] = weight;
}

void Gragm::delEdge(int from, int to)
{
    if (AdjMatrix[from][to] != 0)
    {
        numEdge--;
    }
    AdjMatrix[from][to] = 0;
}

int Gragm::FirstAdj(int oneVertex)
{
    for (int i = 0; i < numVertex; i++)
    {
        if (AdjMatrix[oneVertex][i] != 0)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    
    return 0;
}