#include <iostream>
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "ShellSort.h"
#include "Timer.h"
#include "WriteContainer.h"

using namespace std;

int main()
{
    vector<int> vec1{14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> vec2{14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> vec3{14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int i = 0;
    Timer t;

    cout << "Original Array" << endl;
    WriteVector(vec1);
    cout << endl;

    t.start();
    BubbleSort(vec1);
    t.stop();
    cout << "Bubble Sort took: " << t.duration_in_microseconds() << " microseconds" << endl;
    WriteVector(vec1);
    cout << endl;

    t.start();
    DoubleEndedSelectionSort(vec2);
    t.stop();
    cout << "Double Ended Selection Sort took: " << t.duration_in_microseconds() << " microsseconds" << endl;
    WriteVector(vec2);
    cout << endl;

    t.start();
    ShellSort(vec3);
    t.stop();
    cout << "Shell Sort took: " << t.duration_in_microseconds() << " microsseconds" << endl;
    WriteVector(vec3);
    cout << endl;
    return 0;
}
