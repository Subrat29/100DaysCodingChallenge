#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj, stack<int> &s)
{
    visited[node] = true;
    for (auto &&neighbour : adj[node])
    {
        if (!visited[neighbour])
            dfs(neighbour, visited, adj, s);
    }
    s.push(node);
}

void reverseDfs(int node, vector<vector<int>> &adj2, vector<bool> &visited)
{
    visited[node] = true;
    for (auto &&neighbour : adj2[node])
    {
        if (!visited[neighbour])
            reverseDfs(neighbour, adj2, visited);
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(v);
    for (auto &&edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }

    vector<bool> visited(v, false);
    stack<int> s;

    // step1: topo sort
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, s);
        }
    }

    // step2: transpose graph
    vector<vector<int>> adj2(v);
    for (auto &&edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj2[v].push_back(u);
    }

    for (int i = 0; i < v; ++i)
        visited[i] = false;

    // step3: count scc
    int cnt = 0;
    while (!s.empty())
    {
        if (!visited[s.top()])
        {
            cnt++;
            reverseDfs(s.top(), adj2, visited);
        }
        s.pop();
    }
    return cnt;
}

int main()
{
    return 0;
}