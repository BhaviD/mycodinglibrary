#ifndef _USET_H_
#define _USET_H_

#include <utility>

#include "Hash.h"     // Hash class

// implements an unordered set
template <typename T, typename HashFunc>
class USet
{
    public:
        // USet iterators are simply hash iterators
        typedef typename Hash<T, HashFunc>::iterator iterator;
        typedef typename Hash<T, HashFunc>::const_iterator const_iterator;

        // default constructor
        USet(int tableSize = 1237, const HashFunc& hfunc = HashFunc());

        // build a set whose data are determined by pointer range
        // [first, last)
        USet(T *first, T *last, int tableSize = 1237,
              const HashFunc& hfunc = HashFunc());

        // is the set empty?
        bool empty() const;

        // return the number of elements in the set
        int size() const;

        // search for item in the set and return an iterator
        // pointing at it, or end() if it is not found
        iterator find (const T& item);
        // constant version
        const_iterator find (const T& item) const;

        // if item is not in the set, insert it and return a pair
        // whose first element is an iterator pointing to the
        // new element and whose second element is true.
        // otherwise, return a pair whose first element is an
        // iterator pointing at the existing element and whose
        // second element is false
        // Postcondition: the set size increases by 1 if item is
        // not in the set
        std::pair<iterator,bool> insert(const T& item);

        // if item is in the set, erase it and return 1;
        // otherwise, return 0
        // Postcondition: the set size decreases by 1 if item is
        // in the set
        int erase(const T& item);

        // erase the item pointed to by pos.
        // Precondition: the set is not empty. if the set is empty,
        // the function throws the UnderflowError exception.
        // Postcondition: the set size decreases by 1
        void erase(iterator pos);

        // erase the elements in the range [first, last)
        // Precondition: the set is not empty. if the set is empty,
        // the function throws the UnderflowError exception.
        // Postcondition: the tree size decreases by the number
        // elements in the range
        void erase(iterator first, iterator last);

        // return an iterator pointing at the first member
        // in the set
        iterator begin();

        // constant version of begin()
        const_iterator begin() const;

        // return an iterator pointing just past the last
        // member in the set
        iterator end();

        // constant version of end()
        const_iterator end() const;

    private:
        // USet implemented using a hash table
        Hash<T, HashFunc> t;
};

// default constructor. initialize hash table
template <typename T, typename HashFunc>
USet<T, HashFunc>::USet(int tableSize, const HashFunc& hfunc):
        t(tableSize, hfunc)
{}

template <typename T, typename HashFunc>
USet<T, HashFunc>::USet(T *first, T *last, int tableSize,
                              const HashFunc& hfunc):
        t(first, last, tableSize, hfunc)
{}

template <typename T, typename HashFunc>
bool USet<T, HashFunc>::empty() const
{
    return t.empty();
}

template <typename T, typename HashFunc>
int USet<T, HashFunc>::size() const
{
    return t.size();
}

template <typename T, typename HashFunc>
USet<T, HashFunc>::iterator USet<T, HashFunc>::find (const T& item)
{
    return t.find(item);
}

template <typename T, typename HashFunc>
USet<T, HashFunc>::const_iterator USet<T, HashFunc>::find (const T& item) const
{
    return t.find(item);
}

template <typename T, typename HashFunc>
std::pair<USet<T, HashFunc>::iterator,bool> USet<T, HashFunc>::insert(const T& item)
{
    return t.insert(item);
}

template <typename T, typename HashFunc>
int USet<T, HashFunc>::erase(const T& item)
{
    return t.erase(item);
}

template <typename T, typename HashFunc>
void USet<T, HashFunc>::erase(iterator pos)
{
    if (t.size() == 0)
        throw UnderflowError("USet erase(): set is empty");

    t.erase(pos);
}

template <typename T, typename HashFunc>
void USet<T, HashFunc>::erase(iterator first, iterator last)
{
    if (t.size() == 0)
        throw UnderflowError("USet erase(): set is empty");

    t.erase(first, last);
}

