#include <iostream>
#include "PostfixEval/PostfixEval.h"
using namespace std;

int main()
{
    PostfixEval exp;
    string rpnExp;
    cout << "Enter the postfix expression: ";
    getline(cin, rpnExp);

    // assign the expression to exp
    exp.setPostfixExp(rpnExp);

    // call evaluate() in a try block in case an error occurs
    try
    {
        cout << "The value of the expression = "
             << exp.evaluate() << endl;
    }
    // catch block output the error using what()
    catch (const ExpressionError& ee)
    {
        cout << ee.what() << endl << endl;
    }
    return 0;
}
