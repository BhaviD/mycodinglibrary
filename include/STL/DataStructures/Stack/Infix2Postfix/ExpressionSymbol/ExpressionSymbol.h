#ifndef INFIX_SYMBOLS
#define INFIX_SYMBOLS

// a class that maintains the precedence of symbols
class ExpressionSymbol
{
    public:
        // default constructor
        ExpressionSymbol();
        // initializes the object for operator ch
        ExpressionSymbol(char ch);

        // return true if stackPrecedence of left is
        // >= inputPrecedence of right. determines whether
        // operator left on the stack should be output before
        // pushing operator right on the stack
        friend bool operator>= (const ExpressionSymbol& left,
                                        const ExpressionSymbol& right);

        // return operator        
        char getOp() const;

    private:
        // operator
        char op;
        // input precedence of op
        int inputPrecedence;
        // stack precedence of op
        int stackPrecedence;
};

// default constructor
ExpressionSymbol::ExpressionSymbol()
{}

// constructor that assigns operator and precedence values
ExpressionSymbol::ExpressionSymbol(char ch)
{
    op = ch;    // assign operator

    switch(op)
    {
        // '+' and '-' have input/stack precedence 1
        case '+':  
        case '-': inputPrecedence = 1;
                  stackPrecedence = 1;
                  break;
                       
        // '*', '%', and '/' have input/stack precedence 2
        case '*':   
        case '%':   
        case '/': inputPrecedence = 2;
                  stackPrecedence = 2;
                  break;
                   
        // '^' is right associative. input precedence 4
        // and stack precedence 3
        case '^': inputPrecedence = 4;
                  stackPrecedence = 3;
                  break;

        // '(' has input precendence 5, stack precedence -1
        case '(': inputPrecedence = 5;
                  stackPrecedence = -1;
                  break;
                   
        // ')' has input/stack precedence 0
        case ')': inputPrecedence = 0;
                  stackPrecedence = 0;
                  break;
    }
}

char ExpressionSymbol::getOp() const
{
    return op;
}

bool operator>= (const ExpressionSymbol& left, const ExpressionSymbol& right)
{
    return left.stackPrecedence >= right.inputPrecedence;
}
       
#endif // INFIX_SYMBOLS
