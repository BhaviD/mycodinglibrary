SRC=singly-linked-list-operations.cpp

includedir="-I../../../../include"
INC="$includedir/STL/DataStructures/LinkedList"

g++ -std=c++11 $SRC $INC
