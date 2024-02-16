#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;

void dfs(int i, int j, vector<vector<int>> &grid, int n, queue<pair<int, int>> &q)
{
    if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] == 0 || grid[i][j] == 2)
        return;

    q.push({i, j});
    grid[i][j] = 2;

    dfs(i + 1, j, grid, n, q);
    dfs(i - 1, j, grid, n, q);
    dfs(i, j + 1, grid, n, q);
    dfs(i, j - 1, grid, n, q);
}

int bfs(vector<vector<int>> &grid, queue<pair<int, int>> &q, int n)
{
    vector<vector<int>> drc = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int minDist = INT_MAX;
    int d = 0;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz-- > 0)
        {
            auto a = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int x = drc[i][0] + a.first;
                int y = drc[i][1] + a.second;

                if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 1)
                    minDist = min(minDist, d);

                if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 0)
                {
                    grid[x][y] = 2;
                    q.push({x, y});
                }
            }
        }
        d++;
    }
    return minDist;
}

int shortestBridge(vector<vector<int>> &grid)
{
    int n = grid.size();
    bool flag = false;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1 && flag == false)
            {
                dfs(i, j, grid, n, q);
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }

    return bfs(grid, q, n);
}

int main()
{
    vector<vector<int>> grid = {{0, 1}, {1, 0}};
    cout << shortestBridge(grid);
    return 0;
}