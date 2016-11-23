#ifndef _HEAP_FUNCTIONS_H_
#define _HEAP_FUNCTIONS_H_

#include <vector>
#include <functional>

// the vector elements in the range [0, last-1) are a heap.
// insert the element v[last-1] into the heap so that the
// range [0, last) is a heap. use the function object comp
// to perform comparisons
template <typename T, typename Compare>
void PushHeap(std::vector<T>& v, const T& item, Compare comp);

// filter the vector element v[childPos] up the heap with index
// range [0, childPos]
template <typename T, typename Compare>
void HeapifyUp(std::vector<T>& v, int childPos, Compare comp);

// the vector elements in the range [0, last) are a heap.
// swap the first and last elements of the heap and then
// make the elements in the index range [0, last-1) a heap.
// use the function object comp to perform comparisons
template <typename T, typename Compare>
void PopHeap(std::vector<T>& v, int last, Compare comp);

// filter the vector element v[parentPos] down the heap with index
// range [parentPos, v.size())
template <typename T, typename Compare>
void HeapifyDown(std::vector<T>& v, int parentPos, int last, Compare comp);

// arrange the vector elements into a heap. use the function
// object comp to perform comparisons
template <typename T, typename Compare>
void MakeHeap(std::vector<T>& v, Compare comp);

// IMPLEMENTATIONS

template <typename T, typename Compare>
void PushHeap(std::vector<T>& v, const T& item, Compare comp)
{
    v.push_back(item);
    int last = v.size();

    // assume the new item is at location v[last-1] and that
    // the elements v[0] to v[last-2] are in heap order
    HeapifyUp(v, last - 1, comp);
}

template <typename T, typename Compare>
void HeapifyUp(std::vector<T>& v, int childPos, Compare comp)
{
    int parentPos = (childPos - 1) / 2;
    T target;

    // childPos is an index that traverses path of parents.
    // target is repositioned in path
    parentPos = (childPos - 1) / 2;
    target = v[childPos];

    // traverse path of parents up to the root
    while (childPos > 0)
    {
        // compare target and parent value
        if (comp(target, v[parentPos]))
        {
            // move data from parent position to current
            // position. update current position to parent
            // position. compute next parent
            v[childPos] = v[parentPos];
            childPos = parentPos;
            parentPos = (childPos - 1) / 2;
        }
        else
            // if !comp(target, parentvalue), heap condition is ok. break
            break;
    }
    // the correct location has been discovered. assign target
    v[childPos] = target;
}

template <typename T, typename Compare>
void PopHeap(std::vector<T>& v, int last, Compare comp)
{
    T temp;

    // exchange the first and last element in the heap
    temp = v[0];
    v[0] = v[last - 1];
    v[last - 1] = temp;

    // filter down the root over the range [0, last - 1)
    HeapifyDown(v, 0, last - 1, comp);
}

template <typename T, typename Compare>
void HeapifyDown(std::vector<T>& v, int parentPos, int last, Compare comp)
{
    int childPos;

    // start at parentPos and filter target down the heap
    T target = v[parentPos];

    // compute the left child index and begin a scan down
    // path of children, stopping at end of list (last)
    // or when we find a place for target
    childPos = 2 * parentPos + 1;
    while (childPos < last)
    {
        // index of right child is childPos + 1. compare the
        // two children. change childPos if
        // comp(v[childPos+1], v[childPos]) is true
        if ((childPos + 1 < last) &&
            comp(v[childPos + 1], v[childPos]))
            childPos = childPos + 1;

        // compare selected child to target
        if (comp(v[childPos], target))
        {
            // comp(selected child, target) is true.
            // move selected child to the parent;
            // position of selected child is now vacated
            v[parentPos] = v[childPos];

            // update indices to continue the scan
            parentPos = childPos;
            childPos = 2 * parentPos + 1;
        }
        else
            // target belongs at parentPos
            break;
    }
    v[parentPos] = target;
}

template <typename T, typename Compare>
void MakeHeap(std::vector<T>& v, Compare comp)
{
    int parentPos, last = v.size();

    // compute the index of the last parent
    parentPos = (last - 2) / 2;

    // filter down every parent in order from last parent
    // up to the root
    while (parentPos >= 0)
    {
        HeapifyDown(v, parentPos, last, comp);
        --parentPos;
    }
}

#endif  // _HEAP_FUNCTIONS_H_
