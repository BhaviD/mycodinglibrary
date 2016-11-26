// the program compares the performance of heapsort, mergesort,
// quicksort, and the insertion sort. vectors v1,v2,v3, and v4
// are initialized with the same 100,000 random numbers in the
// range 0 to 999999. the program calls the function TimeSort()
// with each vector as an argument and arguments that identify
// the sorting algorithm. the function times the sorting of the
// vector and calls outputFirst_Last() to display the first and
// last 5 values in the sorted vector. the function TimeSort()
// then outputs the name of the sorting algorithm and the time
// it required to sort the vector. the program illustrates the
// general superiority of quicksort and the excellent speed
// of heapsort. mergesort has a slower time because it is not an
// in-place sorting algorithm. the results vividly contrast an
// O(n log n) algorithm with the quadratic insertion sort algorithm

#include <iostream>
#include <string>
#include <vector>
#include <functional>         // greater<T> for HeapSort()

#include "RandomNumber.h"         // RandomNumber class
#include "HeapSort.h"         // vector sorting algorithms
#include "MergeSort.h"
#include "QuickSort.h"
#include "InsertionSort.h"
#include "Timer.h"            // Timer class

using namespace std;

// outputs the first 5 and last 5 items in the vector
void outputFirst_Last(const vector<int>& v);

// types of sorts we will test
enum sortType {HEAPSORT, MERGESORT, QUICKSORT, INSERTIONSORT};

// apply the specified sort to v and time it.
// output the result using sortName as a descriptive
// label
void TimeSort(vector<int>& v , sortType sort,
              const string& sortName);

int main()
{
    const int VECTORSIZE = 100000;
    vector<int> v1, v2, v3, v4;    
    int rndNum, i;
    RandomNumber rnd;    

    // load the vectors with the same sequence of 100000
    // random numbers in the range 0 to 999999
    for(i = 0; i < VECTORSIZE; i++)
    {
        rndNum = rnd.random(1000000);
        v1.push_back(rndNum);
        v2.push_back(rndNum);
        v3.push_back(rndNum);
        v4.push_back(rndNum);
    }
     
    // time heap sort
    TimeSort(v1, HEAPSORT, "Heap sort");

    // repeat process for the merge sort
    TimeSort(v2, MERGESORT, "Merge sort");

    // repeat process for the quick sort
    TimeSort(v3, QUICKSORT, "Quick sort");

    // repeat process for the insertion sort
    TimeSort(v4, INSERTIONSORT, "Insertion sort");
   
    return 0;
}

void outputFirst_Last(const vector<int>& v)
{
    // capture vector size in n
    int i, n = v.size(), m = 5;
    
    // if the vector size is 10 or less, just
    // output the whole vector
    if (n <= 10)
        m = n;

    // output m elements
    for(i = 0; i < m; i++)
        cout << v[i] << "  ";

    // for n > 10, output "..." and the last 5 elements
    if (n > 10)
    {
        cout << ". . .  ";
        for(i = n - 5; i < n; i++)
            cout << v[i] << "  ";
    }
    cout << endl;
}

void TimeSort(vector<int>& v, sortType sort,
                  const string& sortName)
{
    Timer t;

   // start timing and then sort vector arr
   t.start();

   switch(sort)
    {
        case HEAPSORT:    HeapSort(v, greater<int>());
                          break;
        case MERGESORT:   MergeSort(v, 0, v.size());
                          break;
        case QUICKSORT:   QuickSort(v, 0, v.size());
                          break;
        case INSERTIONSORT:  InsertionSort(v);
                             break;
    }
    t.stop();
    
    // output the first 5 and last 5 elements of sorted vector
    outputFirst_Last(v);

    cout << sortName << " time is " << t.duration_in_milliseconds() << " milliseconds" << endl << endl;
}

/*
Run:

8  11  45  55  61  . . .  999956  999961  999969  999972  999985
Heap sort time is 0.07

8  11  45  55  61  . . .  999956  999961  999969  999972  999985
Merge sort time is 0.39

8  11  45  55  61  . . .  999956  999961  999969  999972  999985
Quick sort time is 0.04

8  11  45  55  61  . . .  999956  999961  999969  999972  999985
Insertion sort time is 33.909
*/
