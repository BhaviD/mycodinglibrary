#ifndef BINARY_SEARCH_TREE_CLASS
#define BINARY_SEARCH_TREE_CLASS

#ifndef NULL
#include <cstddef>
#endif  // NULL

#include <iomanip>      // for setw()
//#include <strstream>        // for format conversion
#include <string>           // node data formatted as a string
#include <queue>
#include <utility>      // std::pair class

#include "Exception.h"   // Exception classes

// declares a binary search tree node object
template <typename T>
class BSTNode
{
   public:
        // BSTNode is used to implement the binary search tree class
        // making the data public simplifies building the class functions

        // node data
        T nodeValue;
        // child pointers and pointer to the node's parent
        BSTNode<T> *left, *right, *parent;

        // constructor
        BSTNode (const T& item, BSTNode<T> *lptr = NULL, 
                 BSTNode<T> *rptr = NULL, BSTNode<T> *pptr = NULL) :
                 nodeValue(item), left(lptr), right(rptr), parent(pptr)
        {}
};

#if 0
// objects hold a formatted label string and the level,column
// coordinates for a shadow tree node
class tnodeShadow
{
    public:
        string nodeValueStr;    // formatted node value
        int level,column;
        tnodeShadow *left, *right;

        tnodeShadow ()
        {}
};
#endif

template <typename T>
class BSTree
{
    public:
        // iterator nested classes
        class iterator;
        class const_iterator;

        // constructor. initialize root to NULL and size to 0
        BSTree();
        // constructor. insert the elements from the pointer
        // range [first, last) into the tree
        BSTree(T *first, T *last);
        // copy constructor
        BSTree(const BSTree<T>& tree);
        // destructor
        ~BSTree();
        // assignment operator
        BSTree<T>& operator= (const BSTree<T>& rhs);

        // search for item. if found, return an iterator pointing
        // at it in the tree; otherwise, return end()
        iterator find(const T& item);
        // constant version
        const_iterator find(const T& item) const;

        // indicate whether the tree is empty
        int empty() const;
        // return the number of data items in the tree
        int size() const;
            
        // if item is not in the tree, insert it and
        // return a std::pair whose iterator component points
        // at item and whose bool component is true. if item
        // is in the tree, return a std::pair whose iterator
        // component points at the existing item and whose
        // bool component is false
        // Postcondition: the tree size increases by 1 if item
        // is not in the tree
        std::pair<iterator, bool> insert(const T& item);
        
        // if item is in the tree, erase it and return 1;
        // otherwise, return 0
        // Postcondition: the tree size decreases by 1 if
        // item is in the tree
        int erase(const T& item);

        // erase the item pointed to by pos.
        // Preconditions: the tree is not empty and pos points
        // to an item in the tree. if the tree is empty, the
        // function throws the UnderflowError exception. if the
        // iterator is invalid, the function throws the ReferenceError
        // exception.
        // Postcondition: the tree size decreases by 1
        void erase(iterator pos);

        // erase all items in the range [first, last).
        // Precondition: the tree is not empty. if the tree
        // is empty, the function throws the UnderflowError
        // exception.
        // Postcondition: the size of the tree decreases by
        // the number of elements in the range [first, last)
        void erase(iterator first, iterator last);

        // return an iterator pointing to the first item InOrder
        iterator begin();
        // constant version
        const_iterator begin() const;
        // return an iterator pointing just past the end of
        // the tree data
        iterator end();
        // constant version
        const_iterator end() const;

        #if 0
        // tree display function. maxCharacters is the
        // largest number of characters required to draw
        // the value of a node
        void displayTree(int maxCharacters);
        #endif

    private:
        // pointer to tree root
        BSTNode<T> *root;
        // number of elements in the tree
        int treeSize;

        // allocate a new tree node and return a pointer to it.
        // if memory allocation fails, the function throws the
        // MemoryAllocationError exception
        BSTNode<T> *getBSTNode(const T& item,
                              BSTNode<T> *lptr,BSTNode<T> *rptr, BSTNode<T> *pptr);

        // recursive function used by copy constructor and assignment
        // operator to assign the current tree as a copy of another tree
        BSTNode<T> *copyTree(BSTNode<T> *t);

        // recursive function used by destructor and assignment
        // operator to delete all the nodes in the tree
        void deleteTree(BSTNode<T> *t);

        // search for item in the tree. if it is in the tree,
        // return a pointer to its node; otherwise, return NULL.
        // used by find() and erase()
        BSTNode<T> *findNode(const T& item) const;

        #if 0
        // recursive function that builds a subtree of the shadow tree
        // corresponding to node t of the tree we are drawing. level is the
        // level-coordinate for the root of the subtree, and column is the
        // changing column-coordinate of the tree nodes
        tnodeShadow *buildShadowTree(BSTNode<T> *t, int level, int& column);

