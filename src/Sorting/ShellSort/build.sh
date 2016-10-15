export SRC=test_shell_sort.cpp

export includedir="../../../include"
export INC="-I$includedir/Sorting/BubbleSort"
export INC="$INC -I$includedir/Sorting/SelectionSort"
export INC="$INC -I$includedir/Sorting/ShellSort"
export INC="$INC -I$includedir/Timer"
export INC="$INC -I$includedir/WriteContainer"

g++ -std=c++11 $SRC $INC
