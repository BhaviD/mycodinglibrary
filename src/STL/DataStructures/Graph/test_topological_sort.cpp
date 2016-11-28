// the program inputs a directed acyclic graph that describes course
// prerequisites in a religious studies department. it performs
// a Topological sort and outputs the result as a possible schedule
// of courses

#include <iostream>
#include <string>
#include <list>

#include "Graph.h"
#include "WriteContainer.h"

using namespace std;

int main()
{
    // graph specifying the courses and prerequisite edges
    Graph<string> g;

    // a list holding the Topological order of courses
    list<string> tlist;

    // input file holding the vertex strings and edges
    // open the file and input the graph
    ifstream graphIn("courses.dat");
    if(!graphIn)
    {
        cerr << "Couldn't open file!!!" << endl;
        return 1;
    }

    graphIn >> g;

    // execute a Topological sort; store results in list
    TopologicalSort(g, tlist);

    // output the list of possible courses 
    cout << "Possible schedule of courses"
          << endl << "    ";
    WriteContainer(tlist.begin(), tlist.end());
    cout << endl;

    return 0;
}

/*
Run:

Possible schedule of courses
    R51  R53  R173  R151  R37  R137  R63  R263
*/
