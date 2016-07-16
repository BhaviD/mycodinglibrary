#include <iostream>
#include <cstdlib>
using namespace std;
 
struct ListNode
{
    int dest;
	ListNode* next;

	ListNode(int nDest = 0)
	{
		dest = nDest;
		next = NULL;
	}
};

class Graph
{
    private:
        int V;
        struct ListNode** adjList;
    public:
        Graph(int N)
        {
            V = N;
			adjList = new ListNode*[V];
            for (int i = 0; i < V; ++i)
				adjList[i] = NULL;
        }

		~Graph()
		{
			ListNode* pCrawl{ NULL };
			ListNode* deleteNode{ NULL };

			for (int v = 0; v < V; ++v)
			{
				pCrawl = adjList[v];
				while (pCrawl)
				{
					deleteNode = pCrawl;
					pCrawl = pCrawl->next;

					delete deleteNode;
				}
			}

			delete[] adjList;
		}

		void addEdge(int, int);
		void printGraph();
};

void Graph::addEdge(int u, int v)
{
	ListNode* newNode = new ListNode(v);
	newNode->next = adjList[u];
	adjList[u] = newNode;

	newNode = new ListNode(u);
	newNode->next = adjList[v];
	adjList[v] = newNode;
}

void Graph::printGraph()
{
	for (int v = 0; v < V; ++v)
	{
		ListNode* pCrawl = adjList[v];
		cout << "\n Adjacency list of vertex " << v << "\n head ";
		while (pCrawl)
		{
			cout << "-> " << pCrawl->dest;
			pCrawl = pCrawl->next;
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
