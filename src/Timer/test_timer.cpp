// Build command: 
// g++ test_timer.cpp -std=c++11 -I../../include/Timer

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

    cout << "The function took " << t.duration_in_microseconds() << " microseconds\n";
    cout << "The function took " << t.duration_in_milliseconds() << " milliseconds\n";
    cout << "The function took " << t.duration_in_seconds() << " seconds\n";

    return 0;
}
