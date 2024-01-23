#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int node, int time, int parent, vector<bool> &visited, vector<int> &discoveryTime, vector<int> &lowestPossibleTime, vector<int> adj[], vector<bool> &ans)
{
    visited[node] = true;
    discoveryTime[node] = lowestPossibleTime[node] = time;

    int child = 0;
    for (auto &&neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, time + 1, node, visited, discoveryTime, lowestPossibleTime, adj, ans);

            // backtrack
            lowestPossibleTime[node] = min(lowestPossibleTime[node], lowestPossibleTime[neighbour]);

            // check articulation point
            if (parent != -1 && lowestPossibleTime[neighbour] >= discoveryTime[node])
                ans[node] = true;

            child++;
        }
        // back edge
        else if (neighbour != parent)
        {
            lowestPossibleTime[node] = min(lowestPossibleTime[node], discoveryTime[neighbour]);
        }
    }

    // Handle source node separately
    if (parent == -1 && child > 1)
        ans[node] = true;
}

vector<int> articulationPoints(int V, vector<int> adj[])
{
    // discovery time
    vector<int> discoveryTime(V, -1);

    // lowest possible time
    vector<int> lowestPossibleTime(V, -1);

    // visited
    vector<bool> visited(V, false);

    // answer
    vector<bool> ans(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            dfs(i, 0, -1, visited, discoveryTime, lowestPossibleTime, adj, ans);
    }

    vector<int> ap;
    for (int i = 0; i < V; i++)
    {
        if (ans[i] == true)
            ap.push_back(i);
    }
    if (!ap.empty())
        return ap;
    else
        return {-1};
}

int main()
{
    return 0;
}