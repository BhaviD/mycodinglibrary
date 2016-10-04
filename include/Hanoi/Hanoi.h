#ifndef _HANOI_H_
#define _HANOI_H_

#include <string>

// move n disks from initNeedle to endNeedle, using tempNeedle
// for intermediate storage of the disks
void hanoi(int n, const std::string& initNeedle,
           const std::string& endNeedle, const std::string& tempNeedle)
{
    // stopping condition: move one disk
    if(n == 1)
        std::cout << "move " << initNeedle << " to "
             << endNeedle << std::endl;
    else
    {
        // move n - 1 disks from initNeedle to
        // tempNeedle using endNeedle for temporary storage
        hanoi(n - 1, initNeedle, tempNeedle, endNeedle);

        // move largest disk to endNeedle
        std::cout << "move " << initNeedle << " to "
             << endNeedle << std::endl;

        // move takes n - 1 disks from tempNeedle to 
        // endNeedle using initNeedle for temporary storage
        hanoi(n - 1, tempNeedle, endNeedle, initNeedle);
    }
}

#endif
