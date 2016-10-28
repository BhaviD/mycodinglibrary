#ifndef _WRITE_CONTAINER_H_
#define _WRITE_CONTAINER_H_

#include <vector>
#include <list>
#include "Matrix/Matrix.h"

// template function to output an n element array of type T
template <typename T>
void WriteArray(const T arr[], int n);

// output the elements of v
template <typename T>
void WriteVector(const std::vector<T>& v);

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
void WriteList(const std::list<T>& alist, const std::string& separator = " ")
{
    //typename std::list<T>::const_iterator iter;
    auto iter = alist.begin();

    for(iter = alist.begin(); iter != alist.end(); ++iter)
        std::cout << *iter << separator;
    std::cout << std::endl;
}

#endif
