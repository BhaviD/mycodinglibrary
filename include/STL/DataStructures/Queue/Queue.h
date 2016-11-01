#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <list> // list class used by object composition
#include "Exception.h"

// implements a queue
template <typename T>
class Queue
{
    public:
        // constructor; create an empty queue
        Queue();
        
        // insert an element at the back of the queue.
        // Postcondition: the queue has one more element
        void push(const T& item);

        // remove an element from the front of the queue.
        // Precondition: the queue is not empty. if the
        // queue is empty, the function throws the
        // UnderflowError exception
        // Postcondition: the queue has one less element
        void pop();

        // return a reference to the front of the queue.
        // Preconditon: the queue is not empty. if the
        // the queue is empty, the function throws the
        // UnderflowError exception
        T& front();
        // constant version of front()
        const T& front() const;
                
        // return the queue size
         int size() const;
        
        // is the queue empty?
        bool empty() const;

    private:
        // a list object maintains the queue items and size
        std::list<T> qlist;
};
  
// the constructor has nothing to do. the default
// constructor for the list class initializes
// qlist to be empty
template <typename T>
Queue<T>::Queue()
{}

// insert item into the queue by inserting it at
// the back of the list
template <typename T>
void Queue<T>::push(const T& item)
{
    qlist.push_back(item);
}

// remove the item at the front of the queue
// by erasing the front of the list
template <typename T>
void Queue<T>::pop()
{
    // if queue is empty, throw UnderflowError
    if (qlist.size() == 0)
        throw UnderflowError("Queue pop(): empty queue");

    // erase the front
    qlist.pop_front();
}

template <typename T>
T& Queue<T>::front()
{
    // if queue is empty, throw UnderflowError
    if (qlist.size() == 0)
        throw UnderflowError("Queue front(): empty queue");

    return qlist.front();
}
          
template <typename T>
const T& Queue<T>::front() const
{
    // if queue is empty, throw UnderflowError
    if (qlist.size() == 0)
        throw UnderflowError("Queue front(): empty queue");

    return qlist.front();
}
 template <typename T>
T& Queue<T>::back()
{
    // if queue is empty, throw UnderflowError
    if (qlist.size() == 0)
        throw UnderflowError("Queue back(): empty queue");

    return qlist.back();
}
          
template <typename T>
const T& Queue<T>::back() const
{
    // if queue is empty, throw UnderflowError
    if (qlist.size() == 0)
        throw UnderflowError("Queue back(): empty queue");

    return qlist.back();
}
          
// return the queue size
template <typename T>
int Queue<T>::size() const
{
    return qlist.size();
}

// is the queue empty?
template <typename T>
bool Queue<T>::empty() const
{
    return qlist.empty();
}

#endif  // _QUEUE_H_
