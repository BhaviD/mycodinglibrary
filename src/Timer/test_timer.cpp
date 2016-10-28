#include <iostream>
#include "Timer/Timer.h"
using namespace std;

void consume_time()
{
    int i = 0;
    while(i++ < 100000)
        cout << "consuming time [" << i << "]\n";
}

int main()
{
    Timer t;
    t.start();
    consume_time();
    t.stop();

    cout << "The function took " << t.duration_in_microseconds() << " microseconds\n";
    cout << "The function took " << t.duration_in_milliseconds() << " milliseconds\n";
    cout << "The function took " << t.duration_in_seconds() << " seconds\n";

    return 0;
}
