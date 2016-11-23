#ifndef _HEAP_SORT_H_
#define _HEAP_SORT_H_

#include "HeapFunctions.h"

template<typename T, typename Compare>
void HeapSort(std::vector<T>& v, Compare comp)
{
    MakeHeap(v, comp);

    int i, n = v.size();

    // iteration that determines elements v[n - 1] ... v[1]
    for(i = n; i > 1; --i)
    {
        // call PopHeap() to move next largest to v[n - 1]
        PopHeap(v, i, comp);
    }
}

#endif