        // remove the shadow tree from memory after displayTree()
        // displays the binary search tree
        void deleteShadowTree(tnodeShadow *t);
        #endif
};

#include "BSTIterator.h"

template <typename T>
BSTNode<T>* BSTree<T>::getBSTNode(const T& item, BSTNode<T> *lptr,
                                 BSTNode<T> *rptr, BSTNode<T> *pptr)
{
    BSTNode<T> *newNode;

    // initialize the data and all pointers
    newNode = new BSTNode<T> (item, lptr, rptr, pptr);
    if (newNode == NULL)
        throw MemoryAllocationError("BSTree: memory allocation failure");

    return newNode;
}

template <typename T>
BSTNode<T> *BSTree<T>::copyTree(BSTNode<T> *t)
{
    BSTNode<T> *newlptr, *newrptr, *newNode;

    // if tree branch NULL, return NULL
    if (t == NULL)
        return NULL;
  
    // copy the left branch of root t and assign its root to newlptr
    newlptr = copyTree(t->left);

    // copy the right branch of tree t and assign its root to newrptr
    newrptr = copyTree(t->right);

    // allocate storage for the current root node, assign
    // its value and pointers to its left and right subtrees.
    // the parent pointer of newNode is assigned when
    // newNode's parent is created. if newNode is root,
    // NULL is the correct value for its parent pointer
    newNode = getBSTNode(t->nodeValue, newlptr, newrptr, NULL);

    // the current node is the parent of any subtree that
    // is not empty
    if (newlptr)
        newlptr->parent = newNode;
    if (newrptr)
        newrptr->parent = newNode;

    return newNode;
}

// delete the tree stored by the current object
template <typename T>
void BSTree<T>::deleteTree(BSTNode<T> *t)
{
    // if current root node is not NULL, delete its left subtree,
    // its right subtree and then the node itself
    if (t != NULL)
    {
        deleteTree(t->left);
        t->left = NULL;

        deleteTree(t->right);
        t->right = NULL;

        delete t;
    }
}

// search for data item in the tree. if found, return its node
// address; otherwise, return NULL
template <typename T>
BSTNode<T>* BSTree<T>::findNode(const T& item) const
{   
    // cycle t through the tree starting with root
    BSTNode<T> *t = root;

    // terminate on on empty subtree
    while(t && (item != t->nodeValue))
    {
        if (item < t->nodeValue)
            t = t->left;
        else 
            t = t->right;
    }

    // return pointer to node; NULL if not found
    return t;
}

template <typename T>
BSTree<T>::BSTree(): root(NULL), treeSize(0)
{}

template <typename T>
BSTree<T>::BSTree(T *first, T *last): root(NULL), treeSize(0)
{
    T *p = first;

    // insert each item in [first, last) into the tree
    while (p != last)
    {
        insert(*p);
        ++p;
    }
}

template <typename T>
BSTree<T>::BSTree(const BSTree<T>& tree): treeSize(tree.treeSize)
{
    // copy tree to the current object
    root = copyTree(tree.root);
}

template <typename T>
BSTree<T>::~BSTree()
{
    // erase the tree nodes from memory
    deleteTree(root);

    // tree is emtpy
    root = NULL;
    treeSize = 0;
}

template <typename T>
BSTree<T>& BSTree<T>::operator= (const BSTree<T>& rhs)
{
    // can't copy a tree to itself
    if (this == &rhs)
        return *this;

    // erase the existing tree nodes from memory
    deleteTree(root);

    // copy tree rhs into current object
    root = copyTree(rhs.root);

    // set the tree size
    treeSize = rhs.treeSize;

    // return reference to current object
    return *this;
}

template <typename T>
typename BSTree<T>::iterator BSTree<T>::find(const T& item)
{
    BSTNode<T> *curr;

    // search tree for item
    curr = findNode (item);

    // if item found, return const_iterator with value current;
    // otherwise, return end()
    if (curr != NULL)
        return iterator(curr, this);
    else
        return end();
}

template <typename T>
typename BSTree<T>::const_iterator BSTree<T>::find(const T& item) const
{
    BSTNode<T> *curr;

    // search tree for item
    curr = findNode (item);

    // if item found, return const_iterator with value current;
    // otherwise, return end()
    if (curr != NULL)
        return const_iterator(curr, this);
    else
        return end();
}

template <typename T>
int BSTree<T>::empty() const
{
    return root == NULL;
}

template <typename T>
int BSTree<T>::size() const
{
    return treeSize;
}

