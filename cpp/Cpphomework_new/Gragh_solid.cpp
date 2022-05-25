#include <iostream>

using namespace std;

int const MAX_numVertex = 20;

class Gragm
{
private:
    bool Visited[MAX_numVertex];
    int **AdjMatrix;
    int numVertex; // 定点个数
    int numEdge;   // 边的个数
public:
    Gragm(int numVert);
    ~Gragm();
    int weight(int from, int to); // 取出权重
    void setEdge(int from, int to, int weight);
    void delEdge(int from, int to);
    int nextAdj(int oneVertex); //取出该节点与其最近的节点（用于DFS和BFS搜索）
    // int nextAdj(int oneVertex);  // 用于DFS和BFS搜索
    void DFSr();    // 定义bool数组，检查节点是否已遍历
    void DFS(int V); // V为节点
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

int Gragm::nextAdj(int oneVertex)
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

void Gragm::DFSr()
{
    for (int i = 0; i < numVertex; i++)
    {
        Visited[i] = false;
    }
    for (int j = 0; j < numVertex; j++)
    {
        if (!Visited[j])
        {
            DFS(j);
        }
    }
}

void Gragm::DFS(int v)
{
    cout << v << endl; // 访问节点
    Visited[v] = true;
    for (int i = v; i >= 0; i = nextAdj(v))
    {
        if (!Visited[i])
        {
            DFS(i);
        }
    }
}

int main()
{

    return 0;
}