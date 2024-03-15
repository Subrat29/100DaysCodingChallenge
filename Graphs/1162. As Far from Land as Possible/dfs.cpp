#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Test Case which i not understand: [[1,0,0],[0,1,0],[1,1,0]]
// iska ans 4 aana chahiye but 2 aa rha h, why?
// ques me poocha kya h max dist from water to land  na or any other?

void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited, int n)
{
    if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 1 || visited[i][j] == true)
        return;

    visited[i][j] = true;
    grid[i][j] = 1;
}

int maxDistance(vector<vector<int>> &grid)
{
    int n = grid.size();
    for (int it = 0; it < 2 * n; it++) // 2*n, bc n+3 pr test cas3 36/38 phatting thats why random i choose this and its run:}
    {
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<vector<int>> grid2 = grid;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    visited[i][j] = true;
                    dfs(i + 1, j, grid, visited, n);
                    dfs(i, j + 1, grid, visited, n);
                    dfs(i - 1, j, grid, visited, n);
                    dfs(i, j - 1, grid, visited, n);
                }
            }
        }
        if (grid == grid2 && it == 0)
            return -1;

        if (grid == grid2)
            return it;
    }
    return -1;
}

int main()
{

    return 0;
}