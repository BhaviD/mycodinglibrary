#ifndef _POW_H_
#define _POW_H_

enum class Computation_Method {Iterative, Recursive};

long long IterativePow(int x, int n);
long long RecursivePow(int x, int n);

long long IterativePow(int x, int n)
{
    long long res = 1;

    while(n > 0)
    {
        // If n is odd, multiply x with result
        if(n & 1)
            res *= x;

        // n must be even now
        n >>= 1;    // n /= 2;
        x *= x;     // x = x ^ 2;
    }
    return res;
}

long long RecursivePow(int x, int n)
{
    long long temp;
    if(n == 0)
        return 1;

    temp = RecursivePow(x, n / 2);
    if(n % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}

long long Pow(int x, int n, Computation_Method method)
{
    return method == Computation_Method::Iterative ? IterativePow(x, n) : RecursivePow(x, n);
}

#endif
