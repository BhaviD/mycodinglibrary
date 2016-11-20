SRC=test_red_black_tree.cpp

includedir="-I../../../../include"
INC="$includedir/STL/DataStructures/RBTree"
INC="$INC $includedir/Exception"
INC="$INC $includedir/Matrix"
INC="$INC $includedir/WriteContainer"
INC="$INC $includedir/STL/DataStructures/LinkedList"
INC="$INC $includedir/STL/DataStructures/BinarySearchTree"

g++ -std=c++11 -g $SRC $INC
