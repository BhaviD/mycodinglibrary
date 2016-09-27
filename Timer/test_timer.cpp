// Build command: 
// g++ -std=c++11 test_timer.cpp

#include <iostream>
#include "Timer.h"
using namespace std;

void consume_time()
{
    int i = 0;
    while(i++ < 100000)
        cout << "consuming time [" << i << "]\n";
}

int main()
{
    timer t;
    t.start();
    consume_time();
    t.stop();

    cout << "The function took " << t.duration_in_microsec() << " microseconds\n";
    cout << "The function took " << t.duration_in_millisec() << " milliseconds\n";
    cout << "The function took " << t.duration_in_sec() << " seconds\n";

    return 0;
}
