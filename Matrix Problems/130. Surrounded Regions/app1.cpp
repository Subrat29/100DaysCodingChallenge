#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(vector<vector<char>> &board, int i, int j, int totRow, int totCol)
{
    if (i < 0 || j < 0 || i >= totRow || j >= totCol || board[i][j] != 'O')
    {
        return;
    }
    board[i][j] = '#';
    DFS(board, i - 1, j, totRow, totCol);
    DFS(board, i + 1, j, totRow, totCol);
    DFS(board, i, j - 1, totRow, totCol);
    DFS(board, i, j + 1, totRow, totCol);
}

void solve(vector<vector<char>> &board)
{
    int row = board.size();
    int col = board[0].size();

    if (row == 0)
    {
        return;
    }

    // first col and last col
    for (int i = 0; i < row; i++)
    {
        if (board[i][0] == 'O')
        {
            DFS(board, i, 0, row, col);
        }

        if (board[i][col - 1] == 'O')
        {
            DFS(board, i, col - 1, row, col);
        }
    }

    //  first row and last row
    for (int i = 0; i < col; i++)
    {
        if (board[0][i] == 'O')
        {
            DFS(board, 0, i, row, col);
        }
        if (board[row - 1][i] == 'O')
        {
            DFS(board, row - 1, i, row, col);
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == 'O')
            {               
                board[i][j] = 'X';
            }
            if (board[i][j] == '#')
            {
                board[i][j] = 'O';
            }

        }
    }
}

int main()
{

    return 0;
}