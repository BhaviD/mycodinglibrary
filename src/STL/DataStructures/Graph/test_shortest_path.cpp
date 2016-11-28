// the program inputs the graph specified by the file "shpath.dat"
// and prompts the user for a starting and an ending vertex. using
// the graph algorithm shortestPath(), the program outputs the length
// of the shortest path from the starting to the ending vertex and the
// actual path

#include <iostream>
#include <fstream>
#include <list>

#include "Graph.h"
#include "WriteContainer.h"

using namespace std;

int main()
{
    // vertices are characters
    Graph<char> g;

    char sVertex, eVertex;

    // minimum path to the destination vertex
    list<char> path;

    ifstream graphIn("shpath.dat");
    if(!graphIn)
    {
        cerr << "Couldn't open file!!!" << endl;
        return 1;
    }

    // input the graph and then prompt for input of
    // source and destination vertices
    graphIn >> g;

    cout << "Enter starting and ending vertices: ";
    cin >> sVertex >> eVertex;

    cout  << "    Shortest path from " << sVertex << " to " 
          << eVertex << " is "
          << ShortestPath(g, sVertex, eVertex, path) << "   Path: ";
    WriteContainer(path.begin(), path.end());
    cout << endl;

    return 0;
}

/*
Run 1:

Enter start and end vertices: F C
    Shortest path from F to C is   3   Path: F  D  A  C

Run 2:

Enter start and end vertices: C F
    Shortest path from C to F is  -1   Path:

Run 3:

Enter start and end vertices: B B
    Shortest path from B to B is   0   Path: B
*/
