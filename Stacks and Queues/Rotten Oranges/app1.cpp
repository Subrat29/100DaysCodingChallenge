#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find minimum time required to rot all oranges.
bool issafe(int i, int j, int n, int m)
{
    if (i >= 0 && i < n && j >= 0 && j < m)
        return true;
    return false;
}

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;

    while (true)
    {
        bool changed = false;
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                    v.push_back({i, j});
            }
        }

        for (int k = 0; k < v.size(); k++)
        {
            int i = v[k].first;
            int j = v[k].second;

            if (issafe(i + 1, j, n, m) && grid[i + 1][j] == 1)
            {
                grid[i + 1][j] = 2;
                changed = true;
            }
            if (issafe(i, j + 1, n, m) && grid[i][j + 1] == 1)
            {
                grid[i][j + 1] = 2;
                changed = true;
            }
            if (issafe(i - 1, j, n, m) && grid[i - 1][j] == 1)
            {
                grid[i - 1][j] = 2;
                changed = true;
            }
            if (issafe(i, j - 1, n, m) && grid[i][j - 1] == 1)
            {
                grid[i][j - 1] = 2;
                changed = true;
            }
        }
        if (changed == false)
        {
            break;
        }
        ans++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
                return -1;
        }
    }

    return ans;
}

int main()
{
    return 0;
}
