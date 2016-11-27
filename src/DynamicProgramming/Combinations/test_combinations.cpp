#include <iostream>
#include <algorithm>
#include "Combinations.h"

using namespace std;

int main()
{
    int n = 0, k = 0;
    int nComm = 0;
    Matrix<int> commMat(101, 101);
    cout << "Enter values of 0 <= (n, k) <= 100 (-1 -1 to exit): ";
    cin >> n >> k;
    while(n != -1)
    {
        cout << "comm(" << n << ", " << k << ") is " << comm(n, k, commMat) << endl;
        cout << "Enter values of 0 <= (n, k) <= 100 (-1 -1 to exit): ";
        cin >> n >> k;
    }
    return 0;
}
