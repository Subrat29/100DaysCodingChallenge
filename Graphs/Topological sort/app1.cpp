#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int node, vector<bool> &visited, vector<int> adj[], vector<int> &ans)
{
    visited[node] = true;

    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
            dfs(neighbour, visited, adj, ans);
    }
    ans.push_back(node);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> ans;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            dfs(i, visited, adj, ans);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    return 0;
}