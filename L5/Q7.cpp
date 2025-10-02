#include <iostream>
#include <vector>

using namespace std;

/*
Create a program that solves the N-Queens problem for any given N using backtracking. The
program should print all possible solutions for placing N queens on an N x N chessboard so
that no two queens threaten each other. This task requires you to use a recursive function to
place queens row by row , and a validation function to check if a queen can be placed in a
specific cell. If a placement leads to a conflict, the algorithm should backtrack to the previous
row and try a different column.
*/

bool isSafe(vector<int>& board, int row, int col, int N)
{
    for (int i = 0; i < row; i++)
    {
        int placedCol = board[i];
        if (placedCol == col || abs(placedCol - col) == abs(i - row))
        {
            return false;
        }
    }
    return true;
}

void printSolution(vector<int>& board, int N, int solutionCount)
{
    cout << "Solution " << solutionCount << ":\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

void solveNQueensUtil(int row, vector<int>& board, int N, int& solutionCount)
{
    if (row == N)
    {
        solutionCount++;
        printSolution(board, N, solutionCount);
        return;
    }

    for (int col = 0; col < N; col++)
    {
        if (isSafe(board, row, col, N))
        {
            board[row] = col;
            solveNQueensUtil(row + 1, board, N, solutionCount);
            board[row] = -1;
        }
    }
}

void solveNQueens(int N)
{
    vector<int> board(N, -1);
    int solutionCount = 0;

    solveNQueensUtil(0, board, N, solutionCount);

    if (solutionCount == 0)
    {
        cout << "No solutions exist for N = " << N << endl;
    }
    else
    {
        cout << "Total solutions for N = " << N << " : " << solutionCount << endl;
    }
}

int main()
{
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    solveNQueens(N);

    return 0;
}
