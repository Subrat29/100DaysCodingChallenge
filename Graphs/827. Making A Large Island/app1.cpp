#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    int n;
    int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    unordered_map<int, int> map;

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        n = grid.size();
        int ret = 0, mark = 2;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                {
                    map[mark] = dfs(grid, i, j, mark);
                    mark += 1;
                }

        unordered_set<int> visited;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0)
                {
                    int area = 1;
                    visited.clear();
                    for (auto dir : dirs)
                    {
                        int x = i + dir[0], y = j + dir[1];
                        if (x < 0 || y < 0 || x >= n || y >= n || grid[x][y] == 0 || visited.count(grid[x][y]))
                            continue;
                        visited.insert(grid[x][y]);
                        area += map[grid[x][y]];
                    }
                    ret = max(ret, area);
                }
        return ret == 0 ? n * n : ret;
    }
    int dfs(vector<vector<int>> &grid, int i, int j, int mark)
    {
        if (i < 0 || j < 0 || i >= n || j >= n)
            return 0;
        if (grid[i][j] == 0 || grid[i][j] == mark)
            return 0;

        grid[i][j] = mark;
        int ret = 1;
        for (auto dir : dirs)
            ret += dfs(grid, i + dir[0], j + dir[1], mark);
        return ret;
    }
};

int main()
{
    return 0;
}