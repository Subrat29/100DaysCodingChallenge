#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int node, vector<bool> &visited, vector<int> adj[], vector<int> &ans)
{
    if (visited[node])
        return;

    visited[node] = true;
    ans.push_back(node);

    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
            dfs(neighbour, visited, adj, ans);
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    vector<int> ans;
    for (int i = 0; i < V; i++)
        dfs(i, visited, adj, ans);
    return ans;
}

int main()
{
    return 0;
}