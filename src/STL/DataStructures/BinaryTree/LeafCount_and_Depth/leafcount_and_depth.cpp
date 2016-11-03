// the program builds the sample Tree 1 and calls
// countLeaf() to determine the number of leaf nodes
// in the tree. it then calls depth() to compute
// the depth of the tree

#include <iostream>

#include "TNode.h"    // TNode class
#include "BinaryTreeFunctions.h"

using namespace std;

int main()
{
    // root of the tree
    TNode<char> *root;
    int leafCount;

    // use the character Tree 1 
    root = BuildTree(1);

    // we accumulate the number of leaf nodes in leafCount,
    // so it must have initial value 0
    leafCount = 0;
    // call countLeaf() and output leaf count
    CountLeaf(root, leafCount);  
    cout << "Number of leaf nodes is " << leafCount << endl;

    // make call to depth() and output the depth of the tree
    cout << "The depth of the tree is "
          << Depth(root) << endl;

    return 0;
}

/*
Run:

Number of leaf nodes is 4
The depth of the tree is 3
*/
