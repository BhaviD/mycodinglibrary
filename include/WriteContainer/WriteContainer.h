#ifndef _WRITE_CONTAINER_H_
#define _WRITE_CONTAINER_H_

#include <vector>

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

#endif
