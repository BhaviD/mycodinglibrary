#ifndef _FACTORIAL_H_
#define _FACTORIAL_H_

//#include <iostream>

// n is a non-negative integer
long long RecursiveFactorial(int n)
{
    if(n < 0)
    {
        std::cerr << "Invalid Input [n = " << n << " ] !!\n"; 
        return -1;
    }
    if(n == 0)
        return 1;
    else
        return n * RecursiveFactorial(n - 1);
}

long long IterativeFactorial(int n)
{
    if(n < 0)
    {
        std::cerr << "Invalid Input [n = " << n << " ] !!\n"; 
        return -1;
    }

    long long fact = 1;
    while(n > 0)
    {
        fact *= n;
        --n;
    }
    return fact;
}

#endif
