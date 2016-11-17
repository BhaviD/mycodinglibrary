#include <iostream>
#include "MBSTree.h"         // MBSTree class

using namespace std;

int main()
{
    int arr[] = {5, 3, 4, 1, 5, 2, 3, 7, 2, 6, 2, 3, 10, 8, 1,
                 2, 15, 9, 8, 2, 5, 3, 8, 1, 7, 0, 4, 9, 5};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int val = 0;
    MBSTree<int> mbstree(arr, arr + arrSize);

    cout << "Size of the tree = " << mbstree.size() << endl;
    cout << "Original Tree: " << endl;
    mbstree.displayTree(2);

    cout << "\n\nInserting 8 in the tree." << endl;
    mbstree.insert(8);
    mbstree.displayTree(2);

    cout << "\n\nEnter a value to find in the tree: ";
    cin >> val;
    if(mbstree.find(val) != mbstree.end())
    {
        cout << "\n" << val << " is present in the tree!!!";
        cout << "\n" << val << " has " << mbstree.count(val) << " occurrence(s) in the tree!!!";
    }
    else
        cout << "\n" << val << " is NOT present in the tree!!!";

    cout << "\n\nErase all occurrences of 2!!" << endl;
    mbstree.erase(2);
    mbstree.displayTree(2);
    cout << "\n\nNow 2 has " << mbstree.count(2) << " occurrence(s) in the tree!!!\n";

    try
    {
        cout << *mbstree.end();
    }
    catch(const ReferenceError& re)
    {
        cout << re.what() << endl;
    }

    return 0;
}
