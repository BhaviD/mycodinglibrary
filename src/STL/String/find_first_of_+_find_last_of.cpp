/* Prototypes:
 * int find_first_of(char c, int start = 0);
 * int find_last_of(char c);
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "Mississippi";
    int index;

    // 's' occurs at indices 2, 3, 5, 6
    index = str.find_first_of('s', 0);
    cout << index << " ";
    index = str.find_first_of('s', 4);
    cout << index << " ";
    index = str.find_first_of('s', 7);
    cout << index << " ";

    // last occurence of 's' is at index = 6
    index = str.find_last_of('s');

    // the while loop outputs the index of each 'i'.
    index = 0;
    while((index = str.find_first_of('i', index)) != -1)
    {
        cout << "index " << index << " ";
        index++;
    }
    cout << endl;
    return 0;
}
