SRC=test_multibase_output.cpp
includedir="../../../../../include"
INC="-I$includedir/STL/DataStructures/Stack/MultibaseOutput"

g++ -std=c++11 $SRC $INC
