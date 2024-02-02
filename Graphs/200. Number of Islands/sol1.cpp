#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int i, int j, vector<vector<char>> &grid)
{
    if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size())
    {
        if (grid[i][j] == '1')
        {
            grid[i][j] = 0;

            dfs(i + 1, j, grid);
            dfs(i - 1, j, grid);
            dfs(i, j + 1, grid);
            dfs(i, j - 1, grid);
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int cnt = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == '1')
            {
                cnt++;
                grid[i][j] = '0';

                dfs(i + 1, j, grid);
                dfs(i - 1, j, grid);
                dfs(i, j + 1, grid);
                dfs(i, j - 1, grid);
            }
        }
    }
    return cnt;
}

int main()
{
    return 0;
}