#ifndef _SELECTION_SORT_H_
#define _SELECTION_SORT_H_

#include <vector>

// sort an integer array using selection sort
void SelectionSort(int arr[], int n);

// sort an array of type T using selection sort
template <typename T>
void SelectionSort(T arr[], int n);

// sort an array of type T using double ended selection sort
template <typename T>
void DoubleEndedSelectionSort(T arr[], int n);

// sort an vector of type T using selection sort
template <typename T>
void SelectionSort(std::vector<T>& v);

// sort an vector of type T using double ended selection sort
template <typename T>
void DoubleEndedSelectionSort(std::vector<T>& v);


void SelectionSort(int arr[], int n)
{
    int smallIndex; // index of smallest element in the sublist
    int pass, j;
    int temp;

    // pass has the range 0 to n-2
    for (pass = 0; pass < n - 1; pass++)
    {
        // scan the sublist starting at index pass
        smallIndex = pass;

        // j traverses the sublist arr[pass+1] to arr[n-1]
        for (j = pass + 1; j < n; j++)
            // update if smaller element found
            if (arr[j] < arr[smallIndex])
                smallIndex = j;

        // if smallIndex and pass are not the same location,
        // exchange the smallest item in the sublist with arr[pass]
        if (smallIndex != pass)
        {
            temp = arr[pass];
            arr[pass] = arr[smallIndex];
            arr[smallIndex] = temp;
        }
    }
}

template <typename T>
void SelectionSort(T arr[], int n)
{
    int smallIndex; // index of smallest element in the sublist
    int pass, j;
    T temp;

    // pass has the range 0 to n-2
    for (pass = 0; pass < n - 1; ++pass)
    {
        // scan the sublist starting at index pass
        smallIndex = pass;

        // j traverses the sublist arr[pass+1] to arr[n-1]
        for (j = pass + 1; j < n; j++)
            // update if smaller element found
            if (arr[j] < arr[smallIndex])
                smallIndex = j;

        // if smallIndex and pass are not the same location,
        // exchange the smallest item in the sublist with arr[pass]
        if (smallIndex != pass)
        {
            temp = arr[pass];
            arr[pass] = arr[smallIndex];
            arr[smallIndex] = temp;
        }
    }
}

template <typename T>
void DoubleEndedSelectionSort(T arr[], int n)
{
    int smallIndex, largeIndex; // index of smallest element in the sublist
    int pass, j;
    T temp;

    // pass has the range 0 to n/2 - 1 i.e. n/2 passes
    for (pass = 0; pass < n / 2; ++pass)
    {
        // scan the sublist starting at index pass
        smallIndex = pass;
        largeIndex = pass;

        // j traverses the sublist arr[pass + 1] to arr[n - 1 - pass]
        for (j = pass + 1; j < n - pass; ++j)
        {
            // update if smaller element found
            if (arr[j] < arr[smallIndex])
                smallIndex = j;

            // update if larger element found
            if (arr[j] > arr[largeIndex])
                largeIndex = j;
        }

        // if smallIndex is the last element and largeIndex is the
        // first element of the pass, then swap them and continue
        if(smallIndex == n - 1 - pass && 
           largeIndex == pass)
        {
            temp = arr[smallIndex];
            arr[smallIndex] = arr[largeIndex];
            arr[largeIndex] = temp;
            continue;
        }

        // if smallIndex and pass are not the same location,
        // exchange the smallest item in the sublist with arr[pass]
        if (smallIndex != pass)
        {
            temp = arr[pass];
            arr[pass] = arr[smallIndex];
            arr[smallIndex] = temp;
        }

        // if largeIndex and "n - 1 - pass" are not the same location,
        // exchange the largest item in the sublist with arr[n - 1 - pass]
        if (largeIndex != n - 1 - pass)
        {
            temp = arr[n - 1 - pass];
            arr[n - 1 - pass] = arr[largeIndex];
            arr[largeIndex] = temp;
        }
    }
}

template <typename T>
void SelectionSort(std::vector<T>& v)
{
    int smallIndex; // index of smallest element in the sublist
    int pass, j, n = v.size();
    T temp;

    // pass has the range 0 to n-2
    for (pass = 0; pass < n - 1; ++pass)
    {
        // scan the sublist starting at index pass
        smallIndex = pass;

        // j traverses the sublist v[pass + 1] to v[n - 1]
        for (j = pass + 1; j < n; j++)
            // update if smaller element found
            if (v[j] < v[smallIndex])
                smallIndex = j;

        // if smallIndex and pass are not the same location,
        // exchange the smallest item in the sublist with v[pass]
        if (smallIndex != pass)
        {
            temp = v[pass];
            v[pass] = v[smallIndex];
            v[smallIndex] = temp;
        }
    }
}

template <typename T>
void DoubleEndedSelectionSort(std::vector<T>& v)
{
    int smallIndex, largeIndex; // index of smallest element in the sublist
    int pass, j, n = v.size();
    T temp;

    // pass has the range 0 to n/2 - 1 i.e. n/2 passes
    for (pass = 0; pass < n / 2; ++pass)
    {
        // scan the sublist starting at index pass
        smallIndex = pass;
        largeIndex = pass;

        // j traverses the sublist v[pass + 1] to v[n - 1 - pass]
        for (j = pass + 1; j < n - pass; ++j)
        {
            // update if smaller element found
            if (v[j] < v[smallIndex])
                smallIndex = j;

            // update if larger element found
            if (v[j] > v[largeIndex])
                largeIndex = j;
        }

        // if smallIndex is the last element and largeIndex is the
        // first element of the pass, then swap them and continue
        if(smallIndex == n - 1 - pass && 
           largeIndex == pass)
        {
            temp = v[smallIndex];
            v[smallIndex] = v[largeIndex];
            v[largeIndex] = temp;
            continue;
        }

        // if smallIndex and pass are not the same location,
        // exchange the smallest item in the sublist with v[pass]
        if (smallIndex != pass)
        {
            temp = v[pass];
            v[pass] = v[smallIndex];
            v[smallIndex] = temp;
        }

        // if largeIndex and "n - 1 - pass" are not the same location,
        // exchange the largest item in the sublist with v[n - 1 - pass]
        if (largeIndex != n - 1 - pass)
        {
            temp = v[n - 1 - pass];
            v[n - 1 - pass] = v[largeIndex];
            v[largeIndex] = temp;
        }
    }
}

#endif  //  _SELECTION_SORT_H_
