#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs(int i, int j, int idx, string word, vector<vector<char>> &board)
{
    if (idx == word.length()) // This must be on top
        return true;
    if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[idx] || idx > word.length())
        return false;

    board[i][j] = '*';
    bool res = dfs(i + 1, j, idx + 1, word, board) ||
               dfs(i - 1, j, idx + 1, word, board) ||
               dfs(i, j + 1, idx + 1, word, board) ||
               dfs(i, j - 1, idx + 1, word, board);
    board[i][j] = word[idx];
    return res;
}

bool exist(vector<vector<char>> &board, string word)
{
    int n = board.size();
    int m = board[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dfs(i, j, 0, word, board))
                return true;
        }
    }
    return false;
}

int main()
{
    return 0;
}