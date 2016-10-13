export SRC="test_insertion_sort.cpp"
export SRC="$SRC ../../RandomNumber/RandomNumber.cpp"

export INC=-I../../../include/Sorting/InsertionSort/
export INC="$INC -I../../../include/RandomNumber/"
export INC="$INC -I../../../include/WriteContainer/"

g++ -std=c++11 $SRC $INC