template <typename T>
std::pair<typename BSTree<T>::iterator, bool> BSTree<T>::insert(const T& item)
{
    // t is current node in traversal, parent the previous node
    BSTNode<T> *t = root, *parent = NULL, *newNode;

    // terminate on on empty subtree
    while(t)
    {
        // update the parent pointer. then go left or right
        parent = t;
        // if a match occurs, return a std::pair whose iterator
        // component points at item in the tree and whose
        // bool component is false
        if (item == t->nodeValue)
            return std::pair<iterator, bool> (iterator(t, this), false);
        else if (item < t->nodeValue)
            t = t->left;
        else 
            t = t->right;
    }
    
    // create the new leaf node
    newNode = getBSTNode(item,NULL,NULL,parent);

    // if parent is NULL, insert as root node
    if (parent == NULL)
        root = newNode;
    else if (item < parent->nodeValue)                   
        // insert as left child        
        parent->left = newNode;  
    else
        // insert as right child     
        parent->right = newNode;
  
    // increment size
    treeSize++;

    // return an std::pair whose iterator component points at
    // the new node and whose bool component is true
    return std::pair<iterator, bool> (iterator(newNode, this), true);
}

template <typename T>
void BSTree<T>::erase(iterator pos)
{
    // dNodePtr = pointer to node D that is deleted
    // pNodePtr = pointer to parent P of node D
    // rNodePtr = pointer to node R that replaces D
    BSTNode<T> *dNodePtr = pos.nodePtr, *pNodePtr, *rNodePtr;

    if (treeSize == 0)
        throw UnderflowError("BSTree erase(): tree is empty");

    if (dNodePtr == NULL)
        throw ReferenceError("BSTree erase(): invalid iterator");

    // assign pNodePtr the address of P
    pNodePtr = dNodePtr->parent;

    // If D has a NULL pointer, the
    // replacement node is the other child
    if (dNodePtr->left == NULL || dNodePtr->right == NULL)
    {
        if (dNodePtr->right == NULL)
            rNodePtr = dNodePtr->left;
        else
            rNodePtr = dNodePtr->right;

        if (rNodePtr)
            // the parent of R is now the parent of D
            rNodePtr->parent = pNodePtr;
    }
    // both pointers of dNodePtr are non-NULL.
    else
    {
        // find and unlink replacement node for D.
        // starting at the right child of node D,
        // find the node whose value is the smallest of all
        // nodes whose values are greater than the value in D.
        // unlink the node from the tree.
  
        // pOfRNodePtr = pointer to parent of replacement node
        BSTNode<T> *pOfRNodePtr = dNodePtr;

        // first possible replacement is right child of D
        rNodePtr = dNodePtr->right;

        // descend down left subtree of the right child of D,
        // keeping a record of current node and its parent.
        // when we stop, we have found the replacement
        while(rNodePtr->left)
        {
            pOfRNodePtr = rNodePtr;
            rNodePtr = rNodePtr->left;
        }
  
        if (pOfRNodePtr == dNodePtr)
        {
            // right child of deleted node is the replacement.
            // assign left subtree of D to left subtree of R
            rNodePtr->left = dNodePtr->left;
            // assign the parent of D as the parent of R
            rNodePtr->parent = pNodePtr;
            // assign the left child of D to have parent R
            dNodePtr->left->parent = rNodePtr;
        }
        else
        {
            // we moved at least one node down a left branch
            // of the right child of D. unlink R from tree by
            // assigning its right subtree as the left child of
            // the parent of R
            pOfRNodePtr->left = rNodePtr->right;

            // the parent of the right child of R is the
            // parent of R
            if (rNodePtr->right)
                rNodePtr->right->parent = pOfRNodePtr;

            // put replacement node in place of dNodePtr
            // assign children of R to be those of D
            rNodePtr->left = dNodePtr->left;
            rNodePtr->right = dNodePtr->right;
            // assign the parent of R to be the parent of D
            rNodePtr->parent = pNodePtr;
            // assign the parent pointer in the children
            // of R to point at R
            rNodePtr->left->parent = rNodePtr;
            rNodePtr->right->parent = rNodePtr;
        }
    }

    // complete the link to the parent node.

    // deleting the root node. assign new root
    if (pNodePtr == NULL)
        root = rNodePtr;
    // attach R to the correct branch of P
    else if (dNodePtr->nodeValue < pNodePtr->nodeValue)
        pNodePtr->left = rNodePtr;
    else
        pNodePtr->right = rNodePtr;
  
    // delete the node from memory and decrement tree size
    delete dNodePtr;
    treeSize--;
}

template <typename T>
int BSTree<T>::erase(const T& item)
{
    int numberErased = 1;
    // search tree for item
    BSTNode<T> *p  = findNode(item);

    // if item found, delete the node
    if (p)
        erase(iterator(p,this));
    else
        numberErased = 0;

    return numberErased;
}

