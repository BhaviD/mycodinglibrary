#include <iostream>
#include <string>

#include "Infix2Postfix/Infix2Postfix.h"       // Infix2Postfix class
#include "PostfixEval/PostfixEval.h"         // PostfixEval class
#include "Exception/Exception.h"         // PostfixEval class

using namespace std;

int main()
{
    // use iexp for infix to postfix conversion
    Infix2Postfix iexp;
    // infix expression input and postfix expression output
    string infixExp, postfixExp;
    // use pexp to evaluate postfix expressions
    PostfixEval pexp;

    // input and evaluate infix expressions until the
    // user enters an empty string

    // get the first expression
    cout << "Enter an infix expression (Empty string to exit): ";
    getline(cin, infixExp);

    while (infixExp != "")
    {
        // an exception may occur. enclose the conversion
        // to postfix and the output of the expression
        // value in a try block
        try
        {
            // convert to postfix
            iexp.setInfixExp(infixExp);
            postfixExp = iexp.postfix();

            // output the postfix expression
            cout << "The postfix form is " << postfixExp
                  << endl;

            // use pexp to evaluate the postfix expression
            pexp.setPostfixExp(postfixExp);
            
            cout << "Value of the expression = "
                  << pexp.evaluate() << endl << endl;
        }

        // catch an exception and output the error
        catch (const ExpressionError& ee)
        {
            cout << ee.what() << endl << endl;
        }
        // input another expression
        cout << "Enter an infix expression (Empty string to exit): ";
        getline(cin, infixExp);
    }

    return 0;
}

/*
Run:

Enter an infix expression: 3 ^ 2 ^ (1+2)
The postfix form is 3 2 1 2 + ^ ^
Value of the expression = 6561

Enter an infix expression: 3 * (4 - 2 ^ 5) + 6
The postfix form is 3 4 2 5 ^ - * 6 +
Value of the expression = -78

Enter an infix expression: (7 + 8*7
Infix2Postfix: Missing ')'

Enter an infix expression: (9 + 7) 4
Infix2Postfix: Operator expected

Enter an infix expression: 2*4*8/
Infix2Postfix: Operand expected

Enter an infix expression:
*/
