// Reference: http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

#ifndef _PERMUTE_H_
#define _PERMUTE_H_

#include <vector>
#include "WriteContainer.h"         // for WriteVector()

// output the list of all permutations of the
// integer values in the range [index, permList.size())
void Permute(std::vector<int>& permList, int index);

void Swap(std::vector<int>& v, int a, int b)
{
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

void Permute(std::vector<int>& permList, int index)
{
    int vSize = permList.size();

    if (index == vSize - 1)
        // display the permutation
        WriteVector(permList);  
    else
    {
        for (int i = index; i < vSize; i++)
        {
            Swap(permList, index, i);
            Permute(permList, index + 1);     
            Swap(permList, index, i);
        }
    }
}

#endif  // _PERMUTE_H_
