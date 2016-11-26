// File: prg15_4.cpp
// the program prompts for an integer n and
// initializes a vector with the values {1,2,3,...,n}.
// it then calls the recursive function permute() that
// displays all n! permutations of the numbers 1 .. n

#include <iostream>
#include <vector>

#include "Permute.h"     // for Permute()

using namespace std;

int main()
{
    int n,i;
    vector<int> permList;
            
    cout << "Enter the size of the permutation list: ";
    cin >> n;

    for (i = 1; i <= n; i++)
        permList.push_back(i);    // initialize the vector
    cout << endl;

    // start creating permutation ordering at index 0
    Permute(permList, 0);
                
    return 0;
}

/*
Run:

Enter the size of the permutation list: 3

1  2  3
1  3  2
2  1  3
2  3  1
3  1  2
3  2  1
*/
