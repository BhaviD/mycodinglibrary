#include <iostream>
#include <vector>
#include "QuickSort.h"
#include "WriteContainer.h"

using namespace std;

int main()
{
    vector<int> vec{34, 63, 223, 46, 29, 10, 83, 19, 38};
    int k = 0;

    cout << "Vector: " << endl;
    WriteContainer(vec.begin(), vec.end()); 
    cout << "\n\nSize of vector = " << vec.size() << endl;

    cout << "Enter the value of k: ";
    cin >> k;
    
    cout << "\nResult of find(" << k << ") is " << findK(vec, 0, vec.size(), k) << endl;
    
    QuickSort(vec, 0, vec.size());
    cout << "Sorted Vector: " << endl;
    WriteVector(vec);
    return 0;
}
