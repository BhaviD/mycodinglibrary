#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string str;
    ifstream fin("getline_input.txt");
    fin >> str;
    cout << "value of str using >> operator: " << str << endl;
    fin.seekg(0, ios::beg);
    getline(fin, str);
    cout << "value of str using getline: " << str << endl;
    return 0;
}
