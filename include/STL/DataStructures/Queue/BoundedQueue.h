#ifndef ARRAY_BASED_QUEUE_CLASS
#define ARRAY_BASED_QUEUE_CLASS

#include "Exception.h"

//using namespace std;

const int MAXQSIZE = 50;

template <typename T>
class BoundedQueue
{
    public:
        // constructor. create an empty queue with MAXQSIZE available slots
        BoundedQueue();
        
        // insert an element at the back of the queue.
        // Precondition: count < MAXQSIZE. throws exception
        // OverflowError if the queue is full
        void push(const T& item);

        // remove an element from the front of the queue.
        // Precondition: the queue is not empty. throws exception
        // UnderflowError if the queue is empty
        void pop();

        // return the front of the queue.
        // Precondition: the queue is not empty. throw the UnderflowError
        // exception if the queue is empty
        T& front();
        // constant version
        const T& front() const;
                               
        // return the queue size
        int size() const;
        
        // is the queue empty?
        bool empty() const;

        // is the queue full?
        bool full() const;

    private:
        // array holding the queue elements
        T queueArray[MAXQSIZE];
        // index of the front and back of the queue
        int qfront, qback;
        // the number of elements in the queue, 0 <= count <= MAXQSIZE      
        int count;
};

template <typename T>
BoundedQueue<T>::BoundedQueue():
    qfront(0), qback(0), count(0)
{}

template <typename T>
void BoundedQueue<T>::push(const T& item)
{
    // is the array filled up? if so, throw OverflowError
    if (count == MAXQSIZE)
        throw OverflowError("BoundedQueue push(): queue full");

    // perform a circular queue insertion
    queueArray[qback] = item;
    qback = (qback + 1) % MAXQSIZE;

    // increment the queue size
    count++;
}

template <typename T>
void BoundedQueue<T>::pop()
{
    // if queue is empty, throw UnderflowError
    if (count == 0)
        throw UnderflowError("BoundedQueue pop(): empty queue");

    // perform a circular queue deletion
    qfront = (qfront + 1) % MAXQSIZE;

    // decrement the queue size
    count--;
}

template <typename T>
T& BoundedQueue<T>::front()
{
    // if queue is empty, throw UnderflowError
    if (count == 0)
        throw UnderflowError("BoundedQueue front(): empty queue");

    return queueArray[qfront];
}
          
template <typename T>
const T& BoundedQueue<T>::front() const
{
    // if queue is empty, throw UnderflowError
    if (count == 0)
        throw UnderflowError("BoundedQueue front(): empty queue");

    return queueArray[qfront];
}
          
template <typename T>
int BoundedQueue<T>::size() const
{
    return count;
}

template <typename T>
bool BoundedQueue<T>::empty() const
{
    return count == 0;
}

template <typename T>
bool BoundedQueue<T>::full() const
{
    return count == MAXQSIZE;
}

#endif  // ARRAY_BASED_QUEUE_CLASS
