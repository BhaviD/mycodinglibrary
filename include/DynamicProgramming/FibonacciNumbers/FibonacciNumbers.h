#ifndef _FIBONACCI_NUMBERS_H_
#define _FIBONACCI_NUMBERS_H_

#include <vector>

// computation of the nth Fibonacci number using top down
// dynamic programming to avoid redundant recursive
// function calls
long long fib(int n, std::vector<long long>& fibList);

long long fib(int n, std::vector<long long>& fibList)
{
    long long fibValue;

    // check for a previously computed result and return
    if (fibList[n] >= 0)
        return fibList[n];
    
    // otherwise execute the recursive algorithm to obtain the result

    // stopping conditions
    if (n <= 1)
        fibValue = n;
    else
        // recursive step
        fibValue = fib(n - 1, fibList) + fib(n - 2, fibList);
    
    // store the result and return its value
    fibList[n] = fibValue;
    return fibValue; 
}


#endif  // _FIBONACCI_NUMBERS_H_
