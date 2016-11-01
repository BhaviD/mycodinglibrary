#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string str, userName, userPwd;
    ifstream fin("getline_input.txt");
    // >> operator stops at the first white space.
    fin >> str;
    cout << "value of str using >> operator: " << str << endl;
    fin.seekg(0, ios::beg);
    
    // gets the entire line till the default delimiter '\n'
    getline(fin, str);
    cout << "value of str using getline: " << str << endl;

    getline(fin, userName, ':');
    getline(fin, userPwd);

    cout << "UserName = " << userName << endl
         << "UserPwd = " << userPwd << endl;
    return 0;
}
