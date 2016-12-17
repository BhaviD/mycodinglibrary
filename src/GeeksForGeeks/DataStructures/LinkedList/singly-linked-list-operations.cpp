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

    cout << "\nCreated Linked List is:";
    PrintList(head);

    int val{};
    cout << "\nEnter the value to be deleted: ";
    cin >> val;
    Erase(head, val);
    cout << "\nLinked List after Deletion of " << val << ":";
    PrintList(head);
    
    cout << "\nLength of the linked list: " << GetCountRecursive(head) << endl;

    int x{}, y{};
    cout << "\nEnter the values to be swapped: ";
    cin >> x >> y;

    SwapNodes(head, x, y);
    cout << "\nLinked List after swapping " << x << " and " << y << ":";
    PrintList(head);

    Reverse(head);
    cout << "\nReversed Linked List:";
    PrintList(head);

    cout << "\nErasing the linked list!!!\n";
    EraseAll(head);

    Append(head, 3);
    Append(head, 1);
    Append(head, 23);
    Append(head, 4);
    Append(head, 30);
    Append(head, 18);

    Node<int>* head2 = NULL;
    Append(head2, 8);
    Append(head2, 2);
    Append(head2, 15);
    Append(head2, 21);
    Append(head2, 16);
    Append(head2, 5);

    cout << "\nThe Two Un-Sorted Linked Lists are:";
    PrintList(head);
    PrintList(head2);
    MergeSort(head);
    MergeSort(head2);
    cout << "\nThe Two Sorted Linked Lists are:";
    PrintList(head);
    PrintList(head2);

    cout << "\nMerged Linked List:";
    head = SortedMergeRecursive(head, head2);
    PrintList(head);

    int k{};
    cout << "\nEnter the size of groups to be reversed: ";
    cin >> k;
    head = Reverse(head, k);
    cout << "\nReversed Linked List:";
    PrintList(head);

    return 0;
}
