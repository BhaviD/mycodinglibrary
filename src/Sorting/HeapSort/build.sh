SRC="test_heap_sort.cpp"
includedir="-I../../../include"
INC="$includedir/Sorting/HeapSort"
INC="$INC $includedir/RandomNumber"
INC="$INC $includedir/WriteContainer"
INC="$INC $includedir/Matrix"
INC="$INC $includedir/Exception"
INC="$INC $includedir/STL/DataStructures/LinkedList"
INC="$INC $includedir/STL/DataStructures/BinarySearchTree"
INC="$INC $includedir/STL/DataStructures/Heap"

g++ -std=c++11 $SRC $INC
