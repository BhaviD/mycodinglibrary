SRC="test_hash_table.cpp"

includedir="-I../../include"
INC="$includedir/Hashing/HashFunctions"
INC="$INC $includedir/Hashing/Hash"
INC="$INC $includedir/Exception"

g++ -std=c++11 $SRC $INC
