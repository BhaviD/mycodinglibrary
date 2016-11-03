#ifndef _BINARY_TREE_FUNCTIONS_H_
#define _BINARY_TREE_FUNCTIONS_H_

#include <iostream>
//#include <strstream>
#include <iomanip>
#include <string>
#include <queue>

#ifndef NULL
#include <cstddef>
#endif  // NULL

#include "TNode.h"        // use TNode class


#if 0
// objects hold a formatted label string and the level,column
// coordinates for a shadow tree node
class TNodeShadow
{
    public:
        std::string nodeValueStr;    // formatted node value
        int level,column;
        TNodeShadow *left, *right;

        TNodeShadow ()
        {}
};
#endif

// create one of three binary trees with character data.
// the argument n selects from tree 0 - tree 2
TNode<char> *BuildTree(int n);

// InOrder recursive output of the nodes in a binary tree.
// output separator after each node value. default value
// of separator is "  "
template <typename T>
void InOrderOutput(TNode<T> *t, const std::string& separator = " ");

// PostOrder recursive output of the nodes in a binary tree.
// output separator after each node value. default value
// of separator is "  "
template <typename T>
void PostOrderOutput(TNode<T> *t, const std::string& separator = " ");

// traverse the tree level by level and output each node in a
// binary tree. output separator after each node value. default value
// of separator is "  "
template <typename T>
void LevelOrderOutput(TNode<T> *t, const std::string& separator = " ");

// accumulate the number of leaf nodes in count
template <typename T>
void CountLeaf(TNode<T> *t, int& count);

// return the depth of the binary tree
template <typename T>
int Depth (TNode<T> *t);

// create copy of tree t and return a pointer to the new root
template <typename T>
TNode<T> *CopyTree(TNode<T> *t);

// traverse the nodes in the binary tree and delete each node
template <typename T>
void DeleteTree(TNode<T> *t);

// delete all tree nodes using DeleteTree() and then assign
// t to be NULL
template <typename T>
void ClearTree(TNode<T> * & t);

#if 0
// recursive InOrder scan used to build the shadow tree
template <typename T>
TNodeShadow *buildShadowTree(TNode<T> *t, int level, int& column);

// display a binary tree. output of a node value requires
// no more than maxCharacters
template <typename T>
void displayTree(TNode<T> *t, int maxCharacters);

// delete the nodes in the shadow tree
void deleteShadowTree(TNodeShadow *t);
#endif

TNode<char> *BuildTree(int n)
{
    // 9 TNode pointers; points to the 9 items in the tree
    TNode<char> *root, *b, *c, *d, *e, *f, *g, *h, *i;

    // parameter n specifies a tree in the range 0 - 2
    switch(n)
    {
        // nodes d and e are leaf nodes
        case 0:
            d = new TNode<char> ('D');
            e = new TNode<char> ('E');
            b = new TNode<char> ('B',(TNode<char> *)NULL, d);
            c = new TNode<char> ('C',e, (TNode<char> *)NULL);
            root = new TNode<char> ('A',b, c);
            break;

        // nodes g, h, i, and d are leaf nodes
        case 1:
            g = new TNode<char> ('G');
            h = new TNode<char> ('H');
            i = new TNode<char> ('I');
            d = new TNode<char> ('D');
            e = new TNode<char> ('E',g, (TNode<char> *)NULL);
            f = new TNode<char> ('F',h, i);
            b = new TNode<char> ('B',d, e);
            c = new TNode<char> ('C',(TNode<char> *)NULL, f);
            root = new TNode<char> ('A',b, c);
            break;

        // nodes g, h, i and f are leaf nodes
        case 2:
            g = new TNode<char> ('G');
            h = new TNode<char> ('H');
            i = new TNode<char> ('I');
            d = new TNode<char> ('D',(TNode<char> *)NULL, g);
            e = new TNode<char> ('E',h, i);
            f = new TNode<char> ('F');
            b = new TNode<char> ('B',d, (TNode<char> *)NULL);
            c = new TNode<char> ('C',e, f);
            root = new TNode<char> ('A',b, c);
            break;
    }

    return root;
}

template <typename T>
void InOrderOutput(TNode<T> *t, const std::string& separator)
{
   // the recursive scan terminates on a empty subtree
   if (t != NULL)
   {
      InOrderOutput(t->left, separator);    // descend left
      std::cout << t->nodeValue << separator;    // output the node
      InOrderOutput(t->right, separator);   // descend right
   }
}

template <typename T>
void PostOrderOutput(TNode<T> *t, const std::string& separator)
{
   // the recursive scan terminates on a empty subtree
   if (t != NULL)
   {
      PostOrderOutput(t->left, separator);  // descend left
      PostOrderOutput(t->right, separator); // descend right
      std::cout << t->nodeValue << separator;    // output the node
   }
}

