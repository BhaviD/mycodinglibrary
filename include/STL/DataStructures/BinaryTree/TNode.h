#ifndef _TREENODE_H_
#define _TREENODE_H_

// represents a node in a binary tree
template <typename T>
class TNode
{
   public:
        // TNode is a class implementation structure. making the
        // data public simplifies building class functions
        T nodeValue;
        TNode<T> *left, *right;

        // default constructor. data not initialized
        TNode()
        {}

        // initialize the data members
        TNode (const T& item, TNode<T> *lptr = NULL, 
                 TNode<T> *rptr = NULL):
                    nodeValue(item), left(lptr), right(rptr)
        {}
};

#endif  // _TREENODE_H_
