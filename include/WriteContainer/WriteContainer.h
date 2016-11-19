#ifndef _WRITE_CONTAINER_H_
#define _WRITE_CONTAINER_H_

#include <vector>
#include <map>
#include <list>
#include "Matrix.h"
#include "Node.h"
#include "DNode.h"
#include "BSTree.h"

// template function to output an n element array of type T
template <typename T>
void WriteArray(const T arr[], int n);

// output the elements of v
template <typename T>
void WriteVector(const std::vector<T>& v);

template <typename T>
void WriteMatrix(const Matrix<T>& mat);

template <typename T>
void WriteList(const std::list<T>& alist, const std::string& separator = " ");

// output a singly linked list with each element followed by separator
template <typename T>
void WriteLinkedList(Node<T> *front, const std::string& separator = " ");

// output a doubly linked list with each element followed by separator
template <typename T>
void WriteDLinkedList(DNode<T> *header, const std::string& separator = " ");

// display the search tree. follow the output of each list element
// by separator. default value of separator = "  "
template <typename T>
void WriteBSTree(const BSTree<T>& t, const std::string& separator = " ");

// display the elements of a container in the iterator
// range [first, last). output separator between items.
// default value of separator = "  "
template <typename Iterator>
void WriteContainer(Iterator first, Iterator last, const std::string& separator = "  ");

template <typename Key, typename T>
void WriteMap(const std::map<Key, T>& m, const std::string& separator = " ");

template <typename T>
void WriteArray(const T arr[], int n)
{
    int i;
    for(i = 0; i < n; ++i)
        std::cout << arr[i] << "  ";
    std::cout << std::endl;
}

template <typename T>
void WriteVector(const std::vector<T>& v)
{
    // capture the size of the vector in n
    int i, n = v.size();

    for(i = 0; i < n; ++i)
        std::cout << v[i] << "  ";
    std::cout << std::endl;
}

template <typename T>
void WriteMatrix(const Matrix<T>& mat)
{
    int rows = mat.rows();
    int cols = mat.cols();
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
            std::cout << mat[i][j] << " ";
        std::cout << std::endl;
    }
}

template <typename T>
void WriteList(const std::list<T>& alist, const std::string& separator)
{
    //typename std::list<T>::const_iterator iter;
    auto iter = alist.begin();

    for(iter = alist.begin(); iter != alist.end(); ++iter)
        std::cout << *iter << separator;
    std::cout << std::endl;
}

// output a singly linked list with each element followed by separator
template <typename T>
void WriteLinkedList(Node<T> *front, const std::string& separator)
{
   // front points at first Node.  curr moves through the list
   Node<T> *curr;

   curr = front;           // set curr to front of the list
   while (curr)    // continue until and of list
   {
      // output Node value and move to the next Node
      std::cout << curr->nodeValue << separator;
      curr = curr->next;
   }
}

// output a doubly linked list with each element followed by separator
template <typename T>
void WriteDLinkedList(DNode<T> *header, const std::string& separator)
{
   // header points at first DNode.  p moves through the list
   DNode<T> *p = header->next ;

   while (p != header)    // continue until end of list
   {
      // output DNode value and move to the next DNode
      std::cout << p->nodeValue << separator;
      p = p->next;
   }
}

template <typename T>
void WriteBSTree(const BSTree<T>& t, const std::string& separator)
{
    typename BSTree<T>::const_iterator iter = t.begin();

    while (iter != t.end())
    {
        std::cout << *iter << separator;
        ++iter;
    }
}

template <typename Iterator>
void WriteContainer(Iterator first, Iterator last,
                    const std::string& separator)
{
    // declare iterator of type Iterator and initialize it
    // to have value first
    Iterator iter = first;

    while (iter != last)
    {
        std::cout << *iter << separator;
        iter++;
    }
}

template <typename Key, typename T>
void WriteMap(const std::map<Key, T>& m, const std::string& separator)
{
    typename std::map<Key, T>::const_iterator iter = m.begin();
    while(iter != m.end())
    {
        std::cout << (*iter).first << " " << (*iter).second << separator;
        ++iter;
    }
}

#endif
