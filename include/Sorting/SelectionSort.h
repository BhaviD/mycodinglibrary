#ifndef _SELECTION_SORT_H_
#define _SELECTION_SORT_H_

using namespace std;

// sort an integer array using selection sort
void selectionSort(int arr[], int n);

// sort an array of type T using selection sort
template <typename T>
void selectionSort(T arr[], int n);

void selectionSort(int arr[], int n)
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
void selectionSort(T arr[], int n)
{
    int smallIndex; // index of smallest element in the sublist
    int pass, j;
    T temp;

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

#endif  //  _SELECTION_SORT_H_