template <typename T>
void LevelOrderOutput(TNode<T> *t, const std::string& separator)
{
   // store siblings of each node in a queue so that they are
   // visited in order at the next level of the tree
   std::queue<TNode<T> *> q;
   TNode<T> *p;

   // initialize the queue by inserting the root in the queue
   q.push(t);

   // continue the iterative process until the queue is empty
   while(!q.empty())
   {
        // delete front node from queue and output the node value
        p = q.front();
        q.pop();
        std::cout << p->nodeValue << separator;

        // if a left child exists, insert it in the queue
        if(p->left)
            q.push(p->left);
        // if a right child exists, insert next to its sibling
        if(p->right)
            q.push(p->right);
    }
}

// assume that count initialized to 0
template <typename T>
void CountLeaf (TNode<T> *t, int& count)
{
   if (t)
   {
      // check if t is a leaf node (no children).
      // if so, increment count
      if (t->left == NULL && t->right == NULL)
         count++;

        CountLeaf(t->left, count);  // descend left
        CountLeaf(t->right, count); // descend right
   }
}

// determine the depth of the tree using a PostOrder scan
template <typename T>
int Depth (TNode<T> *t)
{
   int depthLeft, depthRight, depthval;

   if (NULL == t)
        // depth of an empty tree is -1
      depthval = -1;
   else
    {
        // find the depth of the left subtree of t
        depthLeft = Depth(t->left);
        // find the depth of the right subtree of t
        depthRight = Depth(t->right);
        // depth of the tree with root t is 1 + maximum
        // of the depths of the two subtrees
        depthval = 1 +
            (depthLeft > depthRight ? depthLeft : depthRight);
   }

    return depthval;
}

template <typename T>
TNode<T> *CopyTree(TNode<T> *t)
{
    // newNode points at a new node that the algorithm
    // creates. newLptr. and newRptr point to the subtrees
    // of newNode
    TNode<T> *newLeft, *newRight, *newNode;

    // stop the recursive scan when we arrive at empty tree
    if (t == NULL)
        return NULL;

    // build the new tree from the bottom up by building the two
    // subtrees and then building the parent. at node t, make
    // a copy of the left subtree and assign its root node pointer
    // to newLeft. make a copy of the right subtree and assign its
    // root node pointer to newRight
    newLeft = CopyTree(t->left);
    newRight = CopyTree(t->right);

    // create a new node whose value is the same as the value in t
    // and whose children are the copied subtrees
    newNode = new TNode<T> (t->nodeValue, newLeft, newRight);

    // return a pointer to the root of the newly copied tree
    return newNode;
}

template <typename T>
void DeleteTree(TNode<T> *t)
{
    // PostOrder scan. delete left and right
    // subtrees of t and then node t
    if (t != NULL)
    {
        DeleteTree(t->left);
        t->left = NULL;

        DeleteTree(t->right);
        t->right = NULL;

        delete t;
    }
}

template <typename T>
void ClearTree(TNode<T>* &t)
{
    DeleteTree(t);
    t = NULL;
}

#if 0
template <typename T>
TNodeShadow *buildShadowTree(TNode<T> *t, int level, int& column)
{
    // pointer to new shadow tree node
    TNodeShadow *newNode = NULL;
    // text and ostr used to perform format conversion
    char text[80];
    ostrstream ostr(text,80);

    if (t != NULL)
    {
        // create the new shadow tree node
        newNode = new TNodeShadow;

        // allocate node for left child at next level in tree; attach node
        TNodeShadow *newLeft = buildShadowTree(t->left, level+1, column);
        newNode->left = newLeft;

        // initialize data members of the new node
        ostr << t->nodeValue << ends;   // format conversion
        newNode->nodeValueStr = text;
        newNode->level = level;
        newNode->column = column;

        // update column to next cell in the table
        column++;

        // allocate node for right child at next level in tree; attach node
        TNodeShadow *newRight = buildShadowTree(t->right, level+1, column);
        newNode->right = newRight;
    }

    return newNode;
}

template <typename T>
void displayTree(TNode<T> *t, int maxCharacters)
{
    std::string label;
    int level = 0, column = 0;
    int colWidth = maxCharacters + 1;
    //
    int currLevel = 0, currCol = 0;

    if (t == NULL)
        return;

    // build the shadow tree
    TNodeShadow *shadowRoot = buildShadowTree(t, level, column);

    // use during the level order scan of the shadow tree
    TNodeShadow *currNode;

   // store siblings of each TNodeShadow object in a queue so that
    // they are visited in order at the next level of the tree
   std::queue<TNodeShadow *> q;

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
            std::cout << std::endl;
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
            std::cout << setw((currNode->column-currCol)*colWidth) << " ";
            currCol = currNode->column;
        }
        std::cout << setw(colWidth) << currNode->nodeValueStr;
        currCol++;
   }
    std::cout << std::endl;

    // delete the shadow tree
    deleteShadowTree(shadowRoot);
}

void deleteShadowTree(TNodeShadow *t)
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

#endif   // _BINARY_TREE_FUNCTIONS_H_
