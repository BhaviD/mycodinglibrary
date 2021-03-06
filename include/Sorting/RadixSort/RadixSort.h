#ifndef _RADIX_SORT_H_
#define _RADIX_SORT_H_

#include <vector>
#include <queue>

// support function for RadixSort()
// distribute vector elements into one of 10 queues
// using the digit corresponding to power
//   power = 1    ==> 1's digit
//   power = 10   ==> 10's digit
//   power = 100  ==> 100's digit
//   ...
void distribute(const std::vector<int>& v, std::queue<int> digitQueue[],
                int power)
{
    int i, vec_size = v.size();

    // loop through the vector, inserting each element into
    // the queue (v[i] / power) % 10
    for (i = 0; i < vec_size; i++)
        digitQueue[(v[i] / power) % 10].push(v[i]);
}

// support function for RadixSort()
// gather elements from the queues and copy back to the vector
void collect(std::queue<int> digitQueue[], std::vector<int>& v)
{
    int i = 0, digit;

    // scan the vector of queues using indices 0, 1, 2, etc.
    for (digit = 0; digit < 10; ++digit)
    {
        // collect items until queue empty and copy items back
        // to the vector
        while (!digitQueue[digit].empty())
        {
            v[i] = digitQueue[digit].front();
            digitQueue[digit].pop();
            ++i;
        }
    }
}

void RadixSort(std::vector<int>& v, int d)
{
    int i, power = 1;
    std::queue<int> digitQueue[10];

    for (i = 0; i < d; i++)
    {
        distribute(v, digitQueue, power);
        collect(digitQueue, v);
        power *= 10;
    }
}

#endif
