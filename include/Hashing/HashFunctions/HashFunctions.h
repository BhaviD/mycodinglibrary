#ifndef _HASH_FUNCTIONS_H_
#define _HASH_FUNCTIONS_H_

#include <string>
#include <cmath>

using namespace std;

class hFintID
{
    public:
        unsigned int operator()(int item) const
        { return (unsigned)item; }
};

class hFint
{
    public:
        unsigned int operator()(int item) const
        {
            unsigned int value = (unsigned int)item;

            value *= value;         // square the value
            value >>= 8;            // discard the low order 8 bits
            return value % 65536;   // return result in range 0 to 65535
        }
};

class hFreal
{
    public:
        unsigned int operator()(double item) const
        {
            int exp;
            double mant;
            unsigned int hashval;

            if (item == 0)
                hashval = 0;
            else
            {
                mant = frexp(item,&exp);
                hashval = (unsigned int)((2 * fabs(mant) -1) * (unsigned int)~0);
            }
            return hashval;
        }
};

class hFstring
{
    public:
        unsigned int operator()(const string& item) const
        {
            unsigned int prime = 2049982463;

            int n = 0, i;

            for (i = 0; i < item.length(); i++)
                n = n * 8 + item[i];

            return n > 0 ? (n % prime) : (-n % prime);
        }
};

#endif  // _HASH_FUNCTIONS_H_

