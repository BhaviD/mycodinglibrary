// prompt for the number of disks and call the function
// hanoi() to solve the Tower of Hanoi puzzle

#include <iostream>
#include <string>
#include "Hanoi/Hanoi.h"

using namespace std;

int main()
{
    // number of disks and the needle names
    int n;
    string beginneedle  = "A",
          middleneedle = "B",
          endneedle    = "C";

    // prompt for n and solve the puzzle for n disks
    cout << "Enter the number of disks: ";
    cin >> n;
    cout << "The solution for n = " << n << endl;
    hanoi(n, beginneedle, endneedle, middleneedle);

    return 0;
}
