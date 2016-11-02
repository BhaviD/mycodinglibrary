#ifndef _DOUBLY_LINKED_NODE_H_
#define _DOUBLY_LINKED_NODE_H_

template <typename T>
class DNode
{
    public:
        // the members of a DNode object are used for operations within a
        // doubly linked list; access is simplified by making them public

        T nodeValue;      // data value of the node
        DNode<T> *prev;   // previous node in the list
        DNode<T> *next;   // next node in the list

        
        // default constructor. creates object with value T(), the
        // default value of type T. set the node pointers to point at
        // the node itself
        DNode()
        {
            next = this;    // the next node is the current node
            prev = this;    // the previous node is the current node
        }

        // constructor with an argument to initialize nodeValue.
        // set the node pointers to point at the node itself
        DNode(const T& value, DNode<T> *prevNode = NULL, DNode<T> *nextNode = NULL) : 
                       nodeValue(value), prev(prevNode), next(nextNode)
        {
            if(!prev)
                prev = this;    // the next node is the current node
            if(!next)
                next = this;    // the previous node is the current node
        }
};

#endif  // _DOUBLY_LINKED_NODE_H_
