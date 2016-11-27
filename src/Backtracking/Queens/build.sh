SRC=test_n_queens.cpp
includedir="-I../../../include"
INC="$includedir/Backtracking/Queens"
INC="$INC $includedir/Matrix"
INC="$INC $includedir/Exception"
INC="$INC $includedir/STL/DataStructures/LinkedList"
INC="$INC $includedir/STL/DataStructures/BinarySearchTree"
INC="$INC $includedir/STL/DataStructures/MBinarySearchTree"

g++ -std=c++11 $SRC $INC
