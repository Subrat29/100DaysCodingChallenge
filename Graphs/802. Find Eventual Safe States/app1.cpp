#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pvis, vector<int> &ans)
{
    vis[node] = 1;
    pvis[node] = 1;
    for (auto it : adj[node])
    {
        if (pvis[it])
            return false;
        if (!vis[it])
        {
            if (!dfs(it, adj, vis, pvis, ans))
                return false;
        }
    }
    pvis[node] = 0;
    ans[node] = 1;
    return true;
}
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    vector<int> vis(graph.size());
    vector<int> pvis(graph.size());
    vector<int> ans(graph.size());
    for (int i = 0; i < graph.size(); i++)
    {
        if (!vis[i])
            dfs(i, graph, vis, pvis, ans);
    }
    vector<int> ret;
    for (int i = 0; i < graph.size(); i++)
    {
        if (ans[i])
            ret.push_back(i);
    }
    return ret;
}

int main()
{
    return 0;
}