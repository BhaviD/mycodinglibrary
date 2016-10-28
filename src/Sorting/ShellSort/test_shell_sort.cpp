#include <iostream>
#include "Sorting/BubbleSort/BubbleSort.h"
#include "Sorting/SelectionSort/SelectionSort.h"
#include "Sorting/ShellSort/ShellSort.h"
#include "Sorting/InsertionSort/InsertionSort.h"
#include "Timer/Timer.h"
#include "WriteContainer/WriteContainer.h"
#include "RandomNumber/RandomNumber.h"

using namespace std;

#define VEC_SIZE 2000

int main()
{
    RandomNumber rnd;
    Timer t;
    vector<int> vec1, vec2, vec3, vec4;

    for(int i{}; i < VEC_SIZE; ++i)
        vec1.push_back(rnd.random(1000));

    vec2 = vec3 = vec4 = vec1;

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
    InsertionSort(vec3);
    t.stop();
    cout << "Insertion Sort took: " << t.duration_in_microseconds() << " microsseconds" << endl;
    WriteVector(vec3);
    cout << endl;
 
    t.start();
    ShellSort(vec4);
    t.stop();
    cout << "Shell Sort took: " << t.duration_in_microseconds() << " microsseconds" << endl;
    WriteVector(vec4);
    cout << endl;
    return 0;
}
