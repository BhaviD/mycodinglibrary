#include <iostream>
#include <iomanip>      // std::setw
using namespace std;

int main () 
{
    cout << setw(10);
    cout << 77 << "          -->  width = 10\n";
    cout << 99 << "          -->  setw is not \"Sticky\"\n";
    
    double f = 3.141592653589;
    streamsize ss = cout.precision();       // save original precision value
    ios_base::fmtflags flags = cout.flags();    // save original iosflags
    cout << "Initial precision = " << ss << endl;
    cout << "Value = " << f << endl;
    cout << setprecision(4) << f << "    -->  setprecision(4) rounds off the value\n";

    cout.precision (13);
    cout << "Longer value = " << f << endl;
    cout << "Longer value = " << f << "       --> setprecision is \"Sticky\"\n";

    cout.precision (ss);
    cout << "Original precision restored = " << f << endl;

    cout << "Longer and original precision values = "
        << setprecision(10) << f << ' '
        << setprecision(ss) << f << endl;

    cout << fixed;
    cout << "Using std::fixed with original precision = " << setprecision(ss) << f << endl;
    cout.flags(flags);
    cout << "Restoring original iosflags = " << f << endl;
    return 0;
}
