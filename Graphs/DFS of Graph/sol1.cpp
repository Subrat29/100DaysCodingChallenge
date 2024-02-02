#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// catch: its adj list is customize thats why ans ka format aese aara h
// Adj :
// 0-> 2 3 1
// 1-> 0
// 2-> 0 4
// 3-> 0
// 4-> 2

void dfs(int node, vector<bool> &visited, vector<int> &ans, vector<int> adj[])
{
    ans.push_back(node);
    visited[node] = true;
    for (auto &&neighbour : adj[node])
    {
        if (visited[neighbour] == false)
            dfs(neighbour, visited, ans, adj);
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    vector<int> ans;

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
            dfs(i, visited, ans, adj);
    }
    return ans;
}

int main()
{
    return 0;
}