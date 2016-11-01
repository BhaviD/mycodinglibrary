#include <iostream>
#include "MultibaseOutput.h"

using namespace std;

int main()
{
    int num, b; // decimal number and base

    // prompt for a non-negative number and the desired base 2 <= B <= 16
    cout << "Enter a non-negative decimal number and base "
          << "(2 <= B <= 16)" << endl << "or 0 0 to terminate: ";
    cin >> num >> b;

    // continue until the user enters a base of 0
    while (b != 0)
    {
        cout << "    " << num << " base " << b << " is "
              << MultibaseOutput(num, b) << endl;

        cout << "Enter a non-negative decimal number and base "
              << "(2 <= B <= 16)" << endl << "or 0 0 to terminate: ";
        cin >> num >> b;
    }
    return 0;
}
