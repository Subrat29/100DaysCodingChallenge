#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

void dfs(int i, vector<vector<int>> &cost, vector<int> &vis, int curCost, int &res)
{
    int n = cost.size();

    // flag checks whether all the nodes are visited or not!
    int flag = 1;

    for (int j = 1; j < n; j++)
    {
        if (vis[j] == 0)
        {
            flag = 0;
            vis[j] = 1;
            dfs(j, cost, vis, curCost + cost[i][j], res);
            vis[j] = 0;
        }
    }
    if (flag == 1)
    {
        res = min(res, curCost + cost[i][0]);
    }

    return;
}

int total_cost(vector<vector<int>> cost)
{
    // Code here
    int n = cost.size();
    vector<int> vis(n, 0);
    int res = INT_MAX;

    dfs(0, cost, vis, 0, res);
    return res;
}

int main()
{
    return 0;
}