#ifndef _MSET_H_
#define _MSET_H_

#include <utility>
#include "MBSTree.h"    // MBSTree class

// implements a set which contains duplicate data values
template <typename T>
class MSet
{
    public:
        // MSet iterators are simply MBSTree iterators
        typedef typename MBSTree<T>::iterator iterator;
        typedef typename MBSTree<T>::const_iterator const_iterator;

        // default constructor
        MSet();

        // build a multiset whose data are determined by pointer range
        // [first, last)
        MSet(T *first, T *last);

        // is the multiset empty?
        bool empty() const;

        // return the number of elements in the multiset
        int size() const;

        // return the number of duplicate occurrences of item
        // in the multiset
        int count(const T& item) const;

        // search for item in the multiset and return an iterator
        // pointing at the first occurrence matching item or end() 
        // if it is not found
        iterator find (const T& item);

        // constant version
        const_iterator find (const T& item) const;

        // return a pair of iterators such that all occurrences
        // of item are in the iterator range 
        // [first member of pair, second member of pair)
        std::pair<iterator, iterator> equal_range(const T& item);

        //constant version
        std::pair<const_iterator, const_iterator> equal_range(const T& item) const;

        // insert item into the multiset and return an
        // iterator pointing at the new element.
        // PostCondition: the element item is added to the multiset
        iterator insert(const T& item);
        
        // erase all occurrences of item from the multiset
        // and return the number of items erased.
        // Postcondition: the multiset size decreases by the number of occurrences 
        // of item in the multiset
        int erase(const T& item);

        // erase the item pointed to by pos.
        // Preconditions: the multiset is not empty and pos points
        // to an item in the multiset. if the multiset is empty, the
        // function throws the UnderflowError exception. if the
        // iterator is invalid, the function throws the ReferenceError
        // exception.
        // Postcondition: the multiset size decreases by 1
        void erase(iterator pos);

        // erase the elements in the range [first, last)
        // Precondition: the multiset is not empty. if the multiset is empty,
        // the function throws the UnderflowError exception.
        // Postcondition: the multiset size decreases by the number
        // elements in the range
        void erase(iterator first, iterator last);

        // return an iterator pointing at the first member
        // in the multiset
        iterator begin();

        // constant version of begin()
        const_iterator begin() const;

        // return an iterator pointing just past the last
        // member in the multiset
        iterator end();

        // constant version of end()
        const_iterator end() const;

    private:
        // multiset implemented using a multi binary search tree
        MBSTree<T> t;
};

// CONSTRUCTORS

template <typename T>
MSet<T>::MSet()
{}

template <typename T>
MSet<T>::MSet(T *first, T *last): t(first, last)
{}

template <typename T>
bool MSet<T>::empty() const
{
    return t.empty();
}

template <typename T>
int MSet<T>::size() const
{
    return t.size();
}

template <typename T>
int MSet<T>::count(const T& item) const
{
    return t.count(item);   
}

std::pair<MSet<T>::iterator,
          MSet<T>::iterator> 
MSet<T>::equal_range(const T& item)
{
    return t.equal_range(item);
}

std::pair<MSet<T>::const_iterator,
          MSet<T>::const_iterator> 
MSet<T>::equal_range(const T& item) const
{
    return t.equal_range(item);
}

template <typename T>
MSet<T>::iterator MSet<T>::find (const T& item)
{
    // return MBSTree iterator which is a MSet iterator
    return t.find(item);
}

template <typename T>
MSet<T>::const_iterator MSet<T>::find (const T& item) const
{
    // return MBSTree iterator which is a MSet iterator
    return t.find(item);
}

template <typename T>
MSet<T>::iterator MSet<T>::insert(const T& item)
{
    return t.insert(item);
}

template <typename T>
int MSet<T>::erase(const T& item)
{
    return t.erase(item);
}

template <typename T>
void MSet<T>::erase(iterator pos)
{
    if (t.size() == 0)
        throw UnderflowError("MSet erase(): set is empty");

    if (pos == end())
        throw ReferenceError("MSet erase(): invalid iterator");

    t.erase(pos);
}

template <typename T>
void MSet<T>::erase(iterator first, iterator last)
{
    if (t.size() == 0)
        throw UnderflowError("MSet erase(): set is empty");

    t.erase(first, last);
}

template <typename T>
MSet<T>::iterator MSet<T>::begin()
{
    // a MSet iterator is an MBSTree iterator
    return t.begin();
}

template <typename T>
MSet<T>::const_iterator MSet<T>::begin() const
{
    return t.begin();
}

template <typename T>
MSet<T>::iterator MSet<T>::end()
{
    return t.end();
}

