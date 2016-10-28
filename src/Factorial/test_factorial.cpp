#include <iostream>
#include "Factorial/factorial.h"

using namespace std;

int main()
{
    int n = 0;
    long long fact = 0;
    cout << "Enter a positive integer <= 20 (-1 to exit): ";
    cin >> n;
    while(n != -1)
    {
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
        cout << "Enter a positive integer <= 20 (-1 to exit): ";
        cin >> n;
    }
    return 0;
}
