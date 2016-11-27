SRC=test_combinations.cpp
includedir="-I../../../include"
INC="$includedir/DynamicProgramming/Combinations"
INC="$INC $includedir/Matrix"
INC="$INC $includedir/Exception"
INC="$INC $includedir/STL/DataStructures/LinkedList"
INC="$INC $includedir/STL/DataStructures/BinarySearchTree"
INC="$INC $includedir/STL/DataStructures/MBinarySearchTree"

g++ -g -std=c++11 $SRC $INC
