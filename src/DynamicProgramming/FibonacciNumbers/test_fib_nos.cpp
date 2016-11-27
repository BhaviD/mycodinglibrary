#include <iostream>
#include <algorithm>
#include "FibonacciNumbers.h"

using namespace std;

int main()
{
    int n = 0;
    long long nFib = 0;
    vector<long long> fibVec(91, -1);
    cout << "Enter a positive integer <= 90 (-1 to exit): ";
    cin >> n;
    while(n != -1)
    {
        nFib = fib(n, fibVec);
        cout << "fib(" << n << ") is " << fib(n, fibVec) << endl;
        cout << "Enter a positive integer <= 90 (-1 to exit): ";
        cin >> n;
    }
    return 0;
}
