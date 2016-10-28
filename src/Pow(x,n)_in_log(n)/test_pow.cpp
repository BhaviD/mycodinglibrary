#include <iostream>
#include "Timer/Timer.h"
#include "Pow(x,n)_in_log(n)/Pow.h"
using namespace std;

int main()
{
    Timer t;
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
