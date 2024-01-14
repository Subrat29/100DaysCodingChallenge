#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs(int node, int parent, vector<bool> &vis, vector<vector<int>> &adj)
{
    vis[node] = true;

    for (auto &&neighbour : adj[node])
    {
        if (!vis[neighbour])
        {
            // dfs(neighbour, node, vis, adj); We don't do this directly because ye function call h to return kha se kregi
            if (dfs(neighbour, node, vis, adj))
                return true;
        }
        else if (parent != neighbour)
        {
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // create adj list
    vector<vector<int>> adj(n + 1);
    for (auto &&edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // visited vector
    vector<bool> vis(n + 1);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, vis, adj))
                return "Yes";
        }
    }
    return "No";
}

int main()
{
    return 0;
}