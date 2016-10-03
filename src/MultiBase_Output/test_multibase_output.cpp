#include <iostream>
#include <string>
#include "Multibase_Output.h"

using namespace std;

int main()
{
    int number, base;

    // prompt for number and base
    cout << "Input number and base:  ";
    cin >> number >> base;

    if ((base >= 2 && base <= 10) || (base == 16))
    {
        // output statement with function call 
        cout << "    " << number << " (base 10) = ";
        displayInBase(number,base);
        cout << " (base " << base << ")" << endl;
    }
    else
        cout << "The base must be in the range 2 <= base <= 10 or base should be 16!!" << endl;
    
    return 0;
}
