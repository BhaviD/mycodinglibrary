// the program inputs the graph whose vertices are characters from the
// file "graphIO.dat" and calls the member function getNeighbors() to
// find set of neighbors for 'A'. using the function WriteContainer()
// from "WriteContainer.h", the program outputs the adjacent vertices. a call
// to the overloaded stream operator displays the properties of the
// graph

#include <iostream>
#include <fstream>
#include <set>

#include "Graph.h"        // the Graph class
#include "WriteContainer.h"     // function WriteContainer()

using namespace std;

int main()
{
    // graph with vertices of type char
    Graph<char> demoGraph;

    // edge set
    set<char> edgeSet;

    // input stream for graph data
    // open stream and input the graph
    ifstream graphIn("graphIO.dat");
    if(!graphIn)
    {
        cerr << "unable to open file!!" << endl;
        return 1;
    }
    graphIn >> demoGraph;

    // get set of neighbors of A and output with WriteContainer
    edgeSet = demoGraph.getNeighbors('A');

    cout << "Neighbors of A are ";
    WriteContainer(edgeSet.begin(), edgeSet.end());
    cout << endl << endl;
    
    // output the graph and its properties
    cout << demoGraph << endl;

    return 0;
}

/*
Input file: graphIO.dat
5
A B C D E
8
A  B  4
A  C  7
A  D  6
B  A  2
C  B  3
C  E  2
D  E  4
E  C  1

Run:

Neighbors of A are B  C  D

A: in-degree 1  out-degree 3
    Edges: B (4)  C (7)  D (6)
B: in-degree 2  out-degree 1
    Edges: A (2)
C: in-degree 2  out-degree 2
    Edges: B (3)  E (2)
D: in-degree 1  out-degree 1
    Edges: E (4)
E: in-degree 2  out-degree 1
    Edges: C (1)
*/
