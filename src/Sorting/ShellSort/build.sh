SRC=test_shell_sort.cpp

includedir="../../../include"
INC="-I$includedir/Sorting/BubbleSort"
INC="$INC -I$includedir/Sorting/SelectionSort"
INC="$INC -I$includedir/Sorting/ShellSort"
INC="$INC -I$includedir/Timer"
INC="$INC -I$includedir/WriteContainer"

g++ -std=c++11 $SRC $INC
