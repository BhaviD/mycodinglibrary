#ifndef _PAIR_H_
#define _PAIR_H_

// substitute for the STL pair class. used 
// by the Map class
template<typename T1, typename T2>
class Pair
{
    public:
        // public data members
        T1 first;
        T2 second;

        // default constructor
        Pair(): first(T1()), second(T2())
        {}

        // constructor that initializes first and second
        Pair(const T1& v1, const T2& v2):
                first(v1), second(v2)
        {}

        // overload < by comparing the first data members
        friend bool operator< (const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs)
        {
            return lhs.first < rhs.first;
        }

        // overload == by comparing the first data members
        friend bool operator== (const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs)
        {
            return lhs.first == rhs.first;
        }
};

#endif  // _PAIR_H_
