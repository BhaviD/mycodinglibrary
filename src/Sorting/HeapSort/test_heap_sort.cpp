// program creates 15-element vector of integers in range 0 to 99.
// a call to HeapSort with greater<int>() object sorts vector in
// ascending order; second call to HeapSort() with less<int>()
// sorts the list in descending order; output displays original
// list and the ordered lists

#include <iostream>
#include <vector>
#include <functional>

#include "HeapSort.h"
#include "WriteContainer.h"
#include "RandomNumber.h"

using namespace std;

int main()
{
    // objects to store the elements and generate random numbers
    vector<int> v;
    RandomNumber rnd;
    int i;

    // create a vector with 15 random integers
    for (i = 0; i < 15; i++)
        v.push_back(rnd.random(100));

    // display the original list
    cout << "Original vector" << endl << "   ";
    WriteVector(v);
    cout << endl;

    // call HeapSort() with greater<int>() and display results
    cout << "Sort in ascending order" << endl << "   ";
    HeapSort(v, greater<int>());
    WriteVector(v);
    cout << endl;

    // call HeapSort() with less<int>() and display results
    cout << "Sort in descending order" << endl << "   ";
    HeapSort(v, less<int>());
    WriteVector(v);
    cout << endl;

    return 0;
}
