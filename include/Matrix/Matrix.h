#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <vector>

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

        friend Matrix<T> operator+(const Matrix<T>& mat1, const Matrix<T>& mat2);
        friend Matrix<T> operator-(const Matrix<T>& mat1, const Matrix<T>& mat2);

    private:
        int nRows, nCols;

        // matrix is implemented as nRows vectors (rows),
        // each having nCols elements (columns)
        std::vector<std::vector<T>> mat;
};

#endif
