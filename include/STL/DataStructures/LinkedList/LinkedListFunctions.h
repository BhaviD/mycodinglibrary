#ifndef _LINKEDLIST_FUNCTIONS_H_
#define _LINKEDLIST_FUNCTIONS_H_

#include <iostream>
#include <string>

#include "Node.h"     // use Node class
#include "DNode.h"    // use DNode class

// insert a new Node with value item immediately before Node curr
template <typename T>
DNode<T> *insert(DNode<T> *curr, const T& item);

// erase DNode pointed to by curr
template <typename T>
void erase(DNode<T> *curr);

// ***********************************************************
//      FUNCTION IMPLEMENTATIONS
// ***********************************************************

template <typename T>
DNode<T> *insert(DNode<T> *curr, const T& item)
{
    // declare pointer variables for the new Node and the previous Node
    DNode<T> *newNode, *prevNode = curr->prev;

    // allocate new DNode with item as initial value
    newNode = new DNode<T>(item, prevNode, curr);

    // update curr and prevNode to point at newNode
    prevNode->next = newNode;   
    curr->prev = newNode;
    
    return newNode;
}

template <typename T>
void erase(DNode<T> *curr)
{
    // return if the list is empty
    if (curr->next == curr)
        return;

    // declare pointers for the predecessor and successor nodes
    DNode<T> *prevNode = curr->prev, *succNode = curr->next;

    // update pointer fields for predecessor and successor
    prevNode->next = succNode;
    succNode->prev = prevNode;

    // deallocate the memory used by the node
    delete curr;
}

#endif   // _LINKEDLIST_FUNCTIONS_H_
