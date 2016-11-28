// the program inputs the graph specified by the file "mpath.dat".
// in a loop that executes four times, a prompt directs the user
// to enter starting and ending vertices. by calling the algorithm
// minimumPath(), the program outputs the minimum path weight and
// the corresponding path from the starting to the ending vertex

#include <iostream>
#include <fstream>
#include <iomanip>
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

    ifstream graphIn("mpath.dat");
    if(!graphIn)
    {
        cerr << "Couldn't open file!!!" << endl;
        return 1;
    }

    // input the graph
    graphIn >> g;

    do
    {
        cout << "Enter start and end vertices: ";
        cin >> sVertex >> eVertex;

        cout  << "    Minimum path from " << sVertex << " to " 
                << eVertex << " is " << setw(3)
               << MinimumPath(g, sVertex, eVertex, path) << "   Path: ";
        WriteContainer(path.begin(), path.end());
        cout << endl << endl;

        cout << "Continue? (y / n): ";
        cin >> sVertex;
    }while(sVertex == 'y');

    return 0;
}

/*
Run:

Enter start and end vertices: F C
    Minimum path from F to C is  38   Path: F  E  D  A  B  C

Enter start and end vertices: C F
    Minimum path from C to F is  -1   Path:

Enter start and end vertices: B B
    Minimum path from B to B is   0   Path: B

Enter start and end vertices: A C
    Minimum path from A to C is  10   Path: A  B  C
*/
