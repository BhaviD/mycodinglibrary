/* Prototypes:
 * void insert(int start, const string &s);
 * void erase(int start = 0, int count = -1);
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "endfile";
    cout << "str = " << str << endl;
    string s = "string object type";
    str += " mark";
    str.insert(3, "-of-");  // str is "end-of-file mar"
    cout << "after insert and append, str = " << str << endl;
    cout << "s = " << s << endl;
    s.erase(7, 7);          // s is "string type"
    cout << "after erase oprn, s = " << s << endl;
    // erase 4 characters beginning at index 3
    s.erase(3, 4);
    cout << "Finally s = " << s << endl;

    return 0;
}
