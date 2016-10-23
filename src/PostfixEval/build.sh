SRC=test_postfix_eval.cpp

includedir="../../include"
INC="-I$includedir/PostfixEval"
INC="$INC -I$includedir/Exception"

g++ -std=c++11 $SRC $INC
