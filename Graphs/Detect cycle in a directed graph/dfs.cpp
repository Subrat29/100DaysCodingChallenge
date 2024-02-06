#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Note: In this ques first i thought that we can solve it using undirected logic but when i dry run then i found
// there is another 2 requirement for this ques 1. visited vector 2. dfs visited
// dfsVisited track that this node is in stack or not if it present in stack that means cycle is present.

bool dfs(int node, vector<bool> &visited, vector<bool> &dfsVisited, vector<int> adj[])
{
    visited[node] = true;
    dfsVisited[node] = true;
    for (auto &&neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            if (dfs(neighbor, visited, dfsVisited, adj))
                return true;
        }
        else if (dfsVisited[neighbor])
        {
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    vector<bool> dfsVisited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, visited, dfsVisited, adj))
                return true;
        }
    }
    return false;
}

int main()
{
    return 0;
}