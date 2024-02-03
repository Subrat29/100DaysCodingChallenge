#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs(int node, vector<bool> &visited, int parent, vector<int> adj[])
{
    visited[node] = true;
    for (auto &&neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            if (dfs(neighbour, visited, node, adj))
                return true;
        }
        else if (parent != neighbour)
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
            if (dfs(i, visited, -1, adj))
                return true;
        }
    }
    return false;
}

int main()
{
    return 0;
}