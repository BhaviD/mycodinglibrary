#include <iostream>
#include <iomanip>      // std::setfill

using namespace std;

int main()
{
    char currFill = cout.fill();        // get the current fill character
    char zeroFill;
    cout << setfill('0') << setw(10);   // Sets '0' as the stream's fill character.
    cout << 77 << endl;
    cout << 77 << endl;                 // width = 10 lost after the first cout
    
    cout.fill(currFill);                // same as setfill
    cout << setw(10) << 77 << endl;
    cout.fill('0');
    cout << setw(10) << 77 << endl;

    zeroFill = cout.fill(currFill);     // fill(char fillch) returns the current fill character
    cout << setw(10) << 77 << endl;

    cout.fill(zeroFill);
    cout << setw(10) << 77 << endl; 
    
    return 0;    
}
