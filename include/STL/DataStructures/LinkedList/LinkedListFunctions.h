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
    if(prevNode)
        prevNode->next = succNode;

    if(succNode)
        succNode->prev = prevNode;

    // deallocate the memory used by the node
    delete curr;
}

/* Given a reference to the head of a list and a T, 
   inserts a new node on the front of the list. */
template <typename T>
void Push(Node<T>* &head, T data)
{
    /* put in the data  */
    /* Make next of new node point to head */
    Node<T>* newNode = new Node<T>(data, head);
 
    /* move the head to point to the new node */
    head = newNode;
}
 
/* Given a node prevNode, insert a new node after the given 
   prevNode */
template <typename T>
void InsertAfter(Node<T>* prevNode, T data)
{
    if (NULL == prevNode)
    {
        std::cout << "the given previous node cannot be NULL\n";
        return;
    }
 
    /* allocate new node */
    /* put in the data  */
    /* Make next of new node as next of prevNode */
    Node<T>* newNode = new Node<T>(data, prevNode->next);
 
    /* move the next of prevNode as newNode */
    prevNode->next = newNode;
}
 
/* Given a reference to pointer to the head
   of a list and a T, appends a new node at the end  */
template <typename T>
void Append(Node<T>* &head, T data)
{
    /* put in the data  */
    /* This new node is going to be the last node, so make next of
       it as NULL*/
    Node<T>* newNode = new Node<T>(data);
 
    Node<T> *last = head;
 
    /* If the Linked List is empty, then make the new node as head */
    if (head == NULL)
    {
        head = newNode;
        return;
    }
 
    /* Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
 
    /* 6. Change the next of last node */
    last->next = newNode;
    return;
}

template <typename T>
void PrintList(Node<T>* node)
{
    while (node != NULL)
    {
        std::cout << " " << node->nodeValue << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

#endif   // _LINKEDLIST_FUNCTIONS_H_
