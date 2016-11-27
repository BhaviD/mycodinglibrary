#ifndef _N_QUEENS_H_
#define _N_QUEENS_H_

#include <iostream>
#include <vector>

#include "Matrix.h"

// can a queen at (row, col) be attacked by any of the
// non-attacking queens in columns 0 to col-1 ?
bool SafeLocation(int row, int col, const std::vector<int>& queenList);

// place a queen in columns col through 7
bool PlaceQueens(std::vector<int>& queenList, int col);

// try to find a solution to the n-Queens problem starting
// with a queen at (row, 0)
bool Queens(std::vector<int>& queenList, int row);

bool SafeLocation(int row, int col, const std::vector<int>& queenList)
{
    int qRow;
    
    for (int qCol = 0; qCol < col; ++qCol)  // check previous columns only
    {
        qRow = queenList[qCol];
        if (qRow == row)                // same row
            return false;
        //else if (qCol == col)       // same col
            //return false;
        // can they attack on a diagonal?
        else if(qCol - qRow == col - row || qCol + qRow == col + row)
            return false;
    }
    return true;
}

bool PlaceQueens(std::vector<int>& queenList, int col)
{
    int row, n = queenList.size();
    bool foundLocation;

    if (col == n)   // stopping condition
        foundLocation = true;
    else
    {
        foundLocation = false; // start with row 0
        row = 0;
        while (row < n && !foundLocation)
        {
            // check whether cell (row, col) is safe; if so,
            // assign row to queenList and call PlaceQueens()
            // for next column; otherwise, go to the next row
            if (SafeLocation(row, col, queenList) == true)
            {
                // found good location
                queenList[col] = row;

                // recursive step. try to place queens in columns col + 1
                // through 7
                foundLocation = PlaceQueens(queenList,col+1);
                //if (!foundLocation)
                    // use next row since current one does not lead
                    // to a solution
                    //row++;
            }
            //else
                // current row fails. go to the next row
            row++;

        }   // end while
    }

    // pass success or failure back to previous col
    return foundLocation;
}

bool Queens(std::vector<int>& queenList, int row)
{
    // place first queen at (row,0)
    queenList[0] = row;

    // locate remaining queens in columns 1 through 7
    if (PlaceQueens(queenList, 1))
        return true;
    else
        return false;
}

class ChessBoard
{
    public:
        // default constructor      
        ChessBoard(int n = 8);

        // set queens on board at cells (queenList[col], col)
        // 0 <= col < 8
        void SetQueens(const std::vector<int>& queenList);

        // clear the board
        void ClearBoard();

        // draw the board using symbols 'Q' or '-'
        void DrawBoard() const; 
    private:
        // simulates chess board
        int size;
        Matrix<bool> board;
};

// constructor. initialize board to blanks
ChessBoard::ChessBoard(int n): size(n), board(n, n)
{
    ClearBoard();
}

// assign queens at locations (queenList[col],col),
// 0 <= col < 8
void ChessBoard::SetQueens(const std::vector<int>& queenList)
{
    ClearBoard();

    for (int col = 0; col < size; ++col)
        board[queenList[col]][col] = true;
}

void ChessBoard::ClearBoard()
{
    for(int i = 0; i < size; ++i)
        for(int j = 0; j < size; ++j)
            board[i][j] = false;
}

// draw the chess board
void ChessBoard::DrawBoard() const
{
    int i,j;

    std::cout << "  ";
    for (i = 0; i < size; i++)
        std::cout << " " << i;
    std::cout << std::endl;
    for (i = 0; i < size; i++)
    {
        std::cout << i << " ";
        // draw the squares in current row
        for (j = 0; j < size; j++)
        {
            if (board[i][j] == true)
                std::cout << " Q";
            else
                std::cout << " -";
        }
        std::cout << std::endl;
    }
}

#endif  // _N_QUEENS_H_
