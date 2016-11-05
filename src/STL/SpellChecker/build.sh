SRC="simpleSpellChecker.cpp"

includedir="../../../include"
INC="-I$includedir/WriteContainer"
INC="$INC -I$includedir/Matrix"
INC="$INC -I$includedir/Exception"
INC="$INC -I$includedir/STL/DataStructures/LinkedList"
INC="$INC -I$includedir/STL/DataStructures/BinarySearchTree"

g++ -std=c++11 $SRC $INC
