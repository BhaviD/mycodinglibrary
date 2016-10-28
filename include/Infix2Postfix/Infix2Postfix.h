#ifndef _INFIX_TO_POSTFIX_H_
#define _INFIX_TO_POSTFIX_H_

#include <iostream>
#include <string>
#include <stack>
#include "Infix2Postfix/ExpressionSymbol/ExpressionSymbol.h"   // ExpressionSymbol class
#include "Exception/Exception.h"   // for ExpressionError exception

// labels designating the parentheses characters
const char lParen  = '(', rParen = ')';

class Infix2Postfix
{
    public:
        // default constructor. infix expression is NULL string
        Infix2Postfix();
        // initialize the infix expression
        Infix2Postfix(const std::string& infixExp);

        // change the infix expression
        void setInfixExp(const std::string& infixExp);

        // return a string that contains the equivalent postfix
        // expression. the function throws ExpressionError if an
        // error occurs during conversion
        std::string postfix();

    private:

        // the infix expression to convert
        std::string infixExpression;
        // built to contain the postfix equivalent of infixExpression
        std::string postfixExpression;
        // stack of ExpressionSymbol objects
        std::stack<ExpressionSymbol> operatorStack;

        // the ExpressionSymbol object op holds the current
        // symbol. pop the stack and output as long as the symbol
        // on the top of the stack has a precedence >= that of
        // the current operator
        void outputHigherOrEqual(const ExpressionSymbol& op);

        // is ch one of '+','-','*','/','%','^'
        bool isOperator(char ch) const;
};


void Infix2Postfix::outputHigherOrEqual(const ExpressionSymbol& op)
{
    ExpressionSymbol op2;

    while(!operatorStack.empty() &&
            (op2 = operatorStack.top()) >= op)
    {
        operatorStack.pop();
        postfixExpression += op2.getOp();
        postfixExpression += ' ';
    }
}

bool Infix2Postfix::isOperator(char ch) const
{
    return ch == '+' || ch == '-' || ch == '*' ||
             ch == '%' || ch == '/' || ch == '^';
}

Infix2Postfix::Infix2Postfix()
{}

Infix2Postfix::Infix2Postfix(const std::string& infixExp):
        infixExpression(infixExp)
{}

void Infix2Postfix::setInfixExp(const std::string& infixExp)
{
    // assign a new infix expression
    infixExpression = infixExp;
    // make postfixExpression the NULL string
    postfixExpression = "";
}

std::string Infix2Postfix::postfix()
{
    ExpressionSymbol op;
    // maintain rank for error checking
    int rank = 0, i;
    char ch;

    // process until end of the expression
    for (i = 0; i < infixExpression.length(); ++i)
    {
        ch = infixExpression[i];

        //  ********  process an operand  ********
        // an operand is a single digit non-negative integer
        if (isdigit(ch))
        {
            // just add operand to output expression, followed by
            // a blank
            postfixExpression += ch;
            postfixExpression += ' ';
            // rank of an operand is 1, accumulated rank
            // must be 1
            rank++;
            if (rank > 1)
                throw ExpressionError("Infix2Postfix: Operator expected");
        }
        //  *********  process an operator or '('  **********
        else if (isOperator(ch) || ch == '(')
        {
            // rank of an operator is -1. rank of '(' is 0.
            // accumulated rank should be 0
            if (ch != '(')
                    rank--;

            if (rank < 0)
                throw ExpressionError("Infix2Postfix: Operand expected");
            else
            {
                // output the operators on the stack with higher
                // or equal precedence. push the current operator
                // on the stack
                op = ExpressionSymbol(ch);
                outputHigherOrEqual(op);
                operatorStack.push(op);
            }
        }
        //  *********  process a right parenthesis  **********
        else if (ch == rParen)
        {
            // build an ExpressionSymbol object holding ')', which
            // has precedence lower than the stack precedence
            // of any operator except '('. pop the operator stack
            // and output operators from the subexpression until
            // '(' surfaces or the stack is empty. if the stack is
            // empty, a '(' is missing; otherwise, pop off '('.
            op = ExpressionSymbol(ch);
            outputHigherOrEqual(op);
            if(operatorStack.empty())
                throw ExpressionError("Infix2Postfix: Missing '('");
            else
                operatorStack.pop(); // get rid of '('
        }
        //  *********  make sure ch is whitespace  **********
        else if (!isspace(ch))
            throw ExpressionError("Infix2Postfix: Invalid input");
    }

    // finish processing
    if (rank != 1)
        throw ExpressionError("Infix2Postfix: Operand expected");
    else
    {
        // flush operator stack and complete expression evaluation.
        // if find left parenthesis, a right parenthesis is
        // missing.
        while (!operatorStack.empty())
        {
            op = operatorStack.top();
            operatorStack.pop();
            if (op.getOp() == lParen)
                throw ExpressionError("Infix2Postfix: Missing ')'");
            else
            {
                postfixExpression += op.getOp();
                postfixExpression += ' ';
            }
        }
    }

    return postfixExpression;
}

#endif  // _H_INFIX_TO_POSTFIX_H_
