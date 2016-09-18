#include <ctime>
#include "Random.h"

randomNumber::randomNumber(long s) : seed{s}
{
    if(seed == 0)
    {
        seed = ((long)time(0) % M);
    }
}

long randomNumber::random()
{
    long long product = A * seed;
    seed = (long)(product % M);
    return seed;
}

long randomNumber::random(long n)
{
    long randomNo = random();
    return randomNo % n;
}

double randomNumber::frandom()
{
    long randomNo = random();
    return (double)randomNo / M;
}
