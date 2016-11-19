SRC="test_insertion_sort.cpp"
includedir="../../../include"
INC="-I$includedir/Sorting/InsertionSort"
INC="$INC -I$includedir/RandomNumber"
INC="$INC -I$includedir/WriteContainer"
INC="$INC -I$includedir/Matrix"
INC="$INC -I$includedir/Exception"
INC="$INC -I$includedir/STL/DataStructures/LinkedList"
INC="$INC -I$includedir/STL/DataStructures/BinarySearchTree"

g++ -std=c++11 $SRC $INC
