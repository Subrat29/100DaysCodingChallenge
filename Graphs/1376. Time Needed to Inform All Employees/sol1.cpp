#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// NOTE: Assume that every employees has only 1 manager, bc trees has no loop
// therefore no need of visited array

int dfs(int node, vector<vector<int>> &adj, vector<int> &informTime)
{
    int ans = informTime[node];
    int maxi = 0;
    for (auto &&neighbour : adj[node])
        maxi = max(maxi, dfs(neighbour, adj, informTime));
    return ans + maxi;
}

int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
{
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        if (manager[i] != -1)
            adj[manager[i]].push_back(i);
    }
    return dfs(headID, adj, informTime);
}

int main()
{
    return 0;
}