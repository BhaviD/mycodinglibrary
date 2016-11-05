SRC=record_keeping_in_video_store.cpp

includedir="../../../../include"
INC="-I$includedir/STL/DataStructures/BinarySearchTree"
INC="$INC -I$includedir/STL/DataStructures/LinkedList"
INC="$INC -I$includedir/WriteContainer"
INC="$INC -I$includedir/Exception"
INC="$INC -I$includedir/Matrix"

g++ -std=c++11 $SRC $INC
