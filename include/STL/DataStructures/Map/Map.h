#ifndef _MAP_H_
#define _MAP_H_

#include "Pair.h"     // Pair class
#include "BSTree.h"   // BSTree class

// implements a map containing key/value pairs.
// a map does not contain multiple copies of the same item.
// types T and Key must have a default constructor
template <typename Key, typename T>
class Map
{
    public:
        // Map iterators are simply BSTree iterators. an iterator cannot
        // change the key in a tree node, since the key attribute
        // of a Pair object in the tree is const
        typedef BSTree<Pair<const Key,T>>::iterator iterator;
        typedef BSTree<Pair<const Key,T>>::const_iterator const_iterator;

        // for programmer convenience
        typedef Pair<const Key, T> value_type;

        // default constructor. create an empty map
        Map();

        // build a map whose key/value pairs are determined by pointer
        // values [first, last)
        Map(value_type *first, value_type *last);

        // is the map empty?
        bool empty() const;

        // return the number of elements in the map
        int size() const;

        // search for item in the map with the given key
        // and return an iterator pointing at it, or end()
        // if it is not found
        iterator find (const Key& key);

        // constant version of find()
        const_iterator find (const Key& key) const;

        // if no value is associated with key, create a new
        // map entry with the default value T() and return a
        // reference to the default value; otherwise,
        // return a reference to the value already associated
        // with the key
        T& operator[] (const Key& key);

        // returns 1 if an element with the key is in the map
        // and 0 otherwise
        int count(const Key& key) const;

        // if the map does not contain a key/value pair whose
        // key matches that of kvpair, insert a copy of kvpair
        // and return a Pair object whose first element is an
        // iterator positioned at the new key/value pair and whose second
        // element is true. if the map already contains a key/value
        // pair whose key matches that of kvpair, return a Pair
        // object whose first element is an iterator positioned at the
        // existing key/value pair and whose second element is false
        Pair<iterator,bool> insert(const value_type& kvpair);

        // erase the key/value pair with the specified key
        // from the map and return the number
        // of items erased (1 or 0)
        int erase(const Key& key);

        // erase the map key/value pair pointed by to pos
        void erase(iterator pos);

        // erase the key/value pairs in the range [first, last)
        void erase(iterator first, iterator last);

        // return an iterator pointing at the first member
        // in the map
        iterator begin();
        // constant version of begin()
        const_iterator begin() const;

        // return an iterator pointing just past the last
        // member in the map
        iterator end();
        // constant version of end()
        const_iterator end() const;

    private:
        // Map implemented using an BSTree of key-value pairs
        BSTree<Pair<const Key,T>> t;
};

template <typename Key, typename T>
Map<Key,T>::Map()
{}

template <typename Key, typename T>
Map<Key,T>::Map(value_type *first, value_type *last):
        t(first, last)
{}

template <typename Key, typename T>
bool Map<Key,T>::empty() const
{
    return t.empty();
}

template <typename Key, typename T>
int Map<Key,T>::size() const
{
    return t.size();
}

template <typename Key, typename T>
Map<Key,T>::iterator Map<Key,T>::find (const Key& key)
{
    // pass a Pair to BSTree find() that contains key as its
    // first member and T() as its second
    return t.find(value_type(key, T()));
}

template <typename Key, typename T>
Map<Key,T>::const_iterator Map<Key,T>::find (const Key& key) const
{
    // pass a Pair to BSTree find() that contains key as its
    // first member and T() as its second
    return t.find(value_type(key, T()));
}

template <typename Key, typename T>
T& Map<Key,T>::operator[] (const Key& key)
{
    // build a Pair object consisting of key
    // and the default value T()
    value_type tmp(key, T());
    // will point to a pair in the map
    iterator iter;

    // try to insert tmp into the map. the iterator
    // component of the pair returned by t.insert()
    // points at either the newly created key/value
    // pair or a pair already in the map. return a
    // reference to the value in the pair
    iter = t.insert(tmp).first;

    return (*iter).second;
}

template <typename Key, typename T>
int Map<Key,T>::count(const Key& key) const
{
    // pass a Pair to BSTree count() that contains key as its
    // first member and T() as its second
    return t.count(value_type(key, T()));
}

template <typename Key, typename T>
Pair<Map<Key,T>::iterator,bool>
Map<Key,T>::insert(const Map<Key,T>::value_type& kvpair)
{
    // t.insert() returns a pair<iterator,bool> object, not a
    // Pair<iterator,bool> object
    std::pair<iterator, bool> p = t.insert(kvpair);

    // build and return a Pair<iterator,bool> object
    return Pair<iterator, bool>(p.first, p.second);
}

template <typename Key, typename T>
int Map<Key,T>::erase(const Key& key)
{
    // pass a Pair to BSTree erase() that contains key as its
    // first member and T() as its second
    return t.erase(value_type(key, T()));
}

template <typename Key, typename T>
void Map<Key,T>::erase(iterator pos)
{
    t.erase(pos);
}

template <typename Key, typename T>
void Map<Key,T>::erase(iterator first, iterator last)
{
    t.erase(first, last);
}

template <typename Key, typename T>
Map<Key,T>::iterator Map<Key,T>::begin()
{
    return t.begin();
}

template <typename Key, typename T>
Map<Key,T>::iterator Map<Key,T>::end()
{
    return t.end();
}

template <typename Key, typename T>
Map<Key,T>::const_iterator Map<Key,T>::begin() const
{
    return t.begin();
}

template <typename Key, typename T>
Map<Key,T>::const_iterator Map<Key,T>::end() const
{
    return t.end();
}

#endif  // _MAP_H_
