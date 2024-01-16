#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs(int node, vector<bool> &vis, vector<bool> &dfsVis, vector<vector<int>> &adj)
{
    vis[node] = true;
    dfsVis[node] = true;

    for (auto &&neighbour : adj[node])
    {
        if (!vis[neighbour])
        {
            if (dfs(neighbour, vis, dfsVis, adj))
                return true;
        }
        // vis[neig] == true && dfsVis[neig] == true then cycle is present
        else if (dfsVis[neighbour])
            return true;
    }
    
    // backtrack krte time dfs visited ko false kr do
    dfsVis[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    vector<vector<int>> adj(n + 1);
    for (auto &&edge : edges)
    {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
    }

    // create visited array
    vector<bool> vis(n + 1, false);

    // create dfs visited array
    vector<bool> dfsVis(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, vis, dfsVis, adj))
                return true;
        }
    }
    return false;
}

int main()
{
    return 0;
}