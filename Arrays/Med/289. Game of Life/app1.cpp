#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// This is not inplace aproach but easy to understand + mujhe need bhi aa rhi h to u know...

void gameOfLife(vector<vector<int>> &board)
{
    int row = board.size();
    int col = board[0].size();
    
    // vector<vector<int>> tempBoard;
    vector<vector<int>> tempBoard(row, vector<int>(col, 0));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int liveNeighbors = neighbor(board, i - 1, j - 1) + neighbor(board, i - 1, j) + neighbor(board, i - 1, j + 1) + neighbor(board, i, j - 1) +
                                +neighbor(board, i, j + 1) + neighbor(board, i + 1, j - 1) + neighbor(board, i + 1, j) + neighbor(board, i + 1, j + 1);

            if (board[i][j] == 1)
            {
                tempBoard[i][j] = (liveNeighbors < 2 || liveNeighbors > 3) ? 0 : 1;
            }
            else
            {
                tempBoard[i][j] = (liveNeighbors == 3) ? 1 : 0;
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            board[i][j] = tempBoard[i][j];
        }
    }
}

int neighbor(vector<vector<int>> &board, int row, int col)
{
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] == 0)
    {
        return 0;
    }
    return 1;
}

int main()
{

    return 0;
}

// The line vector<vector<int>> tempBoard;
// declares a vector of vectors, but it doesn't specify the size or initialize the inner vectors.
// This can lead to issues, especially when trying to access elements within tempBoard.
// You should either provide the size when declaring tempBoard or initialize it with specific dimensions.