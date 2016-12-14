#include <iostream>
#include "LinkedListFunctions.h"

using namespace std;

int main()
{
    Node<int>* head = NULL;

    // Insert 6.  So linked list becomes 6->NULL
    Append(head, 6);

    // Insert 7 at the beginning. So linked list becomes 7->6->NULL
    Push(head, 7);

    // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
    Push(head, 1);

    // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
    Append(head, 4);

    // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
    InsertAfter(head->next, 8);

    cout << "\nCreated Linked List is: \n";
    PrintList(head);

    int val{};
    cout << "\nEnter the value to be deleted: ";
    cin >> val;
    Erase(head, val);
    cout << "\nLinked List after Deletion of " << val << ":\n";
    PrintList(head);
    
    cout << "\nLength of the linked list: " << GetCountRecursive(head) << endl;

    int x{}, y{};
    cout << "\nEnter the values to be swapped: ";
    cin >> x >> y;

    SwapNodes(head, x, y);
    cout << "\nLinked List after swapping " << x << " and " << y << ":\n";
    PrintList(head);
 
    return 0;
}
