#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// (parent == -1 && adj[node].size() > 1) 
// This approach is not working because draw a graph which has 0 node its parent -1 and adj[node].size() > 1 but
// still it is not a articulation points....yeah yeah draw


void dfs(int node, int time, int parent, vector<bool> &visited, vector<int> &discoveryTime,
         vector<int> &lowestPossibleTime, vector<int> adj[], vector<int> &ans)
{
    // Handle source node separately
    if (parent == -1 && adj[node].size() > 1)
        ans.push_back(node);

    visited[node] = true;
    discoveryTime[node] = lowestPossibleTime[node] = time;

    for (auto &&neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, time + 1, node, visited, discoveryTime, lowestPossibleTime, adj, ans);

            // check articulation point
            if (parent != -1 && lowestPossibleTime[neighbour] >= discoveryTime[node])
                ans.push_back(node);
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

vector<int> articulationPoints(int V, vector<int> adj[])
{
    // discovery time
    vector<int> discoveryTime(V, -1);

    // lowest possible time
    vector<int> lowestPossibleTime(V, -1);

    // visited
    vector<bool> visited(V, false);

    // answer
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            dfs(i, 0, -1, visited, discoveryTime, lowestPossibleTime, adj, ans);
    }
    return ans;
}

int main()
{
    return 0;
}