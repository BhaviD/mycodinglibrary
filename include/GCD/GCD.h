#ifndef _GCD_H_
#define _GCD_H_

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

#endif
