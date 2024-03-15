#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int maxDistance(vector<vector<int>> &grid)
{

    queue<pair<int, int>> q;
    pair<int, int> curr;
    int maxDistance = 0, x, y;
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
                q.push({i, j});
        }
    }

    while (!q.empty())
    {
        curr = q.front();
        q.pop();

        for (int i = 0; i < dir.size(); i++)
        {
            x = curr.first + dir[i][0];
            y = curr.second + dir[i][1];

            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size())
            {
                if (grid[x][y] == 0)
                {
                    grid[x][y] = grid[curr.first][curr.second] + 1;
                    maxDistance = grid[x][y];
                    // cout<<x<<" "<<y<<endl;
                    q.push({x, y});
                }
            }
        }
    }

    return maxDistance - 1;
}

int main()
{
    return 0;
}