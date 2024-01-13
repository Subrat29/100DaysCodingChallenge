#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj, vector<int> &component)
{
    visited[node] = true;
    component.push_back(node);

    for (auto &&neighbour : adj[node])
    {
        if (visited[neighbour] == false)
        {
            dfs(neighbour, visited, adj, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // create adj list
    vector<vector<int>> adj(V);
    for (auto &&edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // create visited vector
    vector<bool> visited(V, false);

    // create solution vector of vector
    vector<vector<int>> sol;

    for (int i = 0; i < V; i++)
    {
        // vector<int> component;
        // if (visited[i] == false)
        //     dfs(i, visited, adj, component);
        // sol.push_back(component);

        if (visited[i] == false)
        {
            vector<int> component;
            dfs(i, visited, adj, component);
            sol.push_back(component);
        }
    }
    return sol;
}

int main()
{
    return 0;
}