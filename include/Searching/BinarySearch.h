#ifndef _BINARY_SEARCH_H_
#define _BINARY_SEARCH_H_

using namespace std;

// perform a binary search of an array for a target
// in the index range [first, last). return the index of a
// match or last if the target is not in arr
template <typename T>
int IterativeBinarySearch(const T arr[], int first, int last, const T& target);

template <typename T>
int RecursiveBinarySearch(const T arr[], int first, int last, const T& target);

template <typename T>
int IterativeBinarySearch(const T arr[], int first, int last, const T& target)
{
    int mid;                    // index of the midpoint
    T midValue;                 // object that is assigned arr[mid]
    
    while (first < last)        // test for nonempty sublist
    {
        mid = (first + last) / 2;
        midValue = arr[mid];
        if (target == midValue)
            return mid;         // have a match
        // determine which sublist to search
        else if (target < midValue)
            last = mid;         // search lower sublist. reset last
        else
            first = mid + 1;    // search upper sublist. reset first
    }

    return -1;            // target not found
}

template <typename T>
int RecursiveBinarySearch(const T arr[], int first, int last, const T& target)
{
    // target not found in the arr
    if(last <= first)
        return -1;

    int mid = (first + last) / 2;     // index of the midpoint
    T midValue = arr[mid];            // object that is assigned arr[mid]
    
    if (target == midValue)
        return mid;         // have a match
    // determine which sublist to search
    else if (target < midValue)
        last = mid;         // search lower sublist. reset last
    else
        first = mid + 1;    // search upper sublist. reset first
    return RecursiveBinarySearch(arr, first, last, target);
}

#endif
