#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

void bfs(int node, vector<bool> &visited, vector<vector<int>> &adj, vector<int> &ans)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);
        for (auto neighbour : adj[frontNode])
        {
            if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    // visited array
    vector<bool> visited(n, false);

    // ans vector
    vector<int> ans;

    // Yes, it is possible that during a Breadth-First Search (BFS) traversal of a graph, a vertex may not be included
    // in the final result vector or list. The reason for this can be that the vertex is not reachable from the
    // starting vertex or it might not be part of the connected component being explored.

    // Therefore, we not use loop 
    // for (int i = 0; i < n; i++)
    // {
    //     if (!visited[i])
    //         bfs(i, visited, adj, ans);
    // }

    bfs(0, visited, adj, ans);

    return ans;
}

int main()
{
    return 0;
}