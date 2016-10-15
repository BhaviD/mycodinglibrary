// Build Command:
// g++ test_selection_sort.cpp -std=c++11 -I../../../include/Sorting/SelectionSort/ -I../../../include/Timer

#include <iostream>
#include "SelectionSort.h"
#include "Timer.h"

using namespace std;

int main()
{
    int arr1[14] = {23, 20, 59, 81, 12, 43, 62, 9, 52, 4, 89, 1, 34, 47};
    int arr2[14] = {23, 20, 59, 81, 12, 43, 62, 9, 52, 4, 89, 1, 34, 47};
    int i = 0;
    Timer t;

    cout << "Original Array" << endl;
    for(int i = 0; i < 14; ++i)
        cout << arr1[i] << " ";
    cout << endl << endl;

    t.start();
    SelectionSort(arr1, 14);
    t.stop();
    cout << "Selection Sort took: " << t.duration_in_microseconds() << " microseconds" << endl;
    for(int i = 0; i < 14; ++i)
        cout << arr1[i] << " ";
    cout << endl << endl;

    t.start();
    DoubleEndedSelectionSort(arr2, 14);
    t.stop();
    cout << "Double Ended Selection Sort took: " << t.duration_in_microseconds() << " microsseconds" << endl;
    for(int i = 0; i < 14; ++i)
        cout << arr2[i] << " ";
    cout << endl << endl;
    return 0;
}
