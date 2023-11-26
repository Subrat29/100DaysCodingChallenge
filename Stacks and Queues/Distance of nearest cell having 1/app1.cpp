#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<vector<int>> nearest(vector<vector<int>> grid)
{
    // Code here
    int N = grid.size();
    int M = grid[0].size();
    vector<vector<int>> ans(N, vector<int>(M, INT_MAX));

    // For each cell
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            // Traversing the whole matrix
            // to find the minimum distance.
            for (int k = 0; k < N; k++)
                for (int l = 0; l < M; l++)
                {
                    // If cell contain 1, check
                    // for minimum distance.
                    if (grid[k][l] == 1)
                        ans[i][j] = min(ans[i][j],
                                        abs(i - k) + abs(j - l));
                }
        }

    return ans;
}

int main()
{
    return 0;
}
