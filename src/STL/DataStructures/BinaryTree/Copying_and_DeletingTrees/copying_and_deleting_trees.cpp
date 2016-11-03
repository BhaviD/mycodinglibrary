// the program builds the sample Tree 2 and displays the tree.
// by using CopyTree(), the program makes a copy of Tree 2,and
// displays the copied tree. the program terminates after using
// ClearTree() to delete the nodes in both trees

#include <iostream>

#include "TNode.h"        // TNode class
#include "BinaryTreeFunctions.h"

using namespace std;

int main()
{
    // roots for two trees
    TNode<char> *root1, *root2;

    // build the character Tree 2 with root root2
    root1 = BuildTree(2);

    #if 0
    // display the tree
    cout << "Original tree (Tree 2)" << endl;
    displayTree(root1, 1);
    cout << endl << endl;
    #endif

    // make a copy of root1 so its root is root2
    root2 = CopyTree(root1);

    #if 0
    // display the tree copy
    cout << "Copy of Tree 2" << endl;
    displayTree(root2, 1);
    cout << endl;
    #endif

    // delete the nodes in the two trees
    ClearTree(root1);
    ClearTree(root2);

    return 0;
}

/*
Run:

Original tree (Tree 2)
       A
     B         C
 D         E     F
   G     H   I


Copy of Tree 2
       A
     B         C
 D         E     F
   G     H   I
*/
