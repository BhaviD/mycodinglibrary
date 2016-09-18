#ifndef _RANDOM_H_
#define _RANDOM_H_

// generate random numbers
class randomNumber
{
public:
    // initialize the random number generator
    randomNumber(long s = 0);

    // return a 32-bit random integer m, 1 <= m <= 2^31-2
    long random();

    // return a 32-bit random integer m, 0 <= m <= n-1,
    // where n <= 2^31-1
    long random(long n);

    // return a real number x, 0 <= x < 1
    double frandom();

private:
    long seed;
    static const long A = 48271;
    static const long M = 2147483647;
//    static const long Q = M / A;
//    static const long R = M % A;
};

#endif