template <typename T>
void BSTree<T>::erase(iterator first, iterator last)
{
    if (treeSize == 0)
        throw UnderflowError("BSTree erase(): tree is empty");

    iterator p = first;

    if (first == begin() && last == end())
    {
        // we are asked to erase the entire tree.
        // erase the tree nodes from memory
        deleteTree(root);

        // tree is emtpy
        root = NULL;
        treeSize = 0;
    }
    else
        // erase each item in a subrange of the tree
        while (p != last)
            erase(p++);
}

template <typename T>
typename BSTree<T>::iterator BSTree<T>::begin()
{
    BSTNode<T> *curr = root;

    // if the tree is not empty, the first node
    // inorder is the farthest node left from root
    if (curr != NULL)
        while (curr->left != NULL)
            curr = curr->left;

    // build return value using private constructor
    return iterator(curr, this);
}

template <typename T>
typename BSTree<T>::const_iterator BSTree<T>::begin() const
{
    const BSTNode<T> *curr = root;

    // if the tree is not empty, the first node
    // inorder is the farthest node left from root
    if (curr != NULL)
        while (curr->left != NULL)
            curr = curr->left;

    // build return value using private constructor
    return const_iterator(curr, this);
}

template <typename T>
typename BSTree<T>::iterator BSTree<T>::end()
{
    // end indicated by an iterator with NULL BSTNode pointer
    return iterator(NULL, this);
}

template <typename T>
typename BSTree<T>::const_iterator BSTree<T>::end() const
{
    // end indicated by an iterator with NULL BSTNode pointer
    return const_iterator(NULL, this);
}

#if 0
// recursive inorder scan used to build the shadow tree
template <typename T>
tnodeShadow *BSTree<T>::buildShadowTree(BSTNode<T> *t, int level, int& column)
{
    // pointer to new shadow tree node
    tnodeShadow *newNode = NULL;
    // text and ostr used to perform format conversion
    char text[80];
    ostrstream ostr(text,80);

    if (t != NULL)
    {
        // create the new shadow tree node
        newNode = new tnodeShadow;

        // allocate node for left child at next level in tree; attach node
        tnodeShadow *newLeft = buildShadowTree(t->left, level+1, column);
        newNode->left = newLeft;

        // initialize data members of the new node
        ostr << t->nodeValue << ends;   // format conversion
        newNode->nodeValueStr = text;
        newNode->level = level;
        newNode->column = column;

        // update column to next cell in the table
        column++;

        // allocate node for right child at next level in tree; attach node
        tnodeShadow *newRight = buildShadowTree(t->right, level+1, column);
        newNode->right = newRight;
    }

    return newNode;
}

template <typename T>
void BSTree<T>::displayTree(int maxCharacters)
{
    string label;
    int level = 0, column = 0;
    int colWidth = maxCharacters + 1;
    // 
    int currLevel = 0, currCol = 0;

    if (treeSize == 0)
        return;

    // build the shadow tree
    tnodeShadow *shadowRoot = buildShadowTree(root, level, column);

    // use during the level order scan of the shadow tree
    tnodeShadow *currNode;

   // store siblings of each tnodeShadow object in a queue so that
    // they are visited in order at the next level of the tree
   queue<tnodeShadow *> q;

   // insert the root in the queue and set current level to 0
   q.push(shadowRoot);
   
   // continue the iterative process until the queue is empty
   while(!q.empty())
   {
      // delete front node from queue and make it the current node
      currNode = q.front();
        q.pop();

        // if level changes, output a newline
        if (currNode->level > currLevel)
        {
            currLevel = currNode->level;
            currCol = 0;
            cout << endl;
        }

        // if a left child exists, insert the child in the queue
      if(currNode->left != NULL)
            q.push(currNode->left);

        // if a right child exists, insert the child in the queue
      if(currNode->right != NULL)
            q.push(currNode->right);

        // output formatted node label
        if (currNode->column > currCol)
        {
            cout << setw((currNode->column-currCol)*colWidth) << " ";
            currCol = currNode->column;
        }
        cout << setw(colWidth) << currNode->nodeValueStr;
        currCol++;
   }
    cout << endl;

    // delete the shadow tree
    deleteShadowTree(shadowRoot);
}

template <typename T>
void BSTree<T>::deleteShadowTree(tnodeShadow *t)
{
    // if current root node is not NULL, delete its left subtree,
    // its right subtree and then the node itself
    if (t != NULL)
    {
        deleteShadowTree(t->left);
        deleteShadowTree(t->right);
        delete t;
    }
}
#endif

#endif  // BINARY_SEARCH_TREE_CLASS
