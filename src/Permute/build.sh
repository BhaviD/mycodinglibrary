SRC="test_permute.cpp"
includedir="-I../../include"
INC="$includedir/Permute"
INC="$INC $includedir/WriteContainer"
INC="$INC $includedir/Matrix"
INC="$INC $includedir/Exception"
INC="$INC $includedir/STL/DataStructures/LinkedList"
INC="$INC $includedir/STL/DataStructures/BinarySearchTree"
#INC="$INC $includedir/STL/DataStructures/Heap"

g++ -std=c++11 $SRC $INC
