#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

#include <vector>
#include "HeapFunctions.h"
#include "Exception.h"

// maintain a priority queue containing elements of data type
// T using a comparison function object of type Compare
template <typename T, typename Compare = std::greater<T>> 
class PQueue
{                       
    public:
        // create empty priority queue
        PQueue();
     
        // return the number of elements in the priority queue
        int size() const;
        // is the priority queue empty?
        bool empty() const;

        // insert item into the priority queue
        // Postcondition: the heap size increases by 1
        void push(const T& item);
        // remove the element of highest priority.
        // Precondition: the priority queue is not empty. 
        // if condition fails, the function throws the
        // UnderflowError exception.
        // Postcondition: the heap decreases by 1
        void pop();

        // return the element of highest priority
        // Precondition: the priority queue is not empty. 
        // if the condition fails, the function throws the
        // UnderflowError exception
        T& top();
        // constant version
        const T& top() const;
    private:
        // pqVec holds the priority queue elements
        std::vector<T> pqVec;

        // function object used for comparisons
        Compare comp;
};

// constructor. create empty priority queue
template <typename T, typename Compare>
PQueue<T, Compare>::PQueue()
{}

// return the size of the priority queue
template <typename T, typename Compare>
int PQueue<T, Compare>::size() const
{ 
   return pqVec.size(); 
}

// return true if the priority queue is empty and false
// otherwise
template <typename T, typename Compare>
bool PQueue<T, Compare>::empty() const
{
   return pqVec.empty();
}

// insert a new item in the priority queue
template <typename T, typename Compare>
void PQueue<T, Compare>::push(const T& item)
{
    // insert the item at the end of the vector
    // call PushHeap() to restore the heap condition.
    //pqVec.push_back(item);
    PushHeap(pqVec, item, comp);
}

// remove the element of highest priority,
template <typename T, typename Compare>
void PQueue<T, Compare>::pop()
{
    // check for an empty priority queue
    if (pqVec.empty())
        throw UnderflowError("PQueue pop(): empty list");

    // call PopHeap() to put element at back of the vector
    PopHeap(pqVec, pqVec.size(), comp);

    // delele element from back of pqVec
    pqVec.pop_back();
}

template <typename T, typename Compare>
T& PQueue<T, Compare>::top()
{
   // check for an empty heap
   if (pqVec.empty())
        throw UnderflowError("PQueue top(): empty list");

    // return the root of the heap
    return pqVec[0];
}

template <typename T, typename Compare>
const T& PQueue<T, Compare>::top() const
{
   // check for an empty heap
   if (pqVec.empty())
        throw UnderflowError("PQueue top(): empty list");

    // return the root of the heap
    return pqVec[0];
}

#endif  // _PRIORITY_QUEUE_H_
