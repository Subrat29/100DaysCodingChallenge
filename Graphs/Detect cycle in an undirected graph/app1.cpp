#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs(vector<bool> &visited, vector<int> adj[], int node, int parent)
{
    visited[node] = true;

    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            if (dfs(visited, adj, neighbour, node))
                return true;
        }
        else if (neighbour != parent)
            return true;
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(visited, adj, i, -1))
                return true;
        }
    }
    return false;
}

int main()
{
    return 0;
}