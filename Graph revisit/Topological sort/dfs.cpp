#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool> &vis, stack<int> &s, vector<vector<int>> &adj)
{
    vis[node] = true;

    for (auto &&neighbour : adj[node])
    {
        if (!vis[neighbour])
            dfs(neighbour, vis, s, adj);
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // create a adj list
    vector<vector<int>> adj(v);
    for (auto &&edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }

    // create a visited vector
    vector<bool> vis(v, false);

    // create a stack to store topo order
    stack<int> s;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            dfs(i, vis, s, adj);
    }

    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

int main()
{
    return 0;
}