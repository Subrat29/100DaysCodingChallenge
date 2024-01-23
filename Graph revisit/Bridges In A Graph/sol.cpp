#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int node, int parent, int time, vector<bool> &visited, vector<int> &discoveryTime, vector<int> &lowestPossibleTime, vector<vector<int>> &adj, vector<vector<int>> &ans)
{
    visited[node] = true;
    discoveryTime[node] = time;
    lowestPossibleTime[node] = time;

    for (auto &&neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, node, time + 1, visited, discoveryTime, lowestPossibleTime, adj, ans);

            // check bridge
            if (lowestPossibleTime[neighbour] > discoveryTime[node])
                ans.push_back({node, neighbour});
        }
        // back edge
        else if (neighbour != parent)
        {
            lowestPossibleTime[node] = min(lowestPossibleTime[node], discoveryTime[neighbour]);
        }
    }

    // backtrack
    lowestPossibleTime[parent] = min(lowestPossibleTime[parent], lowestPossibleTime[node]);
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    vector<vector<int>> adj(v);
    for (auto &&edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // discovery time
    vector<int> discoveryTime(v, -1);

    // lowest possible time
    vector<int> lowestPossibleTime(v, -1);

    // visited
    vector<bool> visited(v, false);

    // answer vector
    vector<vector<int>> ans;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            dfs(i, -1, 0, visited, discoveryTime, lowestPossibleTime, adj, ans);
    }
    return ans;
}

int main()
{
    return 0;
}