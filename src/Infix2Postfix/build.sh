SRC=test_infix_exp_evaluation.cpp

includedir="../../include"
INC="-I$includedir/PostfixEval"
INC="$INC -I$includedir/Infix2Postfix"
INC="$INC -I$includedir/Infix2Postfix/ExpressionSymbol"
INC="$INC -I$includedir/Exception"

g++ -std=c++11 $SRC $INC
