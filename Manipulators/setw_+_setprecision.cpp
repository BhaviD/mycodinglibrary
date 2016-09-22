#include <iostream>
#include <iomanip>      // std::setw
using namespace std;

int main () 
{
    cout << setw(10);
    cout << 77 << endl;
    cout << 99 << endl;
    
    double f = 3.141592653589;
    streamsize ss = cout.precision();
    cout << "Initial precision = " << ss << endl;
    cout << "Value = " << f << endl;
    cout << setw(10) << setprecision(4) << f << endl;

    cout.precision (10);
    cout << "Longer value = " << f << endl;

    cout.precision (ss);
    cout << "Original value = " << f << endl;

    cout << "Longer and original value = "
        << setprecision(10) << f << ' '
        << setprecision(ss) << f << endl;

    cout << fixed;
    cout << "Original value = " << f << endl;
    return 0;
}
