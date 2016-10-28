#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <vector>
#include "Exception/Exception.h"

template <typename T>
class Matrix
{
    public:
        // constructor.
        // Postcondition: create array having numRows x numCols elements
        // all of whose elements have value initVal
        Matrix(int numRows = 1, int numCols = 1, const T& initVal = T());

        // index operator.
        // Precondition: 0 <= i < nRows. a violation of this
        // precondition throws the indexRangeError exception.
        // Postcondition: if the operator is used on the left-hand
        // side of an assignment statement, an element of row i 
        // is changed
        std::vector<T>& operator[] (int i);

        // version for constant objects
        const std::vector<T>& operator[](int i) const;

        // return number of rows
        int rows() const;
        // return number of columns
        int cols() const;

        // modify the matrix size.
        // Postcondition: the matrix has size numRows x numCols.
        // any new elements are filled with the default value of type T
        void resize(int numRows, int numCols);

        template <typename U>
        friend Matrix<U> operator+(const Matrix<U>& mat1, const Matrix<U>& mat2);

        template <typename U>
        friend Matrix<U> operator-(const Matrix<U>& mat1, const Matrix<U>& mat2);

    private:
        int nRows, nCols;

        // matrix is implemented as nRows vectors (rows),
        // each having nCols elements (columns)
        std::vector<std::vector<T>> mat;
};

template <typename T>
Matrix<T>::Matrix(int numRows, int numCols, const T& initVal):
                  nRows(numRows), nCols(numCols),
                  mat(numRows, std::vector<T>(numCols,initVal))
{}

// non-constant version. provides general access to matrix
// elements
template <typename T>
std::vector<T>& Matrix<T>::operator[] (int i)
{
    if (i < 0 || i >= nRows)
        throw IndexRangeError(
            "Matrix: invalid row index", i, nRows);

   return mat[i];
}

// constant version.  can be used with a constant object.
// does not allow modification of a matrix element
template <typename T>
const std::vector<T>& Matrix<T>::operator[] (int i) const
{
    if (i < 0 || i >= nRows)
        throw IndexRangeError(
            "Matrix: invalid row index", i, nRows);

   return mat[i];
}

template <typename T>
int Matrix<T>::rows() const
{
   return nRows;
}

template <typename T>
int Matrix<T>::cols() const
{
   return nCols;
}

template <typename T>
void Matrix<T>::resize(int numRows, int numCols)
{
   int i;
  
   // handle case of no size change with a return
   if (numRows == nRows && numCols == nCols)
      return;

    // assign the new matrix size
    nRows = numRows;
    nCols = numCols;

    // resize to nRows rows
    mat.resize(nRows);

    // resize each row to have nCols columns
    for (i = 0; i < nRows; ++i)
        mat[i].resize(nCols);
}

template <typename T>
Matrix<T> operator+(const Matrix<T>& left, const Matrix<T>& right)
{
    if(left.nRows != right.nRows ||
       left.nCols != right.nCols)
    {
        // throw exception.
    }
    
    int rows = left.nRows;
    int cols = left.nCols;
    Matrix<T> result(rows, cols);
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            result[i][j] = left[i][j] + right[i][j];
        }
    }
    return result;
}

template <typename T>
Matrix<T> operator-(const Matrix<T>& left, const Matrix<T>& right)
{
    if(left.nRows != right.nRows ||
       left.nCols != right.nCols)
    {
        // throw exception.
    }
    
    int rows = left.nRows;
    int cols = left.nCols;
    Matrix<T> result(rows, cols);
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            result[i][j] = left[i][j] - right[i][j];
        }
    }
    return result;
}

#endif
