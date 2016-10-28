SRC=test_radix_sort.cpp

INC="-I../../../include"
#INC="-I$includedir/Sorting/BubbleSort/"
#INC="$INC -I$includedir/Sorting/SelectionSort/"
#INC="$INC -I$includedir/Sorting/Radix/"
#INC="$INC -I$includedir/Timer/"

g++ -std=c++11 $SRC $INC
