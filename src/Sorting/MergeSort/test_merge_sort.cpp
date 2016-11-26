// the program initializes a vector of integers and a vector of strings.
// it then applies the function MergeSort() to each vector and outputs
// the result 

#include <iostream>
#include <string>
#include <vector>

#include "MergeSort.h"
#include "WriteContainer.h"     // for WriteContainer()

using namespace std;

int main()
{
    // create an array of integers and of strings for the sort
    vector<int> vInt {25, 10, 7, 19, 3, 48, 12, 17, 56, 30, 21};

    vector<string> vStr{"Dallas","Akron","Wausau","Phoenix",
                                "Fairbanks","Miami"};

    // sort and the output each vector 
    MergeSort(vInt, 0, vInt.size());
    cout << "Sorted integers: ";
    WriteContainer(vInt.begin(), vInt.end(), "  ");
    cout << endl;

    MergeSort(vStr, 0, vStr.size());
    cout << "Sorted strings:  ";
    WriteContainer(vStr.begin(), vStr.end() , "  ");
    cout << endl;

    return 0;
}

/*
Run:

Sorted integers: 3  7  10  12  17  19  21  25  30  48  56
Sorted strings:  Akron  Dallas  Fairbanks  Miami  Phoenix  Wausau
*/
