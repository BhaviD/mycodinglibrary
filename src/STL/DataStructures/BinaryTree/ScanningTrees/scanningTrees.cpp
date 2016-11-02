// the program demonstrates the InOrder and PostOrder
// recursive binary tree scanning algorithms and the
// iterative level-order scanning algorithm. using the
// function BuildTree(), construct Tree 1 and call the
// tree output algorithms from the library "d_tlib.h".

#include <iostream>

#include "TNode.h"                 // TNode class
#include "BinaryTreeFunctions.h"   // TNode library

using namespace std;

int main()
{
    // root of the tree
    TNode<char> *root;

    // use the character Tree 1 
    root = BuildTree(1);

    // give InOrder scan of nodes  
    cout << "InOrder scan:      " ;
    InOrderOutput(root);
    cout << endl;

    // give PostOrder scan of nodes   
    cout << "Postorder scan:    " ;
    PostOrderOutput(root);
    cout << endl;

    // give level order scan of nodes   
    cout << "Level-order scan:  " ;
    LevelOrderOutput(root);
    cout << endl;

    return 0;
}

/*
Run:

InOrder scan:      D  B  G  E  A  C  H  F  I
Postorder scan:    D  G  E  B  H  I  F  C  A
Level-order scan:  A  B  C  D  E  F  G  H  I
*/
