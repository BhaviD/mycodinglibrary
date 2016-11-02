SRC=josephusProblem.cpp

includedir="../../../../../include"
INC="-I$includedir/STL/DataStructures/LinkedList"
INC="$INC -I$includedir/RandomNumber"

g++ -std=c++11 $SRC $INC
