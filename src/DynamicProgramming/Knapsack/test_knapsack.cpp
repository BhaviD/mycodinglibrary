// the program demonstrates the dynamic programming solution
// to the knapsack problem. the vector itemList contains
// five items, each with a specified size and value. after
// prompting for the capacity of the knapsack, the program
// declares a knapsack object for the items and the desired
// capacity. calling displayKnapsack() outputs the maximum
// value for the capacity, the contents of the knapsack, and
// the unused capacity

#include <iostream>
#include <vector>

#include "Knapsack.h"

using namespace std;

int main()
{
    //Item itemArr[] = {Item(2,1), Item(3,4), Item(4,3),
    //                        Item(5,6), Item(6,8)};
    //int arrSize = sizeof(itemArr)/sizeof(Item);
    //vector<Item> itemList(itemArr, itemArr+arrSize);
    vector<Item> itemList {Item(2,1), Item(3,4), Item(4,3),
                           Item(5,6), Item(6,8)};
    int capacity;

    cout << "Enter the capacity: ";
    cin >> capacity;

    // create a knapsack object
    Knapsack ks(itemList, capacity);

    // ks.displayMaxValueMat();     // add for diagnostics
    // display the solution
    ks.displayKnapsack(); 
    cout << endl << endl;

    return 0;
}

/*
Run 1:

Enter the capacity: 12

Capacity: 12  Value: 14

Contents:

   item5(6,8)
   item4(5,6)
   Unused capacity: 1

Run 2:

Enter the capacity: 19

Capacity: 19  Value: 21

Contents:

   item5(6,8)
   item4(5,6)
   item3(4,3)
   item2(3,4)
   Unused capacity: 1
*/
