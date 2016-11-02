#ifndef _LINKEDQUEUE_H_
#define _LINKEDQUEUE_H_

#ifndef NULL
#include <cstddef>
#endif  // NULL

#include "Node.h"        // Node class
#include "Exception.h"   // for UnderflowError exception

// implements a linked queue
template <typename T>
class LinkedQueue
{
    public:
        // Constructor: creates an empty queue.
        // Postcondition: qsize = 0, qfront = qback = NULL
        LinkedQueue();

        // copy constructor. builds a copy of obj
        LinkedQueue(const LinkedQueue<T>& obj);

        // destructor. clear the linked list
        ~LinkedQueue();

        LinkedQueue<T>& operator= (const LinkedQueue<T>& rhs);

        // insert an element at the rear of the queue
        // Postcondition: the queue has one more element
        void push(const T& item);

        // remove an element from the front of the queue.
        // Precondition: the queue is not empty. if the queue
        // is empty, throw an UnderflowError exception
        // Postcondition: the queue has one less element
        void pop();

        // return a reference to the front of the queue.
        // Precondition: the queue is not empty. if the queue
        // is empty, throw an UnderflowError exception
        T& front();
        // constant version
        const T& front() const;

        // return the current size of the queue
        int size() const;

        // return true if the queue is empty; otherwise return false
        bool empty() const;

    private:
        // the linked list with qfront stores the elements.
        // qback points to the rear of the queue
        Node<T> *qfront, *qback;
        // number of elements in the queue
        int qsize;

        // copy q so the current list is identical to q
        void copy(const LinkedQueue<T>& q);

        // clear the list. used by the destructor and assignment
        void clear();

        // allocate a Node with value item and pointer value NULL
        // and return a pointer to it. if memory allocation fails,
        // throw the MemoryAllocationError exception
        Node<T> *getNode(const T& item);
};

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& q)
{
    // qback moves through the list we are building and
    // winds up at the rear of our new list. p
    // moves through the list we are copying
    Node<T> *newNode, *p = q.qfront;

    // initially, the list is empty
    qfront = qback = NULL;

    // nothing to do if p is NULL
    if (p != NULL)
    {
        // create the first Node in the queue and assign
        // its addres to qback
        qfront = qback = getNode(p->nodeValue);

        // move forward in the list we are copying
        p = p->next;

        // copy remaining items
        while(p)
        {
            // insert new Node at the back
            newNode = getNode(p->nodeValue);
            qback->next = newNode;

            // qback is the new Node
            qback = newNode;

            // move to the next Node of the list we are copying
            p = p->next;
        }
    }

    // the size of the new list is the size of q
    qsize = q.qsize;
}

template <typename T>
void LinkedQueue<T>::clear()
{
    Node<T> *curr = qfront, *p;

    // delete nodes until we arrive at the end of the list
    while (curr)
    {
        // save curr in p and move curr forward
        // to the next list Node
        p = curr;
        curr = curr->next;

        // delete Node p
        delete p;
    }

    // specify an emtpy list
    qfront = qback = NULL;
    qsize = 0;
}

template <typename T>
Node<T> *LinkedQueue<T>::getNode(const T& item)
{
    // allocate a new Node
    Node<T> *newNode = new Node<T> (item);

    // check for failure
    if (newNode == NULL)
        throw MemoryAllocationError(
            "LinkedQueue: memory allocation failure");

    return newNode;
}

// create the empty list qfront = qback = NULL and qsize = 0
template <typename T>
LinkedQueue<T>::LinkedQueue(): qfront(NULL), qback(NULL), qsize(0)
{}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& obj)
{
    // call copy() and pass the pointer to the front of
    // the linked list in obj
    copy(obj);
}

template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
    // call clear()
    clear();
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator= (const LinkedQueue<T>& rhs)
{
    // delete the current list
    clear();

    // make the current object a copy of rhs
    copy(rhs);

    return *this;
}

// insert item into the queue by inserting it at
// the back of the list
template <typename T>
void LinkedQueue<T>::push(const T& item)
{
    // allocate space for the new Node
    Node<T> *newNode = getNode(item);

    // if the queue is empty, insert the new element at the front of
    // the list and update both qfront and qback
    if (qfront == NULL)
    {
        qfront = newNode;
        qback = newNode;
    }
    // in a non-empty list, insert new element at back and update qback
    else
    {
        qback->next = newNode;
        qback = newNode;
    }

    // increment the queue size
    qsize++;
}

// remove the item at the front of the queue by erasing
// the first element in the linked list
template <typename T>
void LinkedQueue<T>::pop()
{
    // save the location of the front of the queue
    Node<T> *p = qfront;

    // if the queue is empty, throw UnderflowError
    if (qsize == 0)
        throw UnderflowError("queue pop(): empty queue");

    // move the front forward one Node
    qfront= qfront->next;

    // if the queue is now empty, set qback to NULL
    if (qfront == NULL)
        qback = NULL;

    // delete the Node
    delete p;

    // decrement the queue size
    qsize--;
}

template <typename T>
T& LinkedQueue<T>::front()
{
    // if the queue is empty, throw UnderflowError
    if (qsize == 0)
        throw UnderflowError("queue front(): empty queue");

    // return the value at the front
    return qfront->nodeValue;
}

template <typename T>
const T& LinkedQueue<T>::front() const
{
    // if the queue is empty, throw UnderflowError
    if (qsize == 0)
        throw UnderflowError("queue front(): empty queue");

    // return the value at the front
    return qfront->nodeValue;
}

template <typename T>
int LinkedQueue<T>::size() const
{
    return qsize;
}

template <typename T>
bool LinkedQueue<T>::empty() const
{
    return qsize == 0;
}

#endif  // _LINKEDQUEUE_H_
