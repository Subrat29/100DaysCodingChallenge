#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool bfs(int node, vector<bool> &vis, vector<int> &parent, vector<vector<int>> &adj)
{
    queue<int> q;
    q.push(node);  
    vis[node] = true;
    parent[node] = -1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for (auto &&neighbour : adj[frontNode])
        {
            if (!vis[neighbour])
            {
                q.push(neighbour);
                vis[neighbour] = true;
                parent[neighbour] = frontNode;
            }
            else if (vis[neighbour] == true && parent[frontNode] != neighbour)
                return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // create adj list
    vector<vector<int>> adj(n + 1);
    for (auto &&edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // visited vector
    vector<bool> vis(n + 1);

    // parent vector
    vector<int> parent(n + 1);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (bfs(i, vis, parent, adj))
                return "Yes";
        }
    }
    return "No";
}

int main()
{
    return 0;
}