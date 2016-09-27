#ifndef _TIMER_H_
#define _TIMER_H_

#include <chrono>

using CLOCK = std::chrono::steady_clock;
using us = std::chrono::microseconds;
using ms = std::chrono::milliseconds;
using s = std::chrono::seconds;

class timer
{
    public:
        // initialize the timer.
        // Postconditions: set the starting and ending event times to 0.
        timer();
        
        // start timing an event.
        // Postcondition:   record the current time as the starting time
        void start();

        // stop timing an event.
        // Postconditon:    record the current time as the ending time
        void stop();

        // return the time the event took in milliseconds by computing
        // the difference between the ending and starting times
        int duration_in_millisec() const;

        // return the time the event took in microseconds by computing
        // the difference between the ending and starting times
        int duration_in_microsec() const;

        // return the time the event took in seconds by computing
        // the difference between the ending and starting times
        int duration_in_sec() const;

    private:
        CLOCK::time_point startTime, endTime;
};

// constructor. set starting and ending times to 0
timer::timer(): startTime{}, endTime{}
{}

// determine clock ticks at start
void timer::start()
{
   startTime = CLOCK::now();
}

// determine clock ticks at end
void timer::stop()
{
   endTime = CLOCK::now();
}

// return the elapsed time in microseconds
int timer::duration_in_microsec() const
{
   return std::chrono::duration_cast<us>(endTime - startTime).count();
}

// return the elapsed time in milliseconds
int timer::duration_in_millisec() const
{
   return std::chrono::duration_cast<ms>(endTime - startTime).count();
}

// return the elapsed time in seconds
int timer::duration_in_sec() const
{
   return std::chrono::duration_cast<s>(endTime - startTime).count();
}

#endif
