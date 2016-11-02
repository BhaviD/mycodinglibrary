SRC=scanningTrees.cpp

includedir="../../../../../include"
INC="-I$includedir/STL/DataStructures/BinaryTree"

g++ -std=c++11 $SRC $INC
