// Build command:
// g++ test_factorial.cpp -std=c++11 -I../../include/Factorial

#include <iostream>
#include "factorial.h"

using namespace std;

int main()
{
    int n = 0;
    long long fact = 0;
    cout << "Enter 4 positive integers [0, 20]: ";
    for(int i = 0; i < 4; ++i)
    {
        cin >> n;
        if(n > 20)
        {
            cerr << "Invalid Input [n = " << n << "] !!" << endl;
            cerr << "Please enter n < 20!!\n";
            continue;
        }
        if((fact = RecursiveFactorial(n)) != -1)
        {
            cout << n << "! = " << fact << "    (recursive computation)" << endl;
            cout << n << "! = " << IterativeFactorial(n) << "    (iterative computation)" << endl;
        }
    }
    return 0;
}
