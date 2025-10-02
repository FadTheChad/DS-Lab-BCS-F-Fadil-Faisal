#include <iostream>

using namespace std;

/*
Modify the provided "Rat in a Maze" code to handle a more complex version of the problem.
The rat should now be able to move in four directions (up, down, left, and right) instead of just
two. Your updated code should still use backtracking to find a valid path from the source (0,0) to
the destination (N-1, N-1) while avoiding dead ends.
*/

#define N 5

void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int maze[N][N], int x, int y, int sol[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && sol[x][y] == 0);
}

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
    if (x == N - 1 && y == N - 1)
    {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y, sol))
    {
        sol[x][y] = 1;

        if (solveMazeUtil(maze, x + 1, y, sol))
            return true;

        if (solveMazeUtil(maze, x, y + 1, sol))
            return true;

        if (solveMazeUtil(maze, x - 1, y, sol))
            return true;

        if (solveMazeUtil(maze, x, y - 1, sol))
            return true;

        sol[x][y] = 0;
        return false;
    }

    return false;
}

void solveMaze(int maze[N][N])
{
    int sol[N][N] = {0};

    if (!solveMazeUtil(maze, 0, 0, sol))
    {
        cout << "No solution exists\n";
        return;
    }

    cout << "Path found (4 directions):\n";
    printSolution(sol);
}

int main()
{
    int maze[N][N] =
    {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 1, 1}
    };

    solveMaze(maze);
    return 0;
}
