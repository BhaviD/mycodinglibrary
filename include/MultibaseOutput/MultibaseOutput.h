#ifndef _MULTIBASE_OUTPUT_H_
#define _MULTIBASE_OUTPUT_H_

#include <string>
#include <stack>

std::string MultibaseOutput(int num, int b)
{
    // digitChar[digit] is the character that represents
    // the digit, 0 <= digit <= 15
    std::string digitChar = "0123456789ABCDEF", numStr = "";

    // stack holds the base-b digits of num
    std::stack<char> stk;

    // extract base b digits right to left and push on stack s
    do
    {
        // push right-most digit on the stack
        stk.push(digitChar[num % b]);
        num /= b;               // remove right-most digit from num
    } while (num != 0);     // continue until all digits found

    while (!stk.empty())        // flush the stack
    {
        numStr += stk.top();    // add digit on top of stack to numStr
        stk.pop();              // pop the stack
    }

    return numStr;
}

#endif
