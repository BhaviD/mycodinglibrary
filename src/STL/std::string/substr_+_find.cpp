/* Prototypes:
 * string substr(int start = 0, int count = -1)
 * int find(const string &s, int start = 0);
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string fullname = "Mark Tompkin", firstname, lastname;
    int index;

    index = fullname.find_last_of(' ');  // index is 4
    // firstname = "Mark" lastname = "Tompkin"
    firstname = fullname.substr(0, index);
    lastname = fullname.substr(index + 1);
    cout << "Firstname = " << firstname << endl
         << "Lastname = " << lastname << endl;
    index = fullname.find("kin");       // index is 9
    cout << "kin starts at index " << index << endl;
    index = fullname.find("omp", 0);    // index is 6
    cout << "omp starts at index " << index << endl;
    index = fullname.find("omp", 7);    // index is -1
    cout << "index 7 onwards omp is at " << index << endl;

    return 0;
}
