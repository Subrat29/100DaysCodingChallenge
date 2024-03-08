#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void dfs1(int node, vector<bool> &vis, vector<vector<int>> &adj, stack<int> &s)
{
    vis[node] = true;
    for (auto &&neighbour : adj[node])
    {
        if (!vis[neighbour])
            dfs1(neighbour, vis, adj, s);
    }
    s.push(node);
}

void dfs2(int node, vector<bool> &vis, vector<vector<int>> &adj2)
{
    vis[node] = true;
    for (auto &&neighbour : adj2[node])
    {
        if (!vis[neighbour])
            dfs2(neighbour, vis, adj2);
    }
}

int kosaraju(int V, vector<vector<int>> &adj)
{
    // Step1: Find topo sort (need)
    vector<bool> vis(V, false);
    stack<int> s;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs1(i, vis, adj, s);
    }

    // Step2: Transpose the graph
    vector<vector<int>> adj2(V);
    for (int i = 0; i < V; i++)
    {
        for (auto &&j : adj[i])
            adj2[j].push_back(i);
    }

    // Step3: Implement dfs on transpose graph
    for (int i = 0; i < V; i++)
        vis[i] = false;

    int cnt = 0;
    while (!s.empty())
    {
        if (!vis[s.top()])
        {
            cnt++;
            dfs2(s.top(), vis, adj2);
        }
        s.pop();
    }
    return cnt;
}

int main()
{
    return 0;
}