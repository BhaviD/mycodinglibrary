#ifndef _NODE_H_
#define _NODE_H_

#ifndef NULL
#include <cstddef>
#endif  // NULL

// linked list node
template <typename T>
class Node
{
   public:
      T nodeValue;      // data held by the node
      Node<T> *next;    // next node in the list

      // default constructor with no initial value
      Node() : next(NULL)
      {}

      // constructor. initialize nodeValue and next
      Node(const T& item, Node<T> *nextNode = NULL) : 
              nodeValue(item), next(nextNode)
      {}
};

#endif   // _NODE_H_
