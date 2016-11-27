SRC=test_fib_nos.cpp
includedir="-I../../../include"
INC="$includedir/DynamicProgramming/FibonacciNumbers"

g++ -g -std=c++11 $SRC $INC
