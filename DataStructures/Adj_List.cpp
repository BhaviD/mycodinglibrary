#include <iostream>
#include <list>
using namespace std;

class Graph
{
private:
    int V;
    list<int> *adj;
public:
    Graph(int N)
    {
        V = N;
        adj = new list<int>[N];
    }

    ~Graph()
    {
        delete[] adj;
    }

    void addEdge(int v, int w);
    void printGraph();
};

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::printGraph()
{
    list<int>::iterator i;
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex " << v << "\n head ";
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            cout << "-> " << *i;
        }
        cout << endl;
    }
}

int main()
{
    Graph gh(5);
    gh.addEdge(0, 1);
    gh.addEdge(0, 4);
    gh.addEdge(1, 2);
    gh.addEdge(1, 3);
    gh.addEdge(1, 4);
    gh.addEdge(2, 3);
    gh.addEdge(3, 4);

    gh.printGraph();

    return 0;
}