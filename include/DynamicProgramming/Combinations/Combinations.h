#ifndef _COMBINATIONS_H_
#define _COMBINATIONS_H_

#include "Matrix.h"

// computation of C(n,k) using top down dynamic programming
// to avoid redundant recursive function calls
int comm(int n, int k, Matrix<int>& commMat);

// computation of C(n,k) using bottom up dynamic programming
int commB(int n, int k);

int comm(int n, int k, Matrix<int>& commMat)
{
    int commValue;

    // check if value is already computed
    if (commMat[n][k] != 0)
        return commMat[n][k];

    if (n == k || k == 0)                       
        commValue = 1;
    else if (k == 1)
        commValue = n;                                        
    else
        // carry out the recursive step
        commValue = comm(n - 1, k, commMat) + comm(n - 1, k - 1, commMat);
    
    // before returning, assign value to the matrix
    commMat[n][k] = commValue;

    return commValue; 
}

int commB(int n, int k)
{
    // store all precomputed values. form Pascal's Triangle
    Matrix<int> commMat(n + 1, n + 1);
    int i;

    // set row 0
    commMat[0][0] = 1;
    for (i = 1; i <= n; i++)
    {
        // set first and last entry to 1
        commMat[i][0] = 1;
        commMat[i][i] = 1;

        // use terms from row i-1
        for (int j = 1; j < i; j++)
            commMat[i][j] = commMat[i - 1][j] + commMat[i - 1][j - 1];
    }
    // return value of the function
    return commMat[n][k];
}

#endif  // _COMBINATIONS_H_
