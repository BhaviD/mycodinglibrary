SRC=$1

includedir="-I../../../../include"
INC="$includedir/STL/DataStructures/Graph"
INC="$INC $includedir/WriteContainer"
INC="$INC $includedir/Exception"
INC="$INC $includedir/Matrix"
INC="$INC $includedir/STL/DataStructures/LinkedList"
INC="$INC $includedir/STL/DataStructures/BinarySearchTree"
INC="$INC $includedir/STL/DataStructures/MBinarySearchTree"
INC="$INC $includedir/STL/DataStructures/PQueue"
INC="$INC $includedir/STL/DataStructures/Heap"

g++ -std=c++11 $SRC $INC
