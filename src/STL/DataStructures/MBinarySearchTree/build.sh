SRC=test_multi_binary_search_tree.cpp

includedir="../../../../include"
INC="-I$includedir/STL/DataStructures/MBinarySearchTree"
INC="$INC -I$includedir/Exception"
INC="$INC -I$includedir/Matrix"

g++ -std=c++11 -g $SRC $INC
