/*
 * the program generates 12 random integers in the range
 * 100 to 999. add each number value to vector vSmall if
 * value < 400, to vector vMedium if 400 <= value < 700
 * and to vLarge if 700 <= value < 1000. 

 * apply the insertion sort to order each vector. 
 * use join() so that vSmall is the concatenation of the 
 * three vectors. sort the final list in vSmall by using 
 * the insertion sort. display the initial set of elements 
 * in each vector and the final sorted list by calling WriteVector()
**/

#include <iostream>
#include <vector>

#include "RandomNumber.h"
#include "InsertionSort.h"
#include "WriteContainer.h"         // for WriteVector()

using namespace std;

// attach vB onto the end of vA
template <typename T>
void join (vector<T> &vA, const vector<T>& vB);

// object of type GreaterThan<T> evaluate x > y
template <typename T>
class GreaterThan
{
    string comp_type{"GT"};
    public:
        string GetType() const
        {
            return comp_type;
        }

        bool operator()(const T& x, const T& y) const
        {
            return x > y;
        }
};

// object of type GreaterThan<T> evaluate x > y
template <typename T>
class LessThan
{
    string comp_type{"LT"};
    public:
        string GetType() const
        {
            return comp_type;
        }

        bool operator()(const T& x, const T& y) const
        {
            return x < y;
        }
};

template <typename Compare>
void Print_Sorted(vector<int>& vSmall,
                  vector<int>& vMedium,
                  vector<int>& vLarge,
                  Compare comp)
{
    // sort the vector of integers in the range
    // 100 <= n < 400 and output
    InsertionSort(vSmall, comp);
    cout << "Small:   ";
    WriteVector(vSmall);

    // sort the vector of integers in the range
    // 400 <= n < 700 and output
    InsertionSort(vMedium, comp);
    cout << "Medium:  ";
    WriteVector(vMedium);

    // sort the vector of integers in the range
    // 700 <= n < 1000 and output
    InsertionSort(vLarge, comp);
    cout << "Large:   ";
    WriteVector(vLarge);

    // join vMedium onto the end of vSmall
    //if(comp.GetType() == "GreaterThan")
    if(comp.GetType() == "GT")
    {
        join(vLarge, vMedium);
        // join vLarge onto the end of the modified vSmall
        join(vLarge, vSmall);

        // output the new vector
        cout << "Sorted (Descending Order):  ";
        WriteVector(vLarge);
        cout << endl;
    }
    else
    {
        join(vSmall, vMedium);
        // join vLarge onto the end of the modified vSmall
        join(vSmall, vLarge);

        // output the new vector
        cout << "Sorted (Ascending Order):  ";
        WriteVector(vSmall);
        cout << endl;
    }
}

int main()
{
    // declare 3 integer vectors
    vector<int> vSmall, vMedium, vLarge;
    // use a random number generator
    RandomNumber rnd;

    int i, value;

    for (i = 0; i < 12; i++)
    {
        value = rnd.random(900) + 100;

        if (value < 400)
            vSmall.push_back(value);
        else if (value < 700 )
            vMedium.push_back(value);
        else
            vLarge.push_back(value);
    }

    Print_Sorted(vSmall, vMedium, vLarge, GreaterThan<int>());

    vSmall.clear();
    vMedium.clear();
    vLarge.clear();

    for (i = 0; i < 12; i++)
    {
        value = rnd.random(900) + 100;

        if (value < 400)
            vSmall.push_back(value);
        else if (value < 700 )
            vMedium.push_back(value);
        else
            vLarge.push_back(value);
    }

    Print_Sorted(vSmall, vMedium, vLarge, LessThan<int>());

    #if 0
    // sort the vector of integers in the range
    // 100 <= n < 400 and output
    InsertionSort(vSmall, GreaterThan<int>());
    cout << "Small:   ";
    WriteVector(vSmall);

    // sort the vector of integers in the range
    // 400 <= n < 700 and output
    InsertionSort(vMedium, GreaterThan<int>());
    cout << "Medium:  ";
    WriteVector(vMedium);

    // sort the vector of integers in the range
    // 700 <= n < 1000 and output
    InsertionSort(vLarge, GreaterThan<int>());
    cout << "Large:   ";
    WriteVector(vLarge);

    // join vMedium onto the end of vSmall
    //join(vSmall, vMedium);
    // join vLarge onto the end of the modified vSmall
    //join(vSmall, vLarge);

    join(vLarge, vMedium);
    join(vLarge, vSmall);

    // output the new vector
    cout << "Sorted:  ";
    //WriteVector(vSmall);
    WriteVector(vLarge);
    #endif

    return 0;
}

template <typename T>
void join (vector<T> &vA, const vector<T>& vB)
{
    // capture the size of vB in sizeB
    int i, sizeB = vB.size();

    // use index i to access the elements of vB and push_back()
    // to add the elements to the rear of vA
   for (i = 0; i < sizeB; i++)
      vA.push_back(vB[i]);
}
