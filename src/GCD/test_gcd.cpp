// Build Command:
// g++ test_gcd.cpp -I../../include/GCD

// the program prompts the user to input a rational
// number in the form p/q and displays it as a mixed number.

#include <iostream>
#include "GCD.h"

using namespace std;

int main()
{
    int numerator, denominator, wholePart, remainder, divisor;
    char slash;

    cout << "Enter a rational number (numerator/denominator): ";
    cin >> numerator >> slash >> denominator;

    // compute the quotient (whole part) and the remainder
    wholePart = numerator / denominator;
    remainder = numerator % denominator;

    if (remainder == 0)
        // the rational number is an integer
        cout << wholePart << endl;
    else
    {
        // number in mixed form is "wholePart remainder/divisor"
        // output wholePart if it is not 0
        if (wholePart != 0)
            cout << wholePart << ' ';

        // compute the greatest common divisor of the remainder
        // and the divisor
        divisor = gcd(remainder, denominator);
        // output the fractional part in lowest terms by dividing
        // the remainder and divisor by their gcd
        cout << remainder/divisor << '/' << denominator/divisor
              << endl;
    }

    return 0;
}
