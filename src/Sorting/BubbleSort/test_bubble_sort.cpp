#include <iostream>
#include "Sorting/BubbleSort/BubbleSort.h"
#include "Sorting/SelectionSort/SelectionSort.h"
#include "RandomNumber/RandomNumber.h"
#include "WriteContainer/WriteContainer.h"
#include "Timer/Timer.h"

using namespace std;

#define VEC_SIZE 2000

int main()
{
    RandomNumber rnd;
    Timer t;
    vector<int> intVec1, intVec2;

    for(int i{}; i < VEC_SIZE; ++i)
        intVec1.push_back(rnd.random(1000));

    intVec2 = intVec1;

    cout << "Original Array" << endl;
    WriteVector(intVec1);

    t.start();
    BubbleSort(intVec1);
    t.stop();
    cout << "Bubble Sort took: " << t.duration_in_microseconds() << " microseconds" << endl;
    WriteVector(intVec1);

    t.start();
    DoubleEndedSelectionSort(intVec2);
    t.stop();
    cout << "Double Ended Selection Sort took: " << t.duration_in_microseconds() << " microsseconds" << endl;
    WriteVector(intVec2);
    return 0;
}