template <typename T>
MSet<T>::const_iterator MSet<T>::end() const
{
    return t.end();
}

// determine if sets lhs and rhs have the same size and
// are equal element by element
template <typename T>
bool operator== (const MSet<T>& lhs, const MSet<T>& rhs);

// return a MSet object containing all elements that
// are in lhs or rhs
template <typename T>
MSet<T> operator+ (const MSet<T>& lhs, const MSet<T>& rhs);

// return a MSet object containing all elements that
// are in goth lhs and rhs
template <typename T>
MSet<T> operator* (const MSet<T>& lhs, const MSet<T>& rhs);

// return a MSet object containing all elements that
// are in lhs but not in rhs
template <typename T>
MSet<T> operator- (const MSet<T>& lhs, const MSet<T>& rhs);


// SET FUNCTION IMPLEMENTATIONS

template <typename T>
bool operator== (const MSet<T>& lhs, const MSet<T>& rhs)
{
    MSet<T>::const_iterator myself = lhs.begin(), other = rhs.begin();

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

template <typename T>
MSet<T> operator+ (const MSet<T>& lhs, const MSet<T>& rhs)
{
    // constuct union
    MSet<T> setUnion;
    // iterators that traverse the sets
    MSet<T>::const_iterator lhsIter = lhs.begin(), rhsIter = rhs.begin();

    // move forward as long as we have not reached the end of
    // either set
    while (lhsIter != lhs.end() && rhsIter != rhs.end())
    {
        if (*lhsIter < *rhsIter)
        {
            // *lhsIter belongs to the union. insert and
            // move iterator forward
            setUnion.insert(*lhsIter);
            ++lhsIter;
        }
        else if (*rhsIter < *lhsIter)
        {
            // *rhsIter belongs to the union. insert and
            // move iterator forward
            setUnion.insert(*rhsIter++);
            ++rhsIter;
        }
        else
        {
            // the two values are equal. insert just one and
            // move both itertors forward
            setUnion.insert(*lhsIter);
            ++lhsIter;
            ++rhsIter;
        }
    }
    
    // flush any remaining items
    if (lhsIter != lhs.end())
    {
        while (lhsIter != lhs.end())
        {
            setUnion.insert(*lhsIter);
            ++lhsIter;
        }
    }
    else if (rhsIter != rhs.end())
    {
        while (rhsIter != rhs.end())
        {
            setUnion.insert(*rhsIter);
            ++rhsIter;
        }
    }

    return setUnion;
}

template <typename T>
MSet<T> operator* (const MSet<T>& lhs, const MSet<T>& rhs)
{
    // constuct intersection
    MSet<T> setIntersection;
    // iterators that traverse the sets
    MSet<T>::const_iterator lhsIter = lhs.begin(), rhsIter = rhs.begin();

    // move forward as long as we have not reached the end of
    // either set
    while (lhsIter != lhs.end() && rhsIter != rhs.end())
    {
        if (*lhsIter < *rhsIter)
            // *lhsIter is in lhs and not in rhs. move iterator
            // forward
            ++lhsIter;
        else if (*rhsIter < *lhsIter)
            // *rhsIter is in rhs and not in lhs. move iterator
            // forward
            ++rhsIter;
        else
        {
            // the same value is in both sets. insert one value
            // and move the iterators forward
            setIntersection.insert(*lhsIter);
            ++lhsIter;
            ++rhsIter;
        }
    
        return setIntersection;
    }
}

template <typename T>
MSet<T> operator- (const MSet<T>& lhs, const MSet<T>& rhs)
{
    // construct difference
    MSet<T> setDifference;
    // iterators that traverse the sets
    MSet<T>::const_iterator lhsIter = lhs.begin(), rhsIter = rhs.begin();

    // move forward as long as we have not reached the end of
    // either set
    while (lhsIter != lhs.end() && rhsIter != rhs.end())
    {
        if (*lhsIter < *rhsIter)
        {
            // *lhsIter belongs to lhs but not to rhs. put it in
            // the difference
            setDifference.insert(*lhsIter);
            ++lhsIter;
        }
        else if (*rhsIter < *lhsIter)
        {
            // *rhsIter is in the rhs but not in the lhs. pass
            // over it
            ++rhsIter;
        }
        else
        {
            // the same value is in both sets. move the
            // iterators forward
            ++lhsIter;
            ++rhsIter;
        }
    }
    
    // flush any remaining items from lhs
    if (lhsIter != lhs.end())
    {
        while (lhsIter != lhs.end())
        {
            setDifference.insert(*lhsIter);
            ++lhsIter;
        }
    }

    return setDifference;
}

#endif  // _MSET_H_
