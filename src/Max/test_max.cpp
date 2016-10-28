/* This test displayes the use of e_max() in two ways
 *  (1) get the reference to the greater variable.
 *  (2) get the copy of the greater variable.
 *
 *  (1) is only possible because e_max() returns a reference to
 *  template variable T (check its prototype).
 *
 *  Hence, always return a reference from max() function.
 */

#include <iostream>
#include <string>
#include "Max/Max.h"
using namespace std;

int main()
{
    int x = 10, y = 20;
    int& greater1 = e_max(x, y);
    greater1++;
    cout << "greater1 = " << greater1 << "            --> same as y" << endl;
    cout << "y = " << y << endl;

    int greater2 = e_max(x, y);
    greater2++; 
    cout << "greater2 = " << greater2 << "            --> different from y"<< endl;
    cout << "y = " << y << endl;

    string str1 = "Hello", str2 = "World";
    string& strGreater1 = e_max(str1, str2);
    strGreater1[0] = 'A'; 
    cout << "strGreater1 = " << strGreater1 << "      --> same as str2" << endl; 
    cout << "str2 = " << str2 << endl;

    string strGreater2 = e_max(str1, str2);
    strGreater2[0] = 'A'; 
    cout << "strGreater2 = " << strGreater2 << "      --> different from str1" << endl; 
    cout << "str1 = " << str1 << endl;

    return 0;
}
