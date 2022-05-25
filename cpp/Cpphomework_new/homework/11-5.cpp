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
    // ~Gragm();
    int weight(int from, int to); // 取出权重
    void setEdge(int from, int to, int weight);
    void delEdge(int from, int to);
    int FirstAdj(int oneVertex);
    int nextAdj(int oneVertex, int preVertex); //取出该节点与其最近的节点（用于DFS和BFS搜索）
    // int nextAdj(int oneVertex);  // 用于DFS和BFS搜索
    // void DFSr();     // 定义bool数组，检查节点是否已遍历
    // void DFS(int V); // V为节点
    // void setV(int V);
    // void setE(int E);
    int getV()
    {
        return numVertex;
    }
    int getE()
    {
        return numEdge;
    }
    // friend int Kruskal(Gragm G);
};

class Edge
{
public:
    int from;
    int to;
    int weight;
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

// Gragm::~Gragm()
// {
//     for (int i = 0; i < numVertex; i++)
//     {
//         delete[] AdjMatrix[i];
//     }
//     delete[] AdjMatrix;
// }

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
    if (AdjMatrix[from - 1][to - 1] != 0)
    {
        numEdge--;
    }
    AdjMatrix[from - 1][to - 1] = 0;
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

int Gragm::nextAdj(int oneVertex, int preVertex)
{
    for (int i = preVertex + 1; i < numVertex; i++)
    {
        if (AdjMatrix[oneVertex][i] != 0)
        {
            return i;
        }
    }
    return -1;
}

// void Gragm::DFSr()
// {
//     for (int i = 0; i < numVertex; i++)
//     {
//         Visited[i] = false;
//     }
//     for (int j = 0; j < numVertex; j++)
//     {
//         if (!Visited[j])
//         {
//             DFS(j);
//         }
//     }
// }

// void Gragm::DFS(int v)
// {
//     cout << v << endl; // 访问节点
//     Visited[v] = true;
//     for (int i = v; i >= 0; i = nextAdj(v))
//     {
//         if (!Visited[i])
//         {
//             DFS(i);
//         }
//     }
// }

int cmp(const void *a, const void *b)
{
    Edge *c = (Edge *)a;
    Edge *d = (Edge *)b;
    if (c->weight != d->weight)
    {
        return c->weight - d->weight;
    }
    else
    {
        return d->from - c->from;
    }
}

int Kruskal(Gragm G)
{
    Edge *E = new Edge[G.getE()];
    int *Vest = new int[G.getV()];
    int Edgecount = 0;
    for (int i = 0; i < G.getV(); i++)
    {
        for (int j = G.FirstAdj(i); j != -1; j = G.nextAdj(i, j))
        {
            if (i < j)
            {
                E[Edgecount].from = i;
                E[Edgecount].to = j;
                E[Edgecount++].weight = G.weight(i, j);
                // Edgecount++;
            }
        }
        Vest[i] = i;
    }
    qsort(E, Edgecount, sizeof(E[0]), cmp);
    int sum = 0;
    int cnt = 0;
    int k = 0;
    int x, y;
    while (cnt < G.getV() - 1)
    {
        x = Vest[E[k].from];
        y = Vest[E[k].to];
        if (x != y)
        {
            sum = sum + E[k].weight;
            cnt++;
            for (int j = 0; j < G.getV(); j++)
            {
                if (Vest[j] == y)
                {
                    Vest[j] = x;
                }
            }
        }
        k++;
    }
    return sum;
}

int main()
{
    int V, E;
    cin >> V >> E;
    Gragm G(V);
    int from, to, weight;
    for (int i = 0; i < E; i++)
    {
        cin >> from >> to >> weight;
        G.setEdge(from - 1, to - 1, weight);
    }
    // cout << G.weight(7, 8);
    cout << Kruskal(G) << endl;
    return 0;
}