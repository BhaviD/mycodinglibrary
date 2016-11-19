#ifndef _HASH_H_
#define _HASH_H_

#include <iostream>
#include <vector>
#include <list>
#include <utility>

#include "Exception.h"

template <typename T, typename HashFunc>
class Hash
{
    public:

        // Hash table iterator nested classes
#include "HashIterator.h"

        // constructor specifying the number of buckets in the hash table
        // and the hash function
        Hash(int nbuckets, const HashFunc& hfunc = HashFunc());
      
        // constructor with arguments including a pointer range
        // [first, last) of values to insert, the number of
        // buckets in the hash table, and the hash function
        Hash(T *first, T *last, int nbuckets, const HashFunc& hfunc = HashFunc());
      
        // is the hash table empty?
        bool empty() const;
        // return number of elements in the hash table
        int size() const;

        // return an iterator pointing at item if it is in the
        // table; otherwise, return end()
        iterator find(const T& item);
        // constant version
        const_iterator find(const T& item) const;

        // if item is not in the table, insert it and
        // return a pair whose iterator component points
        // at item and whose bool component is true. if item
        // is in the table, return a pair whose iterator
        // component points at the existing item and whose
        // bool component is false
        // Postcondition: the table size increases by 1 if item
        // is not in the table
        std::pair<iterator,bool> insert(const T& item);

        // if item is in the table, erase it and return 1;
        // otherwise, return 0
        // Postcondition: the table size decreases by 1 if
        // item is in the table
        int erase(const T& item);

        // erase the item pointed to by pos.
        // Precondition: the table is not empty and pos points
        // to an item in the table. if the table is empty, the
        // function throws the UnderflowError exception. if the
        // iterator is invalid, the function throws the
        // ReferenceError exception.
        // Postcondition: the tree size decreases by 1
        void erase(iterator pos);

        // erase all items in the range [first, last).
        // Precondition: the table is not empty. if the table
        // is empty, the function throws the UnderflowError
        // exception.
        // Postcondition: the size of the table decreases by
        // the number of elements in the range [first, last)
        void erase(iterator first, iterator last);

        // return an iterator positioned at the start of the
        // hash table
        iterator begin();

        // constant version
        const_iterator begin() const;

        // return an iterator positioned past the last element of the
        // hash table
        iterator end();

        // constant version
        const_iterator end() const;

    private:
        // number of buckets in the table
        int numBuckets;
        // the hash table is a vector of lists
        std::vector<std::list<T>> bucket;
        // hash function
        HashFunc hf;
        // number of elements in the hash table
        int hashtableSize;
};

// constructor. create an empty hash table
template <typename T, typename HashFunc>
Hash<T, HashFunc>::Hash(int nbuckets, const HashFunc& hfunc):
            numBuckets(nbuckets), bucket(nbuckets), hf(hfunc),
            hashtableSize(0)
{}

// constructor. initialize table from pointer range [first, last)
template <typename T, typename HashFunc>
Hash<T, HashFunc>::Hash(T *first, T *last, int nbuckets, const HashFunc& hfunc):
            numBuckets(nbuckets), bucket(nbuckets), hf(hfunc),
            hashtableSize(0)
{
    T *p = first;

    while (p != last)
    {
        insert(*p);
        p++;
    }
}

template <typename T, typename HashFunc>
bool Hash<T, HashFunc>::empty() const
{
    return hashtableSize == 0;
}

template <typename T, typename HashFunc>
int Hash<T, HashFunc>::size() const
{
    return hashtableSize;
}

template <typename T, typename HashFunc>
typename Hash<T, HashFunc>::iterator Hash<T, HashFunc>::find(const T& item)
{
    // hashIndex is the bucket number (index of the linked list)
    int hashIndex = int(hf(item) % numBuckets);
    // use alias for bucket[hashIndex] to avoid indexing
    std::list<T>& myBucket = bucket[hashIndex];
    // use to traverse the list bucket[hashIndex]
    typename std::list<T>::iterator bucketIter;
    // returned if we find item

    // traverse list and look for a match with item
    bucketIter = myBucket.begin();
    while(bucketIter != myBucket.end())
    {
      // if locate item, return an iterator positioned in
      // bucket hashIndex at location bucketIter
      if (*bucketIter == item)
         return iterator(this, hashIndex, bucketIter);

        bucketIter++;
    }

    // return iterator positioned at the end of the hash table
    return end();
}

