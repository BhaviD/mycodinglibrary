// Build Command - 
// g++ test_pow.cpp -std=c++11 -I../../include/Pow\(x,n\)_in_log\(n\) -I../../include/Timer

#include <iostream>
#include "Timer.h"
#include "Pow.h"
using namespace std;

int main()
{
    timer t;
    t.start();
    cout << "x = " << Pow(3, 30, Computation_Method::Iterative) << endl;
    t.stop();
    cout << "IterativePow took " << t.duration_in_microseconds() << " microseconds\n";
    
    t.start();
    cout << "x = " << Pow(3, 30, Computation_Method::Recursive) << endl;
    t.stop();
    cout << "RecursivePow took " << t.duration_in_microseconds() << " microseconds\n";

    return 0;
}
