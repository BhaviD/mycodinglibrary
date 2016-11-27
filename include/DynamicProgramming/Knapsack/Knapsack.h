#ifndef _KNAPSACK_H_
#define _KNAPSACK_H_

#include <iostream>
#include <iomanip>
#include <vector>

#include "Matrix.h"

// specifies the size and value of an item
class Item
{
    public:
        int size;
        int value;

        Item(int s = 0, int v = 0) : size(s), value(v)
        {}
};

class Knapsack
{
    public:
        // constructor. assigns v as the Item list and calls
        // buildMaxValueMat() to implement the knapsack algorithm 
        Knapsack(std::vector<Item>& v, int cap);

        // displays the capacity, the maximum value, the unused
        // space, and a list of the Items with their size and value
        void displayKnapsack();

        // output the row/column values in the matrix
        void displayMaxValueMat();
    private:
        int capacity;
        int numItems;
        std::vector<Item> itemList;
        Matrix<int> maxValueMat;

        // implements the knapsack algorithm
        void buildMaxValueMat();
};

void Knapsack::buildMaxValueMat()
{
    int testMax;

    // compute entries in the matrix
    for (int i = 1; i <= numItems; ++i)
    {
        for (int cap = 1; cap <= capacity; ++cap)
        {
            // keep the same max value by default
            maxValueMat[i][cap] = maxValueMat[i - 1][cap];

            // test if itemList[i] fits into the knapsack
            if (cap - itemList[i].size >= 0)
            {
                // test if maximum value increases
                testMax = maxValueMat[i - 1][cap - itemList[i].size] + 
                                itemList[i].value;
                // if yes, assign new max 
                if (testMax > maxValueMat[i - 1][cap])
                    maxValueMat[i][cap] = testMax;
            }
        }
    }
}

Knapsack::Knapsack(std::vector<Item>& v, int cap): 
             capacity(cap), numItems(v.size())
{
    int i;

    // initialize dimensions for itemList and maxValueMat
    itemList.resize(numItems + 1);
    maxValueMat.resize(numItems + 1, capacity + 1);

    // initialize itemList from v so that item1 = v[0]
    // is in itemList[1], item2 = v[1] is in itemList[2],
    // and so forth
    for (i = 1; i <= numItems; ++i)
        itemList[i] = v[i - 1];

    // build the matrix
    buildMaxValueMat();
}

void Knapsack::displayKnapsack()
{
    int i = numItems, cap = capacity;
    std::cout << std::endl << "Capacity: " << capacity << "  Value: "
          << maxValueMat[numItems][capacity] << std::endl << std::endl;
    std::cout << "Contents: " << std::endl << std::endl;

    // scan list of items in reverse order
    while (i > 0)
    {
        // if values in successive rows are not equal,
        // itemList[i] is part of the solution
        if (maxValueMat[i][cap] != maxValueMat[i - 1][cap])
        {
            std::cout << "   item" << i << '(' << itemList[i].size
                  << ',' << itemList[i].value << ')' << std::endl;
            // look for maximum value remaining space
            cap -= itemList[i].size;
        }
        i--;
    }
    std::cout << "   Unused capacity: " << cap << std::endl;
}

void Knapsack::displayMaxValueMat()
{
    int i, cap;

    std::cout << "Maximum value matrix for capacity " << capacity << std::endl;
    std::cout << "   ";
    for(i = 1; i <= capacity; i++)
        std::cout << std::setw(4) << i;
    std::cout << std::endl << std::endl;

    for (i = 1; i <= numItems; i++)
    {
        std::cout << i << "  ";
        for (cap = 1; cap <= capacity; cap++)
            std::cout << std::setw(4) << maxValueMat[i][cap];
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

#endif  // _KNAPSACK_H_
