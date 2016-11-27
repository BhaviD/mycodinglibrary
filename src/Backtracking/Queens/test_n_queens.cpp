// the program solves the n-Queens problem. it prompts the user for
// the starting row for the queen in column 0 and calls the recursive
// backtracking function queens() to determine if there is a solution.
// if there is a solution, the position of the queens is passed to
// the chessboard object, board, and a call to its drawBoard() function
// shows the placement of the queens

#include <iostream>

#include "NQueens.h"

using namespace std;

int main ()
{
    int row, n = 0;

    cout << "Enter the size of the square chess board (length or breadth): ";
    cin >> n;

    vector<int> queenList(n);
    ChessBoard board(n);

    // enter a starting row for queen in column 0
    cout << "Enter row for queen in column 0: ";
    cin >> row;
    cout << endl;

    // see if there is a solution
    if (Queens(queenList, row))
    {
        board.SetQueens(queenList);
        // display the solution
        board.DrawBoard();
    }
    else
        cout << "No solution" << endl;

    return 0;
}

/*
Run 1:

Enter row for queen in column 0: 2

   0 1 2 3 4 5 6 7
0  - Q - - - - - -
1  - - - - - Q - -
2  Q - - - - - - -
3  - - - - - - Q -
4  - - - Q - - - -
5  - - - - - - - Q
6  - - Q - - - - -
7  - - - - Q - - -

Run 2:

Enter row for queen in column 0: 5

   0 1 2 3 4 5 6 7
0  - Q - - - - - -
1  - - - Q - - - -
2  - - - - - Q - -
3  - - - - - - - Q
4  - - Q - - - - -
5  Q - - - - - - -
6  - - - - - - Q -
7  - - - - Q - - -
*/
