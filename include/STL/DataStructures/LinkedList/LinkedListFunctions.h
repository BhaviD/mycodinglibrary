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
static void Push(Node<T>* &head, T data);

// insert a new node after the given prevNode
template <typename T>
static void InsertAfter(Node<T>* prevNode, T data);

// insert a new node after the given prevNode
template <typename T>
static void InsertAfter(Node<T>* prevNode, Node<T>* newNode);

// appends a new node at the end of the linked list
template <typename T>
static void Append(Node<T>* &head, T data);

// deletes the first occurrence of key in linked list
template <typename T>
static void Erase(Node<T>* &head, T key);

// delete the node at the given position
template <typename T>
static void Erase(Node<T>* &head, Node<T>* curr);

// delete all the nodes of the linked list
template <typename T>
static void EraseAll(Node<T>* &head);

// count no. of nodes in linked list
template <typename T>
int GetCountIterative(Node<T>* head);

/* Counts the no. of occurences of a node
   (search_for) in a linked list (head) */
template <typename T>
int GetCountRecursive(Node<T>* head);

// sorts the linked list by changing next pointers (not data)
template <typename T>
void MergeSort(Node<T>* &head);

template <typename T>
static void PrintList(Node<T>* node);

// swap nodes x and y in linked list by changing links
template <typename T>
static void SwapNodes(Node<T>* &head, T x, T y);

// reverse the linked list
template <typename T>
static void Reverse(Node<T>* &head);

/* Takes two lists sorted in increasing order, and splices
 * their nodes together to make one big sorted list 
**/
template <typename T>
static Node<T>* SortedMergeIterative(Node<T>* a, Node<T>* b);

/* cleaner than iterative code.
 * Not recommended for production code however, becuase it
 * uses stack space proportional to the length of the lists.
**/
template <typename T>
static Node<T>* SortedMergeRecursive(Node<T>* a, Node<T>* b);

/* Split the nodes of the given list into front and back halves,
 * and return the two lists using the reference parameters.
 * If the length is odd, the extra node should go in the front list.
 * Uses the fast/slow pointer strategy.
**/
template <typename T>
void FrontBackSplit(Node<T>* src, Node<T>* &front, Node<T>* &back);

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
static void Push(Node<T>* &head, T data)
{
    // make next of new node point to head
    Node<T>* newNode = new Node<T>(data, head);
 
    // move the head to point to the new node
    head = newNode;
}
 
template <typename T>
static void InsertAfter(Node<T>* prevNode, T data)
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
static void InsertAfter(Node<T>* prevNode, Node<T>* newNode)
{
    if (NULL == prevNode)
    {
        std::cout << "the given previous node cannot be NULL\n";
        return;
    }
 
    // make next of new node as next of prevNode
    newNode->next = prevNode->next;
    // move the next of prevNode as newNode
    prevNode->next = newNode;
}
 
template <typename T>
static void Append(Node<T>* &head, T data)
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
static void Erase(Node<T>* &head, T key)
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
static void Erase(Node<T>* &head, Node<T>* curr)
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
static void EraseAll(Node<T>* &head)
{
    Node<T>* curr = NULL;
    while(head)
    {
        curr = head;
        head = head->next;
        delete curr;
    }
}

template <typename T>
int GetCountIterative(Node<T>* head)
{
    int count = 0;             // Initialize count
    Node<T>* current = head;   // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

template <typename T>
int GetCountRecursive(Node<T>* head)
{
    // Base case
    if (head == NULL)
        return 0;
 
    // count is 1 + count of remaining list
    return 1 + GetCountRecursive(head->next);
}

template <typename T>
static void SwapNodes(Node<T>* &head, T x, T y)
{
    // Nothing to do if x and y are same
    if (x == y) return;

    // Search for x (keep track of prevX and currX)
    Node<T> *prevX = NULL, *currX = head;
    while (currX && currX->nodeValue != x)
    {
       prevX = currX;
       currX = currX->next;
    }

    // Search for y (keep track of prevY and currY)
    Node<T> *prevY = NULL, *currY = head;
    while (currY && currY->nodeValue != y)
    {
       prevY = currY;
       currY = currY->next;
    }

    // If either x or y is not present, nothing to do
    if (currX == NULL || currY == NULL)
       return;

    // If x is not head of linked list
    if (prevX != NULL)
       prevX->next = currY;
    else // Else make y as new head
       head = currY;  

    // If y is not head of linked list
    if (prevY != NULL)
       prevY->next = currX;
    else  // Else make x as new head
       head = currX;

    // Swap next pointers
    Node<T> *temp = currY->next;
    currY->next = currX->next;
    currX->next  = temp;
}

template <typename T>
static void Reverse(Node<T>* &head)
{
    Node<T> *prev = NULL, *current = head;
    Node<T>* next = NULL;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    head = prev;
}

// pull off the front node of the source and put it in dest 
template <typename T>
static void MoveNode(Node<T>* &dest, Node<T>* &src);

template <typename T>
static Node<T>* SortedMergeIterative(Node<T>* a, Node<T>* b)
{
    // a dummy first node to hang the result on
    Node<T> dummy;
 
    // tail points to the last result node
    // so tail is the place after new nodes are added
    Node<T>* tail = &dummy;
 
    while (1)
    {
        // if either list runs out, use the other list
        if (a == NULL)
        {
            tail->next = b;
            break;
        }
        else if (b == NULL)
        {
            tail->next = a;
            break;
        }
        if (a->nodeValue <= b->nodeValue)
            MoveNode(tail, a);
        else
            MoveNode(tail, b);
 
        tail = tail->next;
    }
    return (dummy.next);
}

template <typename T>
static Node<T>* SortedMergeRecursive(Node<T>* a, Node<T>* b)
{
    Node<T>* result = NULL;

    /* Base cases */
    if (a == NULL) 
        return (b);

    if (b == NULL) 
        return (a);

    // Pick either a or b, and recur
    if (a->nodeValue <= b->nodeValue) 
    {
        result = a;
        result->next = SortedMergeRecursive(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMergeRecursive(a, b->next);
    }
    return (result);
}

template <typename T>
static void MoveNode(Node<T>* &dest, Node<T>* &src)
{
    Node<T>* newNode = src;
    src = src->next;

    InsertAfter(dest, newNode);
}

// sorts the linked list by changing next pointers (not data)
template <typename T>
void MergeSort(Node<T>* &head)
{
    // Base case -- length 0 or 1
    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }
    //Node<T>* head = headRef;
    Node<T> *a = NULL, *b = NULL;

    // Split head into 'a' and 'b' sublists
    FrontBackSplit(head, a, b); 

    // Recursively sort the sublists
    MergeSort(a);
    MergeSort(b);

    // merge the two sorted lists together
    head = SortedMergeIterative(a, b);
}

template <typename T>
void FrontBackSplit(Node<T>* src, Node<T>* &front, Node<T>* &back)
{
    front = src;
    Node<T> *fast = NULL, *slow = NULL;
    if (src == NULL || src->next == NULL)
    {
        // length < 2 cases
        back = NULL;
    }
    else
    {
        slow = src;
        fast = src->next;

        // Advance 'fast' two nodes, and advance 'slow' one node
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        // 'slow' is before the midpoint in the list
        back = slow->next;
        slow->next = NULL;
    } 
}

template <typename T>
static void PrintList(Node<T>* node)
{
    std::cout << std::endl;
    while (node != NULL)
    {
        std::cout << " " << node->nodeValue << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

#endif   // _LINKEDLIST_FUNCTIONS_H_
