#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

template <typename T>
int pivotIndex(std::vector<T>& v, int first, int last)
{
    // index for the midpoint of [first,last) and the
    // indices that scan the index range in tandem
    int mid, scanUp, scanDown;
    // pivot value and object used for exchanges
    T pivot, temp;

    #if 0
    if (first == last)
        return last;
    else if (first == last-1)
        return first;
    else
    {
    #endif
        mid = (last + first)/2;
        pivot = v[mid];

        // exchange the pivot and the low end of the range
        // and initialize the indices scanUp and scanDown.
        v[mid] = v[first];
        v[first] = pivot;

        scanUp = first + 1;
        scanDown = last - 1;

        // manage the indices to locate elements that are in
        // the wrong sublist; stop when scanDown <= scanUp
        for(;;)
        {
            // move up lower sublist; stop when scanUp enters
            // upper sublist or identifies an element >= pivot
            while (scanUp <= scanDown && pivot >= v[scanUp])
                scanUp++;

            // scan down upper sublist; stop when scanDown locates
            // an element <= pivot; we guarantee we stop at arr[first]
            while (pivot < v[scanDown])
                scanDown--;

            // if indices are not in their sublists, partition complete
            if (scanUp >= scanDown)
                break;

            // indices are still in their sublists and identify
            // two elements in wrong sublists. exchange
            temp = v[scanUp];
            v[scanUp] = v[scanDown];
            v[scanDown] = temp;

            scanUp++;
            scanDown--;
        }

        // copy pivot to index (scanDown) that partitions sublists
        // and return scanDown
        v[first] = v[scanDown];
        v[scanDown] = pivot;
        return scanDown;
    //}
}

template <typename T>
void QuickSort(std::vector<T>& v, int first, int last)
{
   // index of the pivot
   int pivotLoc;
    // temp used for an exchange when [first,last) has
    // two elements
    //T temp;

   // if the range is not at least two elements, return
   if (last - first <= 1)
        return;

    // if sublist has two elements, compare v[first] and
    // v[last-1] and exchange if necessary
   else if (last - first == 2)
    {
        if (v[last - 1] < v[first])
        {
            T temp = v[last - 1];
            v[last - 1] = v[first];
            v[first] = temp;
        }
        return;
    }
   else
    {
        pivotLoc = pivotIndex(v, first, last);

        // make the recursive call
        QuickSort(v, first, pivotLoc);

        // make the recursive call
        QuickSort(v, pivotLoc + 1, last);
    }
}

#endif  // _QUICK_SORT_H_