template <typename T, typename HashFunc>
typename Hash<T, HashFunc>::const_iterator
Hash<T, HashFunc>::find(const T& item) const
{
   // hashIndex is the bucket number (index of the linked list)
   int hashIndex = int(hf(item) % numBuckets);
   // use alias for bucket[hashIndex] to avoid indexing
   const std::list<T>& myBucket = bucket[hashIndex];
   // use to traverse the list bucket[hashIndex]
   typename std::list<T>::const_iterator bucketIter;
   // returned if we find item

    // traverse list and look for a match with item
    bucketIter = myBucket.begin();
   while(bucketIter != myBucket.end())
    {
      // if locate item, return an iterator positioned in
      // bucket hashIndex at location bucketIter
      if (*bucketIter == item)
         return const_iterator(this, hashIndex, bucketIter);

        bucketIter++;
    }

   // return iterator positioned at the end of the hash table
   return end();
}

template <typename T, typename HashFunc>
std::pair<typename Hash<T, HashFunc>::iterator,bool>
Hash<T, HashFunc>::insert(const T& item)
{
   // hashIndex is the bucket number
   int hashIndex = int(hf(item) % numBuckets);
    // for convenience, make myBucket an alias for bucket[hashIndex]
   std::list<T>& myBucket = bucket[hashIndex];
   // use iterator to traverse the list myBucket
   typename std::list<T>::iterator bucketIter;
    // specifies whether or not we do an insert
    bool success;

    // traverse list until we arrive at the end of
    // the bucket or find a match with item
    bucketIter = myBucket.begin();
    while (bucketIter != myBucket.end())
        if (*bucketIter == item)
            break;
        else
            bucketIter++;

    if (bucketIter == myBucket.end())
    {
        // at the end of the list, so item is not
        // in the hash table. call list class insert()
        // and assign its return value to bucketIter
        bucketIter = myBucket.insert(bucketIter, item);
        success = true;
        // increment the hash table size 
        hashtableSize++;
    }
    else
        // item is in the hash table. duplicates not allowed.
        // no insertion
        success = false;

    // return a pair with iterator pointing at the new or
    // pre-existing item and success reflecting whether
    // an insert took place
   return std::pair<iterator, bool>
                (iterator(this, hashIndex, bucketIter), success);
}

template <typename T, typename HashFunc>
void Hash<T, HashFunc>::erase(iterator pos)
{
    if (hashtableSize == 0)
        throw UnderflowError("hash erase(pos): hash table empty");

    if (pos.currentBucket == -1)
        throw ReferenceError("hash erase(pos): invalid iterator");


    // go to the bucket (list object) and erase the list item
    // at pos.currentLoc 
   bucket[pos.currentBucket].erase(pos.currentLoc);
}

template <typename T, typename HashFunc>
void Hash<T, HashFunc>::erase(Hash<T, HashFunc>::iterator first,
                                      Hash<T, HashFunc>::iterator last)
{
    if (hashtableSize == 0)
        throw UnderflowError("hash erase(first,last): hash table empty");

    // call erase(pos) for each item in the range
    while (first != last)
        erase(first++);
}

template <typename T, typename HashFunc>
int Hash<T, HashFunc>::erase(const T& item)
{
    iterator iter;
    int numberErased = 1;
    
    iter = find(item);
    if (iter != end())
        erase(iter);
    else
        numberErased = 0;

    return numberErased;
}

template <typename T, typename HashFunc>
typename Hash<T, HashFunc>::iterator Hash<T, HashFunc>::begin()
{
    Hash<T, HashFunc>::iterator tmp;

    tmp.hashTable = this;
    tmp.currentBucket = -1;
    // start at index -1 + 1 = 0 and search for a non-empty list
    tmp.findNext();

    return tmp;
}

template <typename T, typename HashFunc>
typename Hash<T, HashFunc>::const_iterator Hash<T, HashFunc>::begin() const
{
    Hash<T, HashFunc>::const_iterator tmp;

    tmp.hashTable = this;
    tmp.currentBucket = -1;
    // start at index -1 + 1 = 0 and search for a non-empty list
    tmp.findNext();

    return tmp;
}

template <typename T, typename HashFunc>
typename Hash<T, HashFunc>::iterator Hash<T, HashFunc>::end()
{
    Hash<T, HashFunc>::iterator tmp;

    tmp.hashTable = this;
    // currentBucket of -1 means we are at end of the table
    tmp.currentBucket = -1;

    return tmp;
}

template <typename T, typename HashFunc>
typename Hash<T, HashFunc>::const_iterator Hash<T, HashFunc>::end() const
{
    Hash<T, HashFunc>::const_iterator tmp;

    tmp.hashTable = this;
    // currentBucket of -1 means we are at end of the table
    tmp.currentBucket = -1;

    return tmp;
}

#endif   // _HASH_H_
