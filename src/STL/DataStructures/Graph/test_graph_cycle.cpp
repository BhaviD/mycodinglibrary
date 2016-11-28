// the program inputs a directed Acyclic Graph (DAG) from the file
// "dag.dat" and calls the graph algorithm Acyclic() to verify that
// it has no cycles. adding an edge (E,A) creates a cycle in the
// graph. a call to Acyclic() verifies the presence of the cycle

#include <iostream>
#include <fstream>
#include <string>

#include "Graph.h"

using namespace std;

int main()
{
    Graph<char> g;
    // the file that defines the graph
    ifstream graphIn("dag.dat");
    if(!graphIn)
    {
        cerr << "Can't open file!!" << endl;
        return 1;
    }

    // read the graph
    graphIn >> g;

    // determine if the graph is acyclic
    if (Acyclic(g))
        cout << "Original graph is Acyclic" << endl;
    else
        cout << "Original graph is not Acyclic" << endl;

    // add edge (E,A) to create a cycle
    cout << "Adding edge (E,A): ";
    g.insertEdge('E', 'A', 1);

    // retest the graph to see if it is acyclic
    if (Acyclic(g))
        cout << "New graph is Acyclic" << endl;
    else
        cout << "New graph is not Acyclic" << endl;

    return 0;
}

/*
Run:

Original graph is Acyclic
   Adding edge (E,A): New graph is not Acyclic
*/
