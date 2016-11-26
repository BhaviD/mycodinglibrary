SRC="FindKth_LargestElement.cpp"
includedir="-I../../include"
INC="$includedir/Sorting/QuickSort"
INC="$INC $includedir/WriteContainer"
INC="$INC $includedir/Matrix"
INC="$INC $includedir/Exception"
INC="$INC $includedir/STL/DataStructures/LinkedList"
INC="$INC $includedir/STL/DataStructures/BinarySearchTree"

g++ -std=c++11 $SRC $INC
