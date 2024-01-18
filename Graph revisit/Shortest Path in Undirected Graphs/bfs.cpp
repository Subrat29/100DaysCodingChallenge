#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// *NOTE*
// In summary, while BFS guarantees the shortest path in terms of the number of edges in an unweighted graph,
// it may not find the shortest path in a graph with different edge weights

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
    vector<vector<int>> adj(n + 1);
    for (auto &&edge : edges)
    {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // processing to find out the parent vector
    vector<bool> vis(n + 1, false);
    vector<int> parent(n + 1, -1);

    queue<int> q;
    q.push(s);
    vis[s] = true;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for (auto &&neighbour : adj[frontNode])
        {
            if (!vis[neighbour])
            {
                vis[neighbour] = true;
                parent[neighbour] = frontNode;
                q.push(neighbour);
            }
        }
    }

    // By parent vector we can backtrack from destination to source node & don't think about shortest path because
    // **Note** bfs automatically traverse acc to shortest path
    vector<int> ans;
    int dest = t;
    ans.push_back(dest);
    while (dest != s)
    {
        dest = parent[dest];
        ans.push_back(dest);
    }

    // But we get path dest -> source therefore reverse it to find source -> dest
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    return 0;
}