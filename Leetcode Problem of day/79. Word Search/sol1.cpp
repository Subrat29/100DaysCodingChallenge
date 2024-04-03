#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs(int i, int j, vector<vector<bool>> &vis, int idx, string word, vector<vector<char>> &board)
{
    if (idx == word.length())
        return true;
    if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[idx] || idx > word.length() || vis[i][j] == true)
        return false;

    vis[i][j] = true;
    bool res = dfs(i + 1, j, vis, idx + 1, word, board) ||
               dfs(i - 1, j, vis, idx + 1, word, board) ||
               dfs(i, j + 1, vis, idx + 1, word, board) ||
               dfs(i, j - 1, vis, idx + 1, word, board);
    vis[i][j] = false;
    return res;
}

bool exist(vector<vector<char>> &board, string word)
{
    int n = board.size();
    int m = board[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == word[0] && dfs(i, j, vis, 0, word, board))
                return true;
        }
    }
    return false;
}

int main()
{
    return 0;
}