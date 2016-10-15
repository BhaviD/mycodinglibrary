SRC="test_insertion_sort.cpp"
SRC="$SRC ../../RandomNumber/RandomNumber.cpp"

INC="-I../../../include/Sorting/InsertionSort/"
INC="$INC -I../../../include/RandomNumber/"
INC="$INC -I../../../include/WriteContainer/"

g++ -std=c++11 $SRC $INC
