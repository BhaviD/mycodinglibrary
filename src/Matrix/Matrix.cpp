#include "Matrix/Matrix.h"
#include "Exception/Exception.h"

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
