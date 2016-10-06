// Build Command:
// g++ test_bubble_sort.cpp -std=c++11 -I../../../include/Sorting/BubbleSort/ -I../../../include/Sorting/SelectionSort -I../../../include/Timer

#include <iostream>
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "Timer.h"

using namespace std;

int main()
{
    int arr1[14] = {14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arr2[14] = {14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int i = 0;
    Timer t;

    cout << "Original Array" << endl;
    for(int i = 0; i < 14; ++i)
        cout << arr1[i] << " ";
    cout << endl << endl;

    t.start();
    BubbleSort(arr1, 14);
    t.stop();
    cout << "Bubble Sort took: " << t.duration_in_microseconds() << " microseconds" << endl;
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
