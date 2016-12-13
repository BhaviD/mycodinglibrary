#ifndef _LINKEDLIST_FUNCTIONS_H_
#define _LINKEDLIST_FUNCTIONS_H_

#include <iostream>
#include <string>

#include "Node.h"     // use Node class
#include "DNode.h"    // use DNode class

// **********************************************************
// Doubly-linked List Functions
// **********************************************************

// insert a new Node with value item immediately before Node curr
template <typename T>
DNode<T> *insert(DNode<T> *curr, const T& item);

// erase DNode pointed to by curr
template <typename T>
void erase(DNode<T> *curr);


// **********************************************************
// Singly-linked List Functions
// **********************************************************

// inserts a new node on the front of the list.
template <typename T>
void Push(Node<T>* &head, T data);

// insert a new node after the given prevNode
template <typename T>
void InsertAfter(Node<T>* prevNode, T data);

// appends a new node at the end of the linked list
template <typename T>
void Append(Node<T>* &head, T data);

// deletes the first occurrence of key in linked list
template <typename T>
void Erase(Node<T>* &head, T key);

// delete the node at the given position
template <typename T>
void Erase(Node<T>* &head, Node<T>* curr);

template <typename T>
void PrintList(Node<T>* node);

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

template <typename T>
void Push(Node<T>* &head, T data)
{
    // make next of new node point to head
    Node<T>* newNode = new Node<T>(data, head);
 
    // move the head to point to the new node
    head = newNode;
}
 
template <typename T>
void InsertAfter(Node<T>* prevNode, T data)
{
    if (NULL == prevNode)
    {
        std::cout << "the given previous node cannot be NULL\n";
        return;
    }
 
    // make next of new node as next of prevNode
    Node<T>* newNode = new Node<T>(data, prevNode->next);
 
    // move the next of prevNode as newNode
    prevNode->next = newNode;
}
 
template <typename T>
void Append(Node<T>* &head, T data)
{
    /* This new node is going to be the last node, so make next of
       it as NULL */
    Node<T>* newNode = new Node<T>(data);
    Node<T> *last = head;
 
    // If the Linked List is empty, then make the new node as head
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    // else traverse till the last node
    while (last->next != NULL)
        last = last->next;
 
    // change the next of last node
    last->next = newNode;
}

template <typename T>
void Erase(Node<T>* &head, T key)
{
    // Store head node
    Node<T> *temp = head, *prev;
 
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->nodeValue == key)
    {
        head = temp->next;   // Changed head
        delete temp;         // free old head
        return;
    }
 
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->nodeValue != key)
    {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL) return;
 
    // Unlink the node from linked list
    prev->next = temp->next;
    delete temp;      // free memory
}


template <typename T>
void Erase(Node<T>* &head, Node<T>* curr)
{
    // if linked list is empty
    if (head == NULL || curr == NULL)
      return;
 
    // store head node
    Node<T>* temp = head;
 
    // if head needs to be removed
    if (curr == head)
    {
        head = temp->next;   // change head
        delete temp;         // free old head
        return;
    }
    // find previous node of the node to be deleted
    while(temp->next != curr)
        temp = temp->next;
 
    // if curr is not present in the linked list
    if (temp == NULL)
         return;
 
    // node temp->next is the node to be deleted
    // store pointer to the next of node to be deleted
    Node<T> *succNode = temp->next->next;
 
    delete temp->next;      // free memory
    temp->next = succNode;  // unlink the deleted node from list
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
