#ifndef _BUBBLE_SORT_H_
#define _BUBBLE_SORT_H_

#include <vector>

// sort an array of type T using Bubble sort
template <typename T>
void BubbleSort(std::vector<T>& v);

// sort an array of type T using Bubble sort
template <typename T>
void BubbleSort(T arr[], int n);

// definition of BubbleSort
template <typename T>
void BubbleSort(T arr[], int n)
{
    T temp;
    bool is_swapped = false;

    // pass has the range (0 to n - 2) i.e. n - 1 times
    for (int pass = 0; pass < n - 1; ++pass)
    {
        is_swapped = false;

        // scan the sublist starting at index pass
        // j traverses the sublist arr[1] to arr[n - pass]
        for (int j = 1; j < n - pass; j++)
        {
            // swap if smaller element found
            if (arr[j] < arr[j - 1])
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                is_swapped = true;
            }
        }
        // If no swap took place in the pass, then break.
        if(!is_swapped)
            break;
    }
}

template <typename T>
void BubbleSort(std::vector<T>& v)
{
    int n = v.size();
    T temp;
    bool is_swapped = false;

    // pass has the range (0 to n - 2) i.e. n - 1 times
    for (int pass = 0; pass < n - 1; ++pass)
    {
        is_swapped = false;

        // scan the sublist starting at index pass
        // j traverses the sublist v[1] to v[n - pass - 1]
        for (int j = 1; j < n - pass; ++j)
        {
            // swap if smaller element found
            if (v[j] < v[j - 1])
            {
                temp = v[j];
                v[j] = v[j - 1];
                v[j - 1] = temp;
                is_swapped = true;
            }
        }
        // If no swap took place in the pass, then break.
        if(!is_swapped)
            break;
    }
}

#endif  //  _SELECTION_SORT_H_