template <typename T, typename HashFunc>
USet<T, HashFunc>::iterator USet<T, HashFunc>::begin()
{
    return t.begin();
}

template <typename T, typename HashFunc>
USet<T, HashFunc>::const_iterator USet<T, HashFunc>::begin() const
{
    return t.begin();
}

template <typename T, typename HashFunc>
USet<T, HashFunc>::iterator USet<T, HashFunc>::end()
{
    return t.end();
}

template <typename T, typename HashFunc>
USet<T, HashFunc>::const_iterator USet<T, HashFunc>::end() const
{
    return t.end();
}

// SET FUNCTIONS

// determine if sets lhs and rhs have the same size and
// are equal element by element
template <typename T, typename HashFunc>
bool operator== (const USet<T, HashFunc>& lhs, const USet<T, HashFunc>& rhs);

// return a set containing all elements that are in lhs or rhs
template <typename T, typename HashFunc>
USet<T, HashFunc> operator+ (const USet<T, HashFunc>& lhs, const USet<T, HashFunc>& rhs);

// return a set containing all elements that are in goth lhs and rhs
template <typename T, typename HashFunc>
USet<T, HashFunc> operator* (const USet<T, HashFunc>& lhs, const USet<T, HashFunc>& rhs);

// return a set containing all elements that are in lhs but not in rhs
template <typename T, typename HashFunc>
USet<T, HashFunc> operator- (const USet<T, HashFunc>& lhs, const USet<T, HashFunc>& rhs);


// SET FUNCTION IMPLEMENTATIONS

template <typename T, typename HashFunc>
bool operator== (const USet<T, HashFunc>& lhs, const USet<T, HashFunc>& rhs)
{
    USet<T, HashFunc>::const_iterator myself = lhs.begin(), other = rhs.begin();

    // return false if the sets do not have the same size
    if (lhs.size() == rhs.size())
    {
        // compare until encounter end of the sets or
        // find two elements that are not equal
        while (myself != lhs.end() && *myself++ == *other++);

        // if we left the loop before reaching the end
        // of the sets, they are not equal
        if (myself != lhs.end())
            return false;
        else
            return true;
    }
    else
        return false;
}

template <typename T, typename HashFunc>
USet<T, HashFunc> operator+ (const USet<T, HashFunc>& lhs, const USet<T, HashFunc>& rhs)
{
    // construct union. initially, copy in all elements of lhs
    USet<T, HashFunc> setUnion = lhs;
    // iterators that traverse the sets
    USet<T, HashFunc>::const_iterator rhsIter = rhs.begin();

    // insert all values from rhs into the union. duplicate
    // values will be discarded
    while (rhsIter != rhs.end())
    {
        setUnion.insert(*rhsIter);
        rhsIter++;
    }

    return setUnion;
}

template <typename T, typename HashFunc>
USet<T, HashFunc> operator* (const USet<T, HashFunc>& lhs, const USet<T, HashFunc>& rhs)
{
    // construct intersection
    USet<T, HashFunc> setIntersection;
    // iterators that traverse the sets
    USet<T, HashFunc>::const_iterator lhsIter = lhs.begin();

    while (lhsIter != lhs.end())
    {
        // insert *lhsIter into the intersection if it is
        // in rhs
        if (rhs.find(*lhsIter) != rhs.end())
            setIntersection.insert(*lhsIter);
        lhsIter++;
    }

    return setIntersection;
}

template <typename T, typename HashFunc>
USet<T, HashFunc> operator- (const USet<T, HashFunc>& lhs, const USet<T, HashFunc>& rhs)
{
    // construct difference
    USet<T, HashFunc> setDifference;
    // iterators that traverse the sets
    USet<T, HashFunc>::const_iterator lhsIter = lhs.begin(),
                                                rhsIter = rhs.begin();

    while (lhsIter != lhs.end())
    {
        // insert *lhsIter into the difference if it
        // is not in rhs
        if (rhs.find(*lhsIter) == rhs.end())
            setDifference.insert(*lhsIter);
        lhsIter++;
    }

    return setDifference;
}

#endif  // _USET_H_
